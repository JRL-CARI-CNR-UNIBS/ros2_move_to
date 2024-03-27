#include "rclcpp/rclcpp.hpp"
#include <rclcpp/parameter_client.hpp>
#include "rclcpp_action/rclcpp_action.hpp"
#include "rclcpp_components/register_node_macro.hpp"

#include "std_msgs/msg/string.hpp"
#include "builtin_interfaces/msg/duration.hpp"
#include "moveit_msgs/msg/display_trajectory.hpp"
#include "trajectory_msgs/msg/joint_trajectory.hpp"
#include "ik_solver_msgs/srv/get_ik.hpp"
#include "ik_solver_msgs/msg/ik_solution.hpp"
#include "ik_solver_msgs/msg/configuration.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"

#include "cnr_param/cnr_param.h"
#include "trajectory_loader/action/move_to_action.hpp"

#include <moveit/move_group_interface/move_group_interface.h>
#include "moveit/trajectory_processing/iterative_spline_parameterization.h"
#include "moveit/trajectory_processing/time_optimal_trajectory_generation.h"

using namespace std::chrono_literals;

class MoveToServer : public rclcpp::Node
{
public:
  explicit MoveToServer(const rclcpp::NodeOptions & node_options = rclcpp::NodeOptions().automatically_declare_parameters_from_overrides(true))
    : Node("move_to_server", node_options)
  {
    this->action_server_ = rclcpp_action::create_server<trajectory_loader::action::MoveToAction>(
          this,"/move_to",
          std::bind(&MoveToServer::handle_goal, this, std::placeholders::_1, std::placeholders::_2),
          std::bind(&MoveToServer::handle_cancel, this, std::placeholders::_1),
          std::bind(&MoveToServer::handle_accepted, this, std::placeholders::_1));

    // Subscribe to the available /get_ik services
    std::vector<std::string> ik_services;
    rclcpp::Rate rate(100);
    while(ik_services.empty())
    {
      RCLCPP_INFO(this->get_logger(),"Waiting for /get_ik services");
      this->getAvailableIkService(ik_services);
      rate.sleep();
    }

    RCLCPP_WARN_STREAM(this->get_logger(),"Available /get_ik services:");
    std::pair<std::string,rclcpp::Client<ik_solver_msgs::srv::GetIk>::SharedPtr> p;
    for(const std::string& service: ik_services)
    {
      p.first = service;
      p.second = this->create_client<ik_solver_msgs::srv::GetIk>(p.first);

      ik_client_map_.insert(p);

      RCLCPP_WARN_STREAM(this->get_logger(),"  -"<<service<<"\n");
    }

    this->display_trj_pub_ = this->create_publisher<moveit_msgs::msg::DisplayTrajectory>("/simulated_trajectory",1);

    // Get robot_description
    rclcpp::SyncParametersClient::SharedPtr parameters_client = std::make_shared<rclcpp::SyncParametersClient>(this, std::string("/move_group"));
    while (!parameters_client->wait_for_service(1s))
    {
      if (!rclcpp::ok())
      {
        RCLCPP_ERROR(this->get_logger(), "Interrupted while waiting for the service. Exiting.");
        rclcpp::shutdown();
      }
      RCLCPP_INFO(this->get_logger(), "service not available, waiting again...");
    }
    if(not parameters_client->has_parameter("robot_description"))
      RCLCPP_ERROR(this->get_logger(), "Cannot find robot_description parameter");
    if(not parameters_client->has_parameter("robot_description_semantic"))
      RCLCPP_ERROR(this->get_logger(), "Cannot find robot_description_semantic parameter");

    std::string param_name = "robot_description";
    std::string robot_description = parameters_client->get_parameter<std::string>(param_name);

    rclcpp::Parameter robot_description_param(param_name,robot_description);
    this->declare_parameter(param_name, rclcpp::PARAMETER_STRING);
    this->set_parameter(robot_description_param);

    if(not this->has_parameter(param_name))
      throw std::runtime_error("no robot description");
    else
      RCLCPP_WARN(this->get_logger(),"robot description loaded");

    param_name = "robot_description_semantic";
    std::string robot_description_semantic = parameters_client->get_parameter<std::string>(param_name);

    rclcpp::Parameter robot_description_semantic_param(param_name,robot_description_semantic);
    this->declare_parameter(param_name, rclcpp::PARAMETER_STRING);
    this->set_parameter(robot_description_semantic_param);

    if(not this->has_parameter(param_name))
      throw std::runtime_error("no robot description semantic");
    else
      RCLCPP_WARN(this->get_logger(),"robot description semantic loaded");
  }

private:
  bool ik_response_received_;
  ik_solver_msgs::srv::GetIk::Response::SharedPtr ik_response_;
  rclcpp::Publisher<moveit_msgs::msg::DisplayTrajectory>::SharedPtr display_trj_pub_;
  rclcpp_action::Server<trajectory_loader::action::MoveToAction>::SharedPtr action_server_;
  std::map<std::string,rclcpp::Client<ik_solver_msgs::srv::GetIk>::SharedPtr> ik_client_map_;
  std::shared_ptr<rclcpp_action::ServerGoalHandle<trajectory_loader::action::MoveToAction>> goal_handle_;

  struct Ik{
    std::vector<std::string> joint_names;
    std::vector<ik_solver_msgs::msg::Configuration> configurations;
  };

  void ik_response_callback(rclcpp::Client<ik_solver_msgs::srv::GetIk>::SharedFuture future)
  {
    this->ik_response_received_ = true;
    this->ik_response_ = future.get();
  }

  void getAvailableIkService(std::vector<std::string>& ik_service)
  {
    std::string target_type = "ik_solver_msgs/srv/GetIk";

    ik_service.clear();
    std::string service_name, service_type;
    for(const std::pair<std::string, std::vector<std::string>> service: this->get_service_names_and_types())
    {
      for(const std::string& type: service.second)
      {
        if(type == target_type)
        {
          ik_service.push_back(service.first);

        }
      }
    }
  }

  bool getIk(const std::string& ik_service, const geometry_msgs::msg::PoseStamped& pose, Ik& ik)
  {
    auto req = std::make_shared<ik_solver_msgs::srv::GetIk::Request>();
    ik_solver_msgs::msg::IkTarget target;
    target.pose = pose;
    req->target = target;

    this->ik_response_ = nullptr;
    this->ik_response_received_ = false;
    auto result = this->ik_client_map_.at(ik_service)->async_send_request(req, std::bind(&MoveToServer::ik_response_callback,
                                                                                         this, std::placeholders::_1));
    rclcpp::Rate rate(100);
    while(not this->ik_response_received_)
    {
      RCLCPP_INFO(this->get_logger(), "Waiting for /get_ik server response");
      rate.sleep();
    }

    if(this->ik_response_ != nullptr)
    {
      ik.joint_names = this->ik_response_.get()->joint_names;
      ik.configurations = this->ik_response_.get()->solution.configurations;
    }
    else
    {
      RCLCPP_ERROR(this->get_logger(), "Ik service failed");
      return false;
    }
    return true;
  }

  bool chooseIk(const Ik& ik, const std::vector<double>& current_configuration, std::vector<double>& best_ik)
  {
    Eigen::VectorXd best_conf;
    Eigen::VectorXd current_conf = Eigen::VectorXd::Map(
          current_configuration.data(), static_cast<Eigen::Index>(current_configuration.size()));

    double distance;
    double min_distance = std::numeric_limits<double>::infinity();

    for(size_t i=0;i<ik.configurations.size();i++)
    {
      Eigen::VectorXd conf = Eigen::VectorXd::Map(
            ik.configurations[i].configuration.data(),
            static_cast<Eigen::Index>(ik.configurations[i].configuration.size()));

      distance = (conf-current_conf).norm();
      if(distance<min_distance)
      {
        best_conf = conf;
        min_distance = distance;
      }
    }

    best_ik.resize(best_conf.size());
    Eigen::Map<Eigen::VectorXd>(best_ik.data(), best_ik.size()) = best_conf;

    return true;
  }

  void move_to()
  {
    auto result = std::make_shared<trajectory_loader::action::MoveToAction::Result>();
    auto feedback = std::make_shared<trajectory_loader::action::MoveToAction::Feedback>();

    result->ok = false;
    const auto goal = goal_handle_->get_goal();

    std::string summary = "Request:\n";
    summary = summary+" - group_name: "+goal->group_name+"\n";
    summary = summary+" - ik_service_name: "+goal->ik_service_name+"\n";
    summary = summary+" - simulation: "+(goal->simulation? "true": "false")+"\n";
    summary = summary+" - pose:\n"+geometry_msgs::msg::to_yaml(goal->pose)+"\n";

    RCLCPP_WARN_STREAM(this->get_logger(),summary);

    if (this->ik_client_map_.find(goal->ik_service_name) == this->ik_client_map_.end())
    {
      RCLCPP_ERROR(this->get_logger(),"Required ik service not available");

      std::vector<std::string> s;
      for(const auto& p:this->ik_client_map_)
        s.push_back(" - "+p.first+"\n");

      RCLCPP_ERROR_STREAM(this->get_logger(),"List of /get_ik services detected:\n");

      result->error = "Required ik service not available";
      goal_handle_->abort(result);
      return;
    }

    bool success;
    moveit::planning_interface::MoveGroupInterface::Plan plan;
    moveit::planning_interface::MoveGroupInterface move_group(this->shared_from_this(),goal->group_name);

    move_group.startStateMonitor();

    if(goal_handle_->is_canceling())
    {
      RCLCPP_INFO(this->get_logger(),"Goal canceled");
      result->error="canceled";
      goal_handle_->canceled(result);
      return;
    }

    Ik ik;
    if(not this->getIk(goal->ik_service_name,goal->pose,ik))
    {
      RCLCPP_ERROR(this->get_logger(),"Ik not available");
      result->error = "Ik not available";
      goal_handle_->abort(result);
      return;
    }

    if(ik.configurations.size()!=0)
      RCLCPP_INFO_STREAM(this->get_logger(),ik.configurations.size()<<" ik available");
    else
    {
      RCLCPP_ERROR(this->get_logger(),"No ik available");
      result->error = "No ik available";
      goal_handle_->abort(result);
      return;
    }

    if(goal_handle_->is_canceling())
    {
      RCLCPP_INFO(this->get_logger(),"Goal canceled");
      result->error="canceled";
      goal_handle_->canceled(result);
      return;
    }

    RCLCPP_INFO_STREAM(this->get_logger(),"Waiting for robot current state");
    moveit::core::RobotState robot_current_state = *move_group.getCurrentState();
    std::vector<double> current_configuration;
    for(const std::string& j:ik.joint_names)
    {
      double d = *robot_current_state.getJointPositions(j);
      current_configuration.push_back(d);
    }
    RCLCPP_INFO_STREAM(this->get_logger(),"Current configuration read");

    std::vector<double> best_ik;
    this->chooseIk(ik,current_configuration,best_ik);

    std::string best_ik_str = "";
    for(const double& d : best_ik)
      best_ik_str = best_ik_str + std::to_string(d)+" ";

    RCLCPP_INFO_STREAM(this->get_logger(),"Choosen ik: "<<best_ik_str);

    std::map<std::string, double> goal_map;
    for(size_t j=0;j<ik.joint_names.size();j++)
    {
      std::pair<std::string, double> p;
      p.first = ik.joint_names[j];
      p.second = best_ik[j];
      goal_map.insert(p);
    }
    move_group.setStartStateToCurrentState();
    move_group.setJointValueTarget(goal_map);

    robot_trajectory::RobotTrajectory trajectory(move_group.getRobotModel(), goal->group_name);
    success = (move_group.plan(plan) == moveit::core::MoveItErrorCode::SUCCESS);
    if(not success)
    {
      RCLCPP_ERROR(this->get_logger(),"Planning to location failed!");
      result->error = "planning failed!";
      goal_handle_->abort(result);
      return;
    }

    moveit_msgs::msg::RobotTrajectory trj;
    trajectory.setRobotTrajectoryMsg(robot_current_state, plan.trajectory_.joint_trajectory);
    trajectory_processing::TimeOptimalTrajectoryGeneration trj_processing;
    trj_processing.computeTimeStamps(trajectory);
    trajectory.getRobotTrajectoryMsg(trj);

    RCLCPP_INFO_STREAM(this->get_logger(),"Trajectory "<<trajectory);

    if(goal_handle_->is_canceling())
    {
      RCLCPP_INFO(this->get_logger(),"Goal canceled");
      result->error="canceled";
      goal_handle_->canceled(result);
      return;
    }

    if(not goal->simulation)
    {
      moveit::core::MoveItErrorCode moveit_error_code = move_group.execute(trj);
      if(moveit_error_code != moveit::core::MoveItErrorCode::SUCCESS)
      {
        RCLCPP_ERROR_STREAM(this->get_logger(), "Move group move failed with error code "
                            <<moveit::core::error_code_to_string(moveit_error_code));
        result->error = "Move group move failed with error code "+moveit::core::error_code_to_string(moveit_error_code);
        goal_handle_->abort(result);
        return;
      }

      if(goal_handle_->is_canceling())
      {
        RCLCPP_INFO(this->get_logger(),"Goal canceled");
        result->error="canceled";
        goal_handle_->canceled(result);
        return;
      }
    }
    else
    {
      moveit_msgs::msg::DisplayTrajectory display_trj_msg;
      display_trj_msg.trajectory.push_back(trj);
      display_trj_pub_->publish(display_trj_msg);

      rclcpp::sleep_for(std::chrono::nanoseconds(
                          rclcpp::Duration(trj.joint_trajectory.points.back().time_from_start).nanoseconds()));
    }

    result->ok=true;
    goal_handle_->succeed(result);
    return;
  }

  rclcpp_action::GoalResponse handle_goal(
      const rclcpp_action::GoalUUID & uuid,
      std::shared_ptr<const trajectory_loader::action::MoveToAction::Goal> goal)
  {
    RCLCPP_INFO_STREAM(this->get_logger(), "Received goal request for group "<< goal->group_name);

    if(this->goal_handle_ != nullptr)
    {
      if(this->goal_handle_->is_active()    ||
         this->goal_handle_->is_canceling() ||
         this->goal_handle_->is_executing())
      {
        RCLCPP_INFO_STREAM(this->get_logger(), "Goal rejected! Current goal not in a terminal state");
        return rclcpp_action::GoalResponse::REJECT;
      }
    }

    (void)uuid;

    return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
  }

  rclcpp_action::CancelResponse handle_cancel(
      const std::shared_ptr<rclcpp_action::ServerGoalHandle
      <trajectory_loader::action::MoveToAction>> goal_handle)
  {
    RCLCPP_INFO(this->get_logger(), "Received request to cancel goal");

    (void)goal_handle;
    return rclcpp_action::CancelResponse::ACCEPT;
  }

  void handle_accepted(const std::shared_ptr<rclcpp_action::ServerGoalHandle
                       <trajectory_loader::action::MoveToAction>> goal_handle)
  {
    goal_handle_ = goal_handle;
    //    goal_handle_->execute();
    std::thread(std::bind(&MoveToServer::move_to, this)).detach();
  }
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);

  rclcpp::NodeOptions node_options;
  node_options.automatically_declare_parameters_from_overrides(true);
  auto node = std::make_shared<MoveToServer>(node_options);

  rclcpp::executors::MultiThreadedExecutor executor;
  executor.add_node(node);
  executor.spin();

  rclcpp::shutdown();

  return 0;
}

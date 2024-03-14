#include "rclcpp/rclcpp.hpp"
#include <rclcpp/parameter_client.hpp>
#include "rclcpp_action/rclcpp_action.hpp"
#include "rclcpp_components/register_node_macro.hpp"

#include "std_msgs/msg/string.hpp"
#include "builtin_interfaces/msg/duration.hpp"
#include "moveit_msgs/msg/display_trajectory.hpp"
#include "trajectory_msgs/msg/joint_trajectory.hpp"

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
    this->server_ptr_ = rclcpp_action::create_server<trajectory_loader::action::MoveToAction>(
          this,"/move_to",
          std::bind(&MoveToServer::handle_goal, this, std::placeholders::_1, std::placeholders::_2),
          std::bind(&MoveToServer::handle_cancel, this, std::placeholders::_1),
          std::bind(&MoveToServer::handle_accepted, this, std::placeholders::_1));

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
  rclcpp::Publisher<moveit_msgs::msg::DisplayTrajectory>::SharedPtr display_trj_pub_;
  rclcpp_action::Server<trajectory_loader::action::MoveToAction>::SharedPtr server_ptr_;
  std::shared_ptr<rclcpp_action::ServerGoalHandle<trajectory_loader::action::MoveToAction>> goal_handle_;

  struct Ik{
    std::vector<double> configuration;
    std::vector<std::string> joint_names;
  };

  Ik getIk(const std::string& location_name)
  {
    (void)location_name;
    Ik ik;
    return ik;
  }

  void load_trajectory()
  {
    auto result = std::make_shared<trajectory_loader::action::MoveToAction::Result>();
    auto feedback = std::make_shared<trajectory_loader::action::MoveToAction::Feedback>();

    result->ok = false;
    const auto goal = goal_handle_->get_goal();

    const bool simulate = goal->simulation;
    const std::string group_name = goal->group_name;
    const std::string location_name = goal->location_name;

    bool success;
    moveit::planning_interface::MoveGroupInterface::Plan plan;
    moveit::planning_interface::MoveGroupInterface move_group(this->shared_from_this(),group_name);

    move_group.startStateMonitor();
    moveit::core::RobotState robot_current_state = *move_group.getCurrentState();

    if(goal_handle_->is_canceling())
    {
      RCLCPP_INFO(this->get_logger(),"Goal canceled");
      result->error="canceled";
      goal_handle_->canceled(result);
      return;
    }

    Ik ik = this->getIk(location_name);

    std::map<std::string, double> goal_map;
    for(size_t j=0;j<ik.joint_names.size();j++)
    {
      std::pair<std::string, double> p;
      p.first = ik.joint_names[j];
      p.second = ik.configuration[j];
      goal_map.insert(p);
    }
    move_group.setJointValueTarget(goal_map);

    robot_trajectory::RobotTrajectory trajectory(move_group.getRobotModel(), group_name);
    success = (move_group.plan(plan) == moveit::core::MoveItErrorCode::SUCCESS);
    if(not success)
    {
      RCLCPP_ERROR(this->get_logger(),"Planning to location failed!");
      result->error = "planning failed!";
      return;
      goal_handle_->abort(result);
    }

    moveit_msgs::msg::RobotTrajectory trj;
    trajectory.setRobotTrajectoryMsg(robot_current_state, plan.trajectory_.joint_trajectory);
    trajectory_processing::TimeOptimalTrajectoryGeneration trj_processing;
    trj_processing.computeTimeStamps(trajectory);
    trajectory.getRobotTrajectoryMsg(trj);

    RCLCPP_INFO_STREAM(this->get_logger(),"Trajectory to location "<<location_name<<"\n"<<trajectory);

    if(goal_handle_->is_canceling())
    {
      RCLCPP_INFO(this->get_logger(),"Goal canceled");
      result->error="canceled";
      goal_handle_->canceled(result);
      return;
    }

    if(not simulate)
    {
      RCLCPP_INFO_STREAM(this->get_logger(),"Move to location "<<location_name);

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

      this->get_clock()->sleep_for(
            std::chrono_literals::operator""s(
              rclcpp::Duration(trj.joint_trajectory.points.back().time_from_start).seconds()));
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
    goal_handle_->execute();
    std::thread(std::bind(&MoveToServer::load_trajectory, this)).detach();
  }
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);

  rclcpp::NodeOptions node_options;
  node_options.automatically_declare_parameters_from_overrides(true);
  auto node = std::make_shared<MoveToServer>(node_options);

  rclcpp::spin(node);
  rclcpp::shutdown();

  return 0;
}

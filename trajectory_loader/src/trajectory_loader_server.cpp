#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "rclcpp_components/register_node_macro.hpp"
#include "control_msgs/action/follow_joint_trajectory.hpp"
#include "trajectory_msgs/msg/joint_trajectory.hpp"
#include "std_srvs/srv/trigger.hpp"
#include "moveit_msgs/action/execute_trajectory.hpp"
#include "trajectory_loader/action/trajectory_loader_action.hpp"
#include "moveit/move_group_interface/move_group_interface.h"
#include "moveit/trajectory_processing/iterative_spline_parameterization.h"
#include "moveit/trajectory_processing/time_optimal_trajectory_generation.h"
#include "cnr_param/cnr_param.h"
#include "builtin_interfaces/msg/duration.hpp"
#include "std_srvs/srv/empty.hpp"
#include "std_msgs/msg/string.hpp"
#include "moveit_msgs/msg/display_trajectory.hpp"
#include <rclcpp/parameter_client.hpp>

#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <moveit/planning_scene/planning_scene.h>
#include <moveit/planning_scene_monitor/planning_scene_monitor.h>
#include <moveit/robot_model_loader/robot_model_loader.h>

using namespace std::chrono_literals;

class TrajectoryLoaderServer : public rclcpp::Node
{
public:
  explicit TrajectoryLoaderServer(const rclcpp::NodeOptions & node_options = rclcpp::NodeOptions().automatically_declare_parameters_from_overrides(true))
    : Node("trajectory_loader_server", node_options)
  {
    this->server_ptr_ = rclcpp_action::create_server<trajectory_loader::action::TrajectoryLoaderAction>(
          this,"/trajectory_loader",
          std::bind(&TrajectoryLoaderServer::handle_goal, this, std::placeholders::_1, std::placeholders::_2),
          std::bind(&TrajectoryLoaderServer::handle_cancel, this, std::placeholders::_1),
          std::bind(&TrajectoryLoaderServer::handle_accepted, this, std::placeholders::_1));

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
  trajectory_msgs::msg::JointTrajectory trajectory_;
  rclcpp::Publisher<moveit_msgs::msg::DisplayTrajectory>::SharedPtr display_trj_pub_;
  rclcpp_action::Client<moveit_msgs::action::ExecuteTrajectory>::SharedPtr client_ptr_;
  rclcpp_action::Server<trajectory_loader::action::TrajectoryLoaderAction>::SharedPtr server_ptr_;
  std::shared_ptr<rclcpp_action::ServerGoalHandle<trajectory_loader::action::TrajectoryLoaderAction>> goal_handle_;

  void load_trajectory()
  {
    this->client_ptr_ = rclcpp_action::create_client<moveit_msgs::action::ExecuteTrajectory>(this,"/execute_trajectory");

    auto result = std::make_shared<trajectory_loader::action::TrajectoryLoaderAction::Result>();
    auto feedback = std::make_shared<trajectory_loader::action::TrajectoryLoaderAction::Feedback>();

    result->ok = false;
    const auto goal = goal_handle_->get_goal();

    const bool rescale = goal->rescale;
    const bool simulate = goal->simulation;
    const std::string group_name = goal->group_name;
    const unsigned int repetitions = goal->repetitions;
    const std::vector<std::string> list_of_trjs = goal->trj_names;

    if(not simulate)
    {
      if (not client_ptr_->wait_for_action_server(std::chrono::duration<double>(10.0)))
      {
        RCLCPP_ERROR(this->get_logger(), "No /execute_trajectory action server found!");
        result->error = "No /execute_trajectory action server found!";
        goal_handle_->abort(result);
        return;
      }
    }

    bool scale;
    bool success;
    moveit::planning_interface::MoveGroupInterface::Plan plan;
    moveit::planning_interface::MoveGroupInterface move_group(this->shared_from_this(),group_name);

    move_group.startStateMonitor();
    moveit::core::RobotState robot_current_state = *move_group.getCurrentState();

    for(unsigned irep = 0; irep<repetitions; irep++)
    {
      if(goal_handle_->is_canceling())
        return;

      for(const std::string& trj_name : list_of_trjs)
      {
        if(goal_handle_->is_canceling())
          return;

        scale = rescale;
        robot_current_state = *move_group.getCurrentState();

        feedback->current_repetition = irep;
        feedback->trj_in_execution = trj_name;

        goal_handle_->publish_feedback(feedback);

        moveit_msgs::msg::RobotTrajectory trj;
        moveit_msgs::msg::RobotTrajectory approach_trj;
        trajectory_msgs::msg::JointTrajectory trj_from_param;

        std::string what;
        if(not getTrajectoryFromParam(trj_name, trj_from_param, what))
        {
          RCLCPP_ERROR(this->get_logger(),"%s not found", trj_name.c_str());
          RCLCPP_ERROR_STREAM(this->get_logger(), what);

          result->error = trj_name+" not found";
          goal_handle_->abort(result);
          return;
        }
        else
        {
          if(trj_from_param.points.back().time_from_start == rclcpp::Duration::from_seconds(0.0))
            scale = true;
        }

        if(goal_handle_->is_canceling())
          return;

        std::vector<double> initial_trj_position = trj_from_param.points.begin()->positions;

        bool is_single_point = false;
        if(trj_from_param.points.size() < 2)
        {
          is_single_point = true;
          trj.joint_trajectory = trj_from_param;
          RCLCPP_WARN_STREAM(this->get_logger(),"Single point trajectory!");
        }
        else
        {
          if(scale)
          {
            //trj_state.setJointGroupPositions(group_name, initial_position);
            //robot_current_state.setJointGroupActivePositions(group_name, initial_trj_position);

            robot_trajectory::RobotTrajectory trajectory(move_group.getRobotModel(), group_name);
            trajectory.setRobotTrajectoryMsg(robot_current_state, trj_from_param);

            trajectory_processing::TimeOptimalTrajectoryGeneration trj_processing;
            trj_processing.computeTimeStamps(trajectory);
            trajectory.getRobotTrajectoryMsg(trj);

            RCLCPP_WARN(this->get_logger(),"Trajectory is scaled");
          }
          else
            trj.joint_trajectory=trj_from_param;
        }

        if(goal_handle_->is_canceling())
          return;

        //Go to the first configuration of the trajectory
        //        moveit::core::RobotStatePtr current_state = move_group.getCurrentState(10);
        //        const moveit::core::JointModelGroup* joint_model_group =
        //            move_group.getCurrentState()->getJointModelGroup(group_name);
        //        std::vector<double> joint_group_positions;
        //        current_state->copyJointGroupPositions(joint_model_group, joint_group_positions);

        //        move_group.setStartState(*move_group.getCurrentState());

        std::map<std::string, double> target_configuration;
        for(size_t j=0;j<trj_from_param.joint_names.size();j++)
        {
          std::pair<std::string, double> p;
          p.first = trj_from_param.joint_names[j];
          p.second = initial_trj_position[j];
          target_configuration.insert(p);
        }
        move_group.setJointValueTarget(target_configuration);

        std::vector<double> current_position;
        move_group.startStateMonitor();
        auto current_state = *move_group.getCurrentState();
        for(const std::string& n:trj_from_param.joint_names)
        {
          double d = *current_state.getJointPositions(n);
          current_position.push_back(d);
        }

        for(const double& d: current_position)
          RCLCPP_WARN_STREAM(this->get_logger(),"current pos j "<<d);

        for(const double& d: initial_trj_position)
          RCLCPP_WARN_STREAM(this->get_logger(),"initial pos j "<<d);

        robot_trajectory::RobotTrajectory trajectory(move_group.getRobotModel(), group_name);
        success = (move_group.plan(plan) == moveit::core::MoveItErrorCode::SUCCESS);
        if(not success)
        {
          RCLCPP_ERROR(this->get_logger(),"Planning to initial trj position failed!");
          result->error = "planning failed!";
          return;
          goal_handle_->abort(result);
        }

        trajectory.setRobotTrajectoryMsg(robot_current_state, plan.trajectory_.joint_trajectory);
        trajectory_processing::TimeOptimalTrajectoryGeneration trj_processing;
        trj_processing.computeTimeStamps(trajectory);
        trajectory.getRobotTrajectoryMsg(approach_trj);

        RCLCPP_ERROR_STREAM(this->get_logger(),"approach trj\n"<<trajectory);

        if(goal_handle_->is_canceling())
          return;

        moveit_msgs::action::ExecuteTrajectory::Goal goal;
        if(not simulate)
        {
          // Execute approach trajectory
          RCLCPP_INFO(this->get_logger(),"Move %s to initial position", group_name.c_str());

          moveit::core::MoveItErrorCode moveit_error_code = move_group.execute(approach_trj);
          if(moveit_error_code != moveit::core::MoveItErrorCode::SUCCESS)
          {
            RCLCPP_ERROR_STREAM(this->get_logger(), "Move group move failed with error code "
                                <<moveit::core::error_code_to_string(moveit_error_code));
            result->error = "Move group move failed with error code "+moveit::core::error_code_to_string(moveit_error_code);
            goal_handle_->abort(result);
            return;
          }
          //          goal.trajectory = approach_trj;

          //          auto future_goal_handle=this->client_ptr_->async_send_goal(goal);
          //          if(future_goal_handle.get() == nullptr)
          //          {
          //            RCLCPP_ERROR(this->get_logger(), "/execute_trajectory action rejected the goal");
          //            result->error = "/execute_trajectory action rejected the goal";
          //            goal_handle_->abort(result);
          //            return;
          //          }

          //          auto future_result_handle = this->client_ptr_->async_get_result(future_goal_handle.get());
          //          if(future_result_handle.get().code != rclcpp_action::ResultCode::SUCCEEDED)
          //          {
          //            RCLCPP_ERROR(this->get_logger(), "/execute_trajectory failed");
          //            result->error = "/execute_trajectory failed";
          //            goal_handle_->abort(result);
          //            return;
          //          }

          RCLCPP_WARN(this->get_logger(),"AFTER APPROACH");

          if(goal_handle_->is_canceling())
            return;

          if(not is_single_point)
          {
            // Execute the trajectory
            RCLCPP_INFO(this->get_logger(), "Execute trajectory %s", trj_name.c_str());

            moveit::core::MoveItErrorCode moveit_error_code = move_group.execute(trj);
            if(moveit_error_code != moveit::core::MoveItErrorCode::SUCCESS)
            {
              RCLCPP_ERROR_STREAM(this->get_logger(), "Move group move failed with error code "
                                  <<moveit::core::error_code_to_string(moveit_error_code));
              result->error = "Move group move failed with error code "+moveit::core::error_code_to_string(moveit_error_code);
              goal_handle_->abort(result);
              return;
            }

//            goal.trajectory = trj;

//            auto future_goal_handle=this->client_ptr_->async_send_goal(goal);
//            if(future_goal_handle.get() == nullptr)
//            {
//              RCLCPP_ERROR(this->get_logger(), "/execute_trajectory action rejected the goal");
//              result->error = "/execute_trajectory action rejected the goal";
//              goal_handle_->abort(result);
//              return;
//            }

//            auto future_result_handle = this->client_ptr_->async_get_result(future_goal_handle.get());
//            if(future_result_handle.get().code != rclcpp_action::ResultCode::SUCCEEDED)
//            {
//              RCLCPP_ERROR(this->get_logger(), "/execute_trajectory failed");
//              result->error = "/execute_trajectory failed";
//              goal_handle_->abort(result);
//              return;
//            }

            if(goal_handle_->is_canceling())
              return;
          }
        }
        else
        {
          moveit_msgs::msg::DisplayTrajectory display_trj_msg;
          display_trj_msg.trajectory.push_back(approach_trj);
          display_trj_pub_->publish(display_trj_msg);

          this->get_clock()->sleep_for(
                std::chrono_literals::operator""s(
                  rclcpp::Duration(approach_trj.joint_trajectory.points.back().time_from_start).seconds()));

          if(goal_handle_->is_canceling())
            return;

          display_trj_msg.trajectory.at(0)=trj;
          display_trj_pub_->publish(display_trj_msg);
          this->get_clock()->sleep_for(
                std::chrono_literals::operator""s(
                  rclcpp::Duration(trj.joint_trajectory.points.back().time_from_start).seconds()));
        }
      }
    }

    result->ok=true;
    goal_handle_->succeed(result);
    return;
  }

  template<typename T>
  bool checkd(const std::vector<T>& in, const size_t& dim, const std::string& id, std::string& what)
  {
    bool ret = in.size() == dim;
    if(!ret)
    {
      what += std::string(what.length()>0 ? "\n" : "") +
          "The vector '" + id + "' dimension is '"+ std::to_string(in.size()) + "' but '"+std::to_string(dim)+"' is expected";
    }
    return ret;
  }

  bool getTrajectoryFromParam(const std::string& trj_name, trajectory_msgs::msg::JointTrajectory& trj, std::string& what)
  {
    RCLCPP_INFO(this->get_logger(),"Reading trajectory %s from param ",trj_name.c_str());

    std::vector<std::string>          n;
    std::vector<double>               t;
    std::vector<std::vector<double>>  q, qd, qdd, eff;

    std::vector<std::string> params =
    {"joint_names", "time_from_start", "positions", "velocities", "accelerations", "effort" };

    for(size_t i=0; i<params.size(); i++)
    {
      std::string w;
      bool ok = true;
      std::string ns = trj_name+"/"+params.at(i);
      switch(i)
      {
      case 0:
        ok = cnr::param::get(ns,n,w);
        break;
      case 1:
        ok = cnr::param::get(ns,t,w);
        break;
      case 2:
        ok = cnr::param::get(ns, q, w);
        break;
      case 3:
        ok = cnr::param::get(ns, qd, w);
        break;
      case 4:
        ok = cnr::param::get(ns, qdd, w);
        break;
      case 5:
        ok = cnr::param::get(ns, eff, w);
        break;
      }
      what += (what.length()>0 && w.length()>0 ? "\n" : "") + w;
      if(not ok)
        return false;
    }

    if((q.size() == 0) || (q.at(0).size() == 0))
    {
      what += trj_name + "/positions is broken";
      return false;
    }
    size_t np = q.size();
    size_t dof = q.at(0).size();

    if((n.size()==0 || !checkd(n, dof, "joint_names", what))
       || (t.size()!=0 && !checkd(t, np , "time_from_start", what))
       || (qd.size()!=0 && !checkd(qd, np , "velocities", what))
       || (qdd.size()!=0 && !checkd(qdd, np , "accelerations", what))
       || (eff.size()!=0 && !checkd(eff, np , "effort", what) ))
    {
      return false;
    }

    std::map< std::string, std::vector<std::vector<double>>& > checks =
    {{"position", q}, {"velocity", qd}, {"acceleration", qdd}, {"effort", eff}};

    for(const auto & cc : checks )
    {
      if(cc.second.size()!=0)
      {
        for(size_t i=0;i<np;i++)
        {
          if( !checkd( cc.second.at(i) , dof, cc.first +"#" + std::to_string(i), what))
            return false;
        }
      }
    }

    // TRJ MODIFICATION == == == == == == == == == == == == == ==
    trj.joint_names = n;
    trj.points.clear();
    trj.points.resize(np);

    for (size_t i=0;i<np;i++)
    {
      trj.points.at(i).positions = q.at(i);
      if (qd.size()>0)
      {
        trj.points.at(i).velocities = qd.at(i);
      }
      if (qdd.size()>0)
      {
        trj.points.at(i).accelerations = qdd.at(i);
      }
      if (eff.size()>0)
      {
        trj.points.at(i).effort = eff.at(i);
      }

      builtin_interfaces::msg::Duration duration;
      if(t.size()>0)
        duration = rclcpp::Duration::from_seconds(t.at(i));
      else
        duration = rclcpp::Duration::from_seconds(0.0);

      trj.points.at(i).time_from_start = duration;
    }

    RCLCPP_INFO_STREAM(this->get_logger(),"Trajectory read from param positions:");
    for(size_t i=0;i<np;i++)
    {
      std::string pos = "";
      unsigned int n=0;
      for(const auto& d:trj.points.at(i).positions)
      {
        pos = pos+std::to_string(d)+ " ";
      }
      RCLCPP_INFO_STREAM(this->get_logger(),"point "<<n<<": ["<<pos<<"]");
    }

    return true;
  }

  rclcpp_action::GoalResponse handle_goal(
      const rclcpp_action::GoalUUID & uuid,
      std::shared_ptr<const trajectory_loader::action::TrajectoryLoaderAction::Goal> goal)
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
      <trajectory_loader::action::TrajectoryLoaderAction>> goal_handle)
  {
    RCLCPP_INFO(this->get_logger(), "Received request to cancel goal");

    auto cancel_future = this->client_ptr_->async_cancel_all_goals();
    cancel_future.get();

    (void)goal_handle;
    return rclcpp_action::CancelResponse::ACCEPT;
  }

  void handle_accepted(const std::shared_ptr<rclcpp_action::ServerGoalHandle
                       <trajectory_loader::action::TrajectoryLoaderAction>> goal_handle)
  {
    goal_handle_ = goal_handle;
    std::thread(std::bind(&TrajectoryLoaderServer::load_trajectory, this)).detach();
  }
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);

  rclcpp::NodeOptions node_options;
  node_options.automatically_declare_parameters_from_overrides(true);
  auto node = std::make_shared<TrajectoryLoaderServer>(node_options);

  rclcpp::spin(node);
  rclcpp::shutdown();

  return 0;
}

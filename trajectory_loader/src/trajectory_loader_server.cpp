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
  explicit TrajectoryLoaderServer(moveit::planning_interface::MoveGroupInterface& move_group, const rclcpp::NodeOptions & node_options = rclcpp::NodeOptions().automatically_declare_parameters_from_overrides(true))
    : Node("trajectory_loader_server", node_options), move_group_(move_group)
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

    robot_description_ = parameters_client->get_parameter<std::string>("robot_description");
  }

private:
  moveit::planning_interface::MoveGroupInterface& move_group_;
  std::string robot_description_;
  trajectory_msgs::msg::JointTrajectory trajectory_;
  rclcpp::Publisher<moveit_msgs::msg::DisplayTrajectory>::SharedPtr display_trj_pub_;
  rclcpp_action::Client<moveit_msgs::action::ExecuteTrajectory>::SharedPtr client_ptr_;
  rclcpp_action::Server<trajectory_loader::action::TrajectoryLoaderAction>::SharedPtr server_ptr_;
  std::shared_ptr<rclcpp_action::ServerGoalHandle<trajectory_loader::action::TrajectoryLoaderAction>> goal_handle_;

  void load_trajectory()
  {
    std::string node_ns = this->get_namespace();

    this->client_ptr_ = rclcpp_action::create_client<moveit_msgs::action::ExecuteTrajectory>(this,"/execute_trajectory");

    auto result = std::make_shared<trajectory_loader::action::TrajectoryLoaderAction::Result>();
    auto feedback = std::make_shared<trajectory_loader::action::TrajectoryLoaderAction::Feedback>();

    result->ok = false;
    const auto goal = goal_handle_->get_goal();
    bool simulate = goal->simulation;
    static const std::string group_name = goal->group_name;
    std::vector<std::string> executed_trjs = goal->trj_names;
    bool rescale = goal->rescale;
    unsigned int repetitions = goal->repetitions;

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

    RCLCPP_WARN(this->get_logger(),"QUA");

    if(this->robot_description_.empty())
    {
      RCLCPP_WARN(this->get_logger(),"robot_description not available");
      result->error = "robot_description not available";
      goal_handle_->abort(result);
      return;
    }
    RCLCPP_WARN(this->get_logger(),"QUA1");
    RCLCPP_WARN_STREAM(this->get_logger(),this->robot_description_);


    const rclcpp::Node::SharedPtr node = this->shared_from_this();
    RCLCPP_ERROR_STREAM(this->get_logger(),node->get_name());


//    moveit::planning_interface::MoveGroupInterface move_group(node,group_name);
    //    moveit::planning_interface::MoveGroupInterface::Options opt(group_name,this->robot_description_);
    RCLCPP_WARN(this->get_logger(),"QUA2");

    //    moveit::planning_interface::MoveGroupInterface move_group(node,opt);

    RCLCPP_WARN(this->get_logger(),"QUA3");

    moveit::planning_interface::MoveGroupInterface::Plan my_plan;
    bool success;

    //    if(executed_trjs.size()==0)
    //    {
    //      rclcpp::Parameter trjs;
    //      if(not this->get_parameter("list_of_trajectories", trjs))
    //      {
    //        RCLCPP_ERROR(this->get_logger(), "No list of trajectories specified!");
    //        result->error = "No list of trajectories specified!";
    //        goal_handle_->abort(result);
    //        return;
    //      }
    //      else
    //        executed_trjs = trjs.as_string_array();
    //    }

    if(executed_trjs.size()==0)
    {
      std::string w;
      if(not cnr::param::get(node_ns+"/list_of_trajectories",executed_trjs,w))
      {
        RCLCPP_ERROR(this->get_logger(), "No list of trajectories specified!");
        result->error = "No list of trajectories specified!";
        goal_handle_->abort(result);
        return;
      }
      else
        RCLCPP_INFO(this->get_logger(), "trajectories read from param!");
    }

    move_group_.startStateMonitor();
    moveit::core::RobotState trj_state = *move_group_.getCurrentState();

    for(unsigned irep = 0; irep<repetitions; irep++)
    {
      if(goal_handle_->is_canceling())
        return;

      for (const std::string & current_trj_name : executed_trjs)
      {
        if(goal_handle_->is_canceling())
          return;

        feedback->trj_in_execution = current_trj_name;
        feedback->current_repetition = irep;

        goal_handle_->publish_feedback(feedback);

        trajectory_msgs::msg::JointTrajectory trj_from_param;
        moveit_msgs::msg::RobotTrajectory my_trj;
        moveit_msgs::msg::RobotTrajectory approach_trj;

        std::string what;
        if (not getTrajectoryFromParam(node_ns+"/"+current_trj_name, trj_from_param, what))
        {
          RCLCPP_ERROR(this->get_logger(),"%s not found", current_trj_name.c_str());
          result->error = current_trj_name+ " not found";
          goal_handle_->abort(result);
          return;
        }

        if(goal_handle_->is_canceling())
          return;

        // Next get the current set of joint values for the group.
        std::vector<double> initial_position = trj_from_param.points.begin()->positions;

        bool is_single_point = false;
        if (trj_from_param.points.size() < 2)
        {
          my_trj.joint_trajectory = trj_from_param;
          is_single_point = true;
        }
        else
        {
          trj_state.setJointGroupPositions(group_name, initial_position);
          robot_trajectory::RobotTrajectory trajectory(move_group_.getRobotModel(), group_name);
          trajectory.setRobotTrajectoryMsg(trj_state, trj_from_param);
          if(rescale)
          {
            trajectory_processing::IterativeSplineParameterization isp;
            isp.computeTimeStamps(trajectory);
            trajectory.getRobotTrajectoryMsg(my_trj);
          }
          else
            my_trj.joint_trajectory=trj_from_param;
        }

        if (rclcpp::Duration(my_trj.joint_trajectory.points.back().time_from_start) > rclcpp::Duration(trj_from_param.points.back().time_from_start))
          RCLCPP_WARN(this->get_logger(),"trajectory is scaled to respect joint limit");

        if(goal_handle_->is_canceling())
          return;

        //Go to the first configuration of the trajectory
        move_group_.startStateMonitor(2);
        move_group_.setStartState(*move_group_.getCurrentState());
        move_group_.setJointValueTarget(initial_position);

        robot_trajectory::RobotTrajectory trajectory(move_group_.getRobotModel(), group_name);
        success = (move_group_.plan(my_plan) == moveit::core::MoveItErrorCode::SUCCESS);
        if(not success)
        {
          RCLCPP_ERROR(this->get_logger(),"planning failed!");
          result->error = "planning failed!";
          goal_handle_->abort(result);
          return;
        }

        trajectory.setRobotTrajectoryMsg(trj_state, my_plan.trajectory_.joint_trajectory);
        trajectory_processing::IterativeSplineParameterization isp;
        isp.computeTimeStamps(trajectory);
        trajectory.getRobotTrajectoryMsg(approach_trj);

        if(not simulate)
          RCLCPP_INFO(this->get_logger(),"Move %s to initial position", group_name.c_str());

        if(goal_handle_->is_canceling())
          return;

        moveit_msgs::action::ExecuteTrajectory::Goal goal;
        if(is_single_point && (not simulate))
        {
          //          this->get_clock()->sleep_for(std::chrono_literals::operator""s(3));
          goal.trajectory = approach_trj;

          auto future_goal_handle=this->client_ptr_->async_send_goal(goal);
          if(future_goal_handle.get() == nullptr)
          {
            result->error = "/execute_trajectory action rejected the goal";
            goal_handle_->abort(result);
            return;
          }

          if(goal_handle_->is_canceling())
            return;

          //Goal accepted by the action server, wait for result
          this->client_ptr_->async_get_result(future_goal_handle.get());

          //          auto action_client_result_future= this->client_ptr_->async_get_result(future_goal_handle.get());
          //          auto action_client_result = action_client_result_future.get();
        }
        else
        {
          if(not simulate)
          {
            goal.trajectory = approach_trj;
            auto future_goal_handle=this->client_ptr_->async_send_goal(goal);
            if(future_goal_handle.get() == nullptr)
            {
              result->error = "/execute_trajectory action rejected the goal";
              goal_handle_->abort(result);
              return;
            }

            if(goal_handle_->is_canceling())
              return;

            //Goal accepted by the action server, wait for result
            this->client_ptr_->async_get_result(future_goal_handle.get());

            //            this->get_clock()->sleep_for(std::chrono_literals::operator""s(3));

            RCLCPP_INFO(this->get_logger(), "Execute trajectory %s", current_trj_name.c_str());
            goal.trajectory = my_trj;
            future_goal_handle=this->client_ptr_->async_send_goal(goal);
            if(future_goal_handle.get() == nullptr)
            {
              result->error = "/execute_trajectory action rejected the goal";
              goal_handle_->abort(result);
              return;
            }

            if(goal_handle_->is_canceling())
              return;

            //Goal accepted by the action server, wait for result
            this->client_ptr_->async_get_result(future_goal_handle.get());
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

            display_trj_msg.trajectory.at(0)=my_trj;
            display_trj_pub_->publish(display_trj_msg);
            this->get_clock()->sleep_for(
                  std::chrono_literals::operator""s(
                    rclcpp::Duration(my_trj.joint_trajectory.points.back().time_from_start).seconds()));
          }
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

  bool getTrajectoryFromParam(const std::string& full_path_to_trj, trajectory_msgs::msg::JointTrajectory& trj, std::string& what)
  {
    what = "";
    if((full_path_to_trj.length()==0)||(full_path_to_trj.front()!='/'))
    {
      what = "Error: The input 'full_path_to_trj' name is void or does not start with '/'";
      return false;
    }

    std::vector<std::string>          n;
    std::vector<double>               t;
    std::vector<std::vector<double>>  q, qd, qdd, eff;

    std::vector<std::string> params =
    {"joint_names", "time_from_start", "positions", "velocities", "accelerations", "effort" };

    for(size_t i=0; i<params.size(); i++)
    {
      std::string w;
      bool ok = true;
      std::string ns = full_path_to_trj+"/" + params.at(i);
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
      what += full_path_to_trj + "/positions is broken";
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

  auto node = rclcpp::Node::make_shared("trajectory_loader_node", node_options);

  rclcpp::executors::MultiThreadedExecutor executor;
  executor.add_node(node);
  std::thread([&executor]() { executor.spin(); }).detach();

  static const std::string PLANNING_GROUP = "manipulator";
  moveit::planning_interface::MoveGroupInterface move_group(node, PLANNING_GROUP);
  RCLCPP_WARN(node->get_logger(),"QUUAAAAAAAAA");

  //LEGGI ROBOT DESCRIPTION E CARICALA NEI PARAMETRI DEL NODO

  rclcpp::spin(std::make_shared<TrajectoryLoaderServer>(move_group,node_options));


  rclcpp::shutdown();
  return 0;
}

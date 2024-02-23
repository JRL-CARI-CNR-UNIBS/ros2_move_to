#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "rclcpp_components/register_node_macro.hpp"
#include "control_msgs/action/follow_joint_trajectory.hpp"
#include "trajectory_msgs/msg/joint_trajectory.hpp"
#include "std_srvs/srv/trigger.hpp"
#include "moveit_msgs/action/execute_trajectory.hpp"
#include "trajectory_loader/action/trajectory_loader_action.hpp"
#include "moveit/move_group_interface/move_group_interface.h"


class TrajectoryLoaderServer : public rclcpp::Node
{
public:

  explicit TrajectoryLoaderServer(const rclcpp::NodeOptions & node_options = rclcpp::NodeOptions())
    : Node("trajectory_loader_action_client", node_options)
  {
    this->server_ptr_ = rclcpp_action::create_server<trajectory_loader::action::TrajectoryLoaderAction>(
          this,"/trajectory_loader",
          std::bind(&TrajectoryLoaderServer::handle_goal, this, std::placeholders::_1, std::placeholders::_2),
          std::bind(&TrajectoryLoaderServer::handle_cancel, this, std::placeholders::_1),
          std::bind(&TrajectoryLoaderServer::handle_accepted, this, std::placeholders::_1));
  }

  void load_trajectory()
  {
    this->client_ptr_ = rclcpp_action::create_client<moveit_msgs::action::ExecuteTrajectory>(this,"/execute_trajectory");

    trajectory_loader::action::TrajectoryLoaderAction::Result::SharedPtr result;
    result->ok = false;

    const auto goal = goal_handle_->get_goal();
    bool simulate=goal->simulation;
    std::string group_name=goal->group_name;
    std::vector<std::string> executed_trjs=goal->trj_names;

    if(not simulate)
    {
      if (not client_ptr_->wait_for_action_server(std::chrono::duration<double>(10.0)))
      {
        RCLCPP_ERROR(this->get_logger(), "No /execute_trajectory action server found!");
        goal_handle_->abort(result);
        return;
      }
    }

    moveit::planning_interface::MoveGroupInterface move_group(this->shared_from_this(),group_name);
    moveit::planning_interface::MoveGroupInterface::Plan my_plan;
    bool success;

    if (executed_trjs.size()==0)
    {
      rclcpp::Parameter trjs;
      if(not this->get_parameter("list_of_trajectories", trjs))
      {
        RCLCPP_ERROR(this->get_logger(), "No list of trajectories specified!");
        goal_handle_->abort(result);
        return;
      }
      else
        executed_trjs = trjs.as_string_array();
    }
  }

private:
  trajectory_msgs::msg::JointTrajectory trajectory_;
  rclcpp_action::Client<moveit_msgs::action::ExecuteTrajectory>::SharedPtr client_ptr_;
  rclcpp_action::Server<trajectory_loader::action::TrajectoryLoaderAction>::SharedPtr server_ptr_;
  std::shared_ptr<rclcpp_action::ServerGoalHandle<trajectory_loader::action::TrajectoryLoaderAction>> goal_handle_;

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
  //  auto action_client = std::make_shared<TrajectoryLoaderServer>();
}

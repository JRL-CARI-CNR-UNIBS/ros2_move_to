#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "rclcpp_components/register_node_macro.hpp"
#include "control_msgs/action/follow_joint_trajectory.hpp"
#include "trajectory_msgs/msg/joint_trajectory.hpp"
#include "std_srvs/srv/trigger.hpp"


class TrajectoryLoaderServer : public rclcpp::Node
{
public:

  explicit TrajectoryLoaderServer(const std::string& namespace, const rclcpp::NodeOptions & node_options = rclcpp::NodeOptions())
  : Node("trajectory_loader_action_client", node_options)
  {
      this->server_ptr_ = rclcpp::create_server<std_srvs::srv::Trigger>("trajectory_loader", &load_trajectoy);

      this->client_ptr_ = rclcpp_action::create_client<control_msgs::action::FollowJointTrajectory>(
        this->get_node_base_interface(),
        this->get_node_graph_interface(),
        this->get_node_logging_interface(),
        this->get_node_waitables_interface(),
        namespace+"/follow_joint_trajectory");
  }

  void load_trajectory()
  {
    //Read trj from param and sent to action client
    trajectory_msgs::msg::JointTrajectory trj;

    this->trajectory_ = trj;
    this->client_ptr_->send_goal()
  }

  void send_goal()
  {
    if (!this->client_ptr_) 
      RCLCPP_ERROR(this->get_logger(), "Action client not initialized");

    if(!this->client_ptr_->wait_for_action_server(std::chrono::seconds(10))) 
    {
      RCLCPP_ERROR(this->get_logger(), "Action server not available after waiting");
      return;
    }

    control_msgs::action::FollowJointTrajectory::Goal goal_msg;
    goal_msg.trajectory = trajectory_;

    RCLCPP_INFO(this->get_logger(), "Sending goal");

    auto send_goal_options = rclcpp_action::Client<FollowJointTrajectory>::SendGoalOptions();
    send_goal_options.goal_response_callback =
      std::bind(&TrajectoryLoaderServer::goal_response_callback, this, _1);
    send_goal_options.feedback_callback =
      std::bind(&TrajectoryLoaderServer::feedback_callback, this, _1, _2);
    send_goal_options.result_callback =
      std::bind(&TrajectoryLoaderServer::result_callback, this, _1);

    auto goal_handle_future = this->client_ptr_->async_send_goal(goal_msg, send_goal_options);
  }

private:
  trajectory_msgs::msg::JointTrajectory trajectory_;
  rclcpp_action::Server<std_srvs::srv::Trigger>::SharedPtr server_ptr_;
  rclcpp_action::Client<control_msgs::action::FollowJointTrajectory>::SharedPtr client_ptr_;

  void goal_response_callback(rclcpp_action::ClientGoalHandle
  <control_msgs::action::FollowJointTrajectory>::SharedPtr goal_handle)
  {
    if (!goal_handle)
      RCLCPP_ERROR(this->get_logger(), "Goal was rejected by server");
    else
      RCLCPP_INFO(this->get_logger(), "Goal accepted by server, waiting for result");
  }

  void feedback_callback(
  rclcpp_action::ClientGoalHandle<control_msgs::action::FollowJointTrajectory>::SharedPtr,
  const std::shared_ptr<const control_msgs::action::FollowJointTrajectory::Feedback> feedback)
  {
    RCLCPP_INFO(this->get_logger(), "feedback->desired.positions :");
    for (auto & x : feedback->desired.positions) 
      RCLCPP_INFO_STREAM(this->get_logger(), x<<"/t");

    RCLCPP_INFO(this->get_logger(), "feedback->desired.velocities :");
    for (auto & x : feedback->desired.velocities) 
      RCLCPP_INFO_STREAM(this->get_logger(), x<<"/t");
  }

  void result_callback(const rclcpp_action::ClientGoalHandle
  <control_msgs::action::FollowJointTrajectory>::WrappedResult & result)
  {
    switch (result.code) {
      case rclcpp_action::ResultCode::SUCCEEDED:
        break;
      case rclcpp_action::ResultCode::ABORTED:
        RCLCPP_ERROR(this->get_logger(), "Goal was aborted");
        return;
      case rclcpp_action::ResultCode::CANCELED:
        RCLCPP_ERROR(this->get_logger(), "Goal was canceled");
        return;
      default:
        RCLCPP_ERROR(this->get_logger(), "Unknown result code");
        return;
    }

    RCLCPP_INFO(this->get_logger(), "Action succeeded!");
    }
  }
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  auto action_client = std::make_shared<TrajectoryLoaderServer>();
}
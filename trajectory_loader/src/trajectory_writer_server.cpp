#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "rclcpp_components/register_node_macro.hpp"
#include "trajectory_msgs/msg/joint_trajectory.hpp"
#include "trajectory_loader/action/trajectory_writer_action.hpp"
#include "sensor_msgs/msg/joint_state.hpp"
#include "thread"

class TrajectoryWriterServer : public rclcpp::Node
{
public:

  explicit TrajectoryWriterServer(const rclcpp::NodeOptions & node_options = rclcpp::NodeOptions())
  : Node("trajectory_writer_action_server", node_options)
  {
//      this->action_server_ = rclcpp_action::create_server<TrajectoryWriterAction>(
//        this,
//        "trajectory_writer",
//        std::bind(&TrajectoryWriterServer::handle_goal, this, _1, _2),
//        std::bind(&TrajectoryWriterServer::handle_cancel, this, _1),
//        std::bind(&TrajectoryWriterServer::handle_accepted, this, _1));
  }

private:
  std::string path_to_file_;
  std::string topic_to_listen_;
  trajectory_msgs::msg::JointTrajectory trajectory_;
  rclcpp_action::Server<TrajectoryWriterAction>::SharedPtr action_server_;
  rclcpp::Subscription<trajectory_msgs::msg::JointState>::SharedPtr subscription_;

//  rclcpp_action::GoalResponse handle_goal(
//    const rclcpp_action::GoalUUID & uuid,
//    std::shared_ptr<const TrajectoryWriterAction::Goal> goal)
//  {
//    RCLCPP_INFO(this->get_logger(), "Received goal request for topic %s and path %s",
//     goal->topic_to_listen_, goal->path_to_file);

//    if(goal->topic_to_listen_ != this->topic_to_listen_)
//    {
//      subscription_.reset(); //unsubscribe old topic

//      subscription_ = this->create_subscription<sensor_msgs::msg::JointState>(
//        goal->topic_to_listen_, 10, std::bind(&TrajectoryWriterServer::topic_callback, this, _1));
//    }

//    this->path_to_file_ = goal_->path_to_file;
//    this->topic_to_listen_ = goal->topic_to_listen;

//    (void)uuid;
//    return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
//  }

//    rclcpp_action::CancelResponse handle_cancel(
//    const std::shared_ptr<rclcpp_action::ServerGoalHandle<TrajectoryWriterAction>> goal_handle)
//  {
//    RCLCPP_INFO(this->get_logger(), "Received request to cancel goal");

//    (void)goal_handle;
//    return rclcpp_action::CancelResponse::ACCEPT;
//  }

//  void handle_accepted(
//    const std::shared_ptr<rclcpp_action::ServerGoalHandle<TrajectoryWriterAction>> goal_handle)
//  {
//    // this needs to return quickly to avoid blocking the executor, so spin up a new thread
//    std::thread{std::bind(&TrajectoryWriterServer::execute, this, _1), goal_handle}.detach();
//  }

//  void execute(const std::shared_ptr<GoalHandleFibonacci> goal_handle)
//  {
//    RCLCPP_INFO(this->get_logger(), "Executing goal");
//    rclcpp::Rate loop_rate(1);
//    const auto goal = goal_handle->get_goal();
//    auto feedback = std::make_shared<TrajectoryWriterAction::Feedback>();
//    auto & sequence = feedback->partial_sequence;
//    sequence.push_back(0);
//    sequence.push_back(1);
//    auto result = std::make_shared<TrajectoryWriterAction::Result>();

//    for (int i = 1; (i < goal->order) && rclcpp::ok(); ++i) {
//      // Check if there is a cancel request
//      if (goal_handle->is_canceling()) {
//        result->sequence = sequence;
//        goal_handle->canceled(result);
//        RCLCPP_INFO(this->get_logger(), "Goal canceled");
//        return;
//      }
//      // Update sequence
//      sequence.push_back(sequence[i] + sequence[i - 1]);
//      // Publish feedback
//      goal_handle->publish_feedback(feedback);
//      RCLCPP_INFO(this->get_logger(), "Publish feedback");

//      loop_rate.sleep();
//    }

//    // Check if goal is done
//    if (rclcpp::ok()) {
//      result->sequence = sequence;
//      goal_handle->succeed(result);
//      RCLCPP_INFO(this->get_logger(), "Goal succeeded");
//    }
//  }
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  auto action_client = std::make_shared<TrajectoryWriterServer>();
}

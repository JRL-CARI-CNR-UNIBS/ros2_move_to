#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "trajectory_loader/action/trajectory_loader_action.hpp"

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  auto node = rclcpp::Node::make_shared("test_trajectory_loader");
  rclcpp_action::Client<trajectory_loader::action::TrajectoryLoaderAction>::SharedPtr client_ptr;
  client_ptr = rclcpp_action::create_client<trajectory_loader::action::TrajectoryLoaderAction>(node,"/trajectory_loader");

  while(not client_ptr->wait_for_action_server(std::chrono::seconds(1)))
  {
    if (not rclcpp::ok())
    {
      RCLCPP_ERROR(node->get_logger(), "client interrupted while waiting for action /trajectory_loader to appear.");
      return 1;
    }
    RCLCPP_INFO(node->get_logger(), "waiting for action /trajectory_loader to appear...");
  }

  auto goal = trajectory_loader::action::TrajectoryLoaderAction::Goal();
  std::vector<std::string> trj; trj.push_back("trj_test");
  goal.group_name = "manipulator";
  goal.repetitions = 5;
  goal.rescale = false;
  goal.simulation = false;
  goal.trj_names = trj;

  auto future = client_ptr->async_send_goal(goal);
  auto res = rclcpp::spin_until_future_complete(node,future);
  RCLCPP_INFO_STREAM(node->get_logger(),"Result: "<<res);
  std::cin.get();

  rclcpp::shutdown();
  return 0;
}

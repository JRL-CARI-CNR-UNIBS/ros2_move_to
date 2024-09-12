#include "rclcpp/rclcpp.hpp"
#include <rclcpp/parameter_client.hpp>
#include "rclcpp_action/rclcpp_action.hpp"
#include "rclcpp_components/register_node_macro.hpp"
#include <moveit/move_group_interface/move_group_interface.h>

using namespace std::chrono_literals;

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);

  auto node = std::make_shared<rclcpp::Node>("move_group_test_node");

  // Get robot_description
  rclcpp::SyncParametersClient::SharedPtr parameters_client = std::make_shared<rclcpp::SyncParametersClient>(node, std::string("/move_group"));
  while (!parameters_client->wait_for_service(1s))
  {
    if (!rclcpp::ok())
    {
      RCLCPP_ERROR(node->get_logger(), "Interrupted while waiting for the service. Exiting.");
      rclcpp::shutdown();
    }
    RCLCPP_INFO(node->get_logger(), "service not available, waiting again...");
  }
  if(not parameters_client->has_parameter("robot_description"))
    RCLCPP_ERROR(node->get_logger(), "Cannot find robot_description parameter");
  if(not parameters_client->has_parameter("robot_description_semantic"))
    RCLCPP_ERROR(node->get_logger(), "Cannot find robot_description_semantic parameter");

  std::string param_name = "robot_description";
  std::string robot_description = parameters_client->get_parameter<std::string>(param_name);

  rclcpp::Parameter robot_description_param(param_name,robot_description);
  node->declare_parameter(param_name, rclcpp::PARAMETER_STRING);
  node->set_parameter(robot_description_param);

  if(not node->has_parameter(param_name))
    throw std::runtime_error("no robot description");
  else
    RCLCPP_WARN(node->get_logger(),"robot description loaded");

  param_name = "robot_description_semantic";
  std::string robot_description_semantic = parameters_client->get_parameter<std::string>(param_name);

  rclcpp::Parameter robot_description_semantic_param(param_name,robot_description_semantic);
  node->declare_parameter(param_name, rclcpp::PARAMETER_STRING);
  node->set_parameter(robot_description_semantic_param);

  if(not node->has_parameter(param_name))
    throw std::runtime_error("no robot description semantic");
  else
    RCLCPP_WARN(node->get_logger(),"robot description semantic loaded");

  auto thread = std::thread([&]{rclcpp::spin(node);});

  RCLCPP_WARN(node->get_logger(),"Getting current state");
  moveit::planning_interface::MoveGroupInterface move_group(node,"kuka");
  move_group.startStateMonitor();

  RCLCPP_WARN(node->get_logger(),"Getting current state");
  auto state = move_group.getCurrentState(3.0);
  auto joints = move_group.getActiveJoints();

  for(auto j:joints)
    RCLCPP_WARN_STREAM(node->get_logger(),"joint "<<j<<": "<<*state->getJointPositions(j));

  rclcpp::shutdown();
  thread.join();

  return 0;
}

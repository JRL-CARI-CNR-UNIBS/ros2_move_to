#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "trajectory_loader/action/trajectory_loader_action.hpp"
#include "cnr_param/cnr_param.h"

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

  std::string ns = "/trj_loader_test/";
  std::string w;
  std::vector<std::string> trj;
  if(cnr::param::has(ns+"trj_names",w))
  {
    if(cnr::param::is_sequence(ns+"trj_names"))
      cnr::param::get(ns+"trj_names",trj,w);
    else
    {
      RCLCPP_ERROR(node->get_logger(),"trj_names should be a vector");
      return 1;
    }
  }
  else
  {
    RCLCPP_ERROR(node->get_logger(),"trj_names not defined");
    RCLCPP_ERROR_STREAM(node->get_logger(),w);

    return 1;
  }

  std::string group_name;
  if(cnr::param::has(ns+"group_name",w))
    cnr::param::get(ns+"group_name",group_name,w);
  else
  {
    RCLCPP_ERROR(node->get_logger(),"group_name not defined");
    RCLCPP_ERROR_STREAM(node->get_logger(),w);

    return 1;
  }

  int repetitions;
  if(cnr::param::has(ns+"repetitions",w))
    cnr::param::get(ns+"repetitions",repetitions,w);
  else
  {
    RCLCPP_ERROR(node->get_logger(),"repetitions not defined");
    RCLCPP_ERROR_STREAM(node->get_logger(),w);

    return 1;
  }

  bool recompute_time_law;
  if(cnr::param::has(ns+"recompute_time_law",w))
    cnr::param::get(ns+"recompute_time_law",recompute_time_law,w);
  else
  {
    RCLCPP_ERROR(node->get_logger(),"recompute_time_law not defined");
    RCLCPP_ERROR_STREAM(node->get_logger(),w);

    return 1;
  }

  bool simulation;
  if(cnr::param::has(ns+"simulation",w))
    cnr::param::get(ns+"simulation",simulation,w);
  else
  {
    RCLCPP_ERROR(node->get_logger(),"simulation not defined");
    RCLCPP_ERROR_STREAM(node->get_logger(),w);

    return 1;
  }

  double scaling;
  if(cnr::param::has(ns+"scaling",w))
    cnr::param::get(ns+"scaling",scaling,w);
  else
  {
    RCLCPP_ERROR(node->get_logger(),"scaling not defined");
    RCLCPP_ERROR_STREAM(node->get_logger(),w);

    return 1;
  }

  goal.trj_names = trj;
  goal.group_name = group_name;
  goal.repetitions = repetitions;
  goal.recompute_time_law = recompute_time_law;
  goal.simulation = simulation;
  goal.scaling = scaling;

  auto future = client_ptr->async_send_goal(goal);
  auto res = rclcpp::spin_until_future_complete(node,future);
  RCLCPP_INFO_STREAM(node->get_logger(),"Result: "<<res);
  std::cin.get();

  rclcpp::shutdown();
  return 0;
}

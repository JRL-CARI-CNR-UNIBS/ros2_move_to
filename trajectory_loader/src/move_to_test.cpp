#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "trajectory_loader/action/move_to_action.hpp"

#include "geometry_msgs/msg/transform_stamped.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "tf2/exceptions.h"
#include "tf2_ros/transform_listener.h"
#include "tf2_ros/buffer.h"

#include "cnr_param/cnr_param.h"

namespace tf2
{
inline
void convert(const geometry_msgs::msg::Transform& trans, geometry_msgs::msg::Pose& pose)
{
  pose.orientation = trans.rotation;
  pose.position.x = trans.translation.x;
  pose.position.y = trans.translation.y;
  pose.position.z = trans.translation.z;
}

inline
void convert(const geometry_msgs::msg::Pose& pose, geometry_msgs::msg::Transform& trans)
{
  trans.rotation = pose.orientation;
  trans.translation.x = pose.position.x;
  trans.translation.y = pose.position.y;
  trans.translation.z = pose.position.z;
}

inline
void convert(const geometry_msgs::msg::TransformStamped& trans, geometry_msgs::msg::PoseStamped& pose)
{
  convert(trans.transform, pose.pose);
  pose.header = trans.header;
}

inline
void convert(const geometry_msgs::msg::PoseStamped& pose, geometry_msgs::msg::TransformStamped& trans)
{
  convert(pose.pose, trans.transform);
  trans.header = pose.header;
}
}

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  auto node = rclcpp::Node::make_shared("test_move_to");
  rclcpp_action::Client<trajectory_loader::action::MoveToAction>::SharedPtr client_ptr;

  std::string action_name;
  if(node->get_namespace() == std::string("/"))
    action_name = std::string("/move_to");
  else
    action_name = node->get_namespace()+std::string("/move_to");

  RCLCPP_INFO_STREAM(node->get_logger(),"Subscribing action "<<action_name);

  client_ptr = rclcpp_action::create_client<trajectory_loader::action::MoveToAction>(node,action_name);

  while(not client_ptr->wait_for_action_server(std::chrono::seconds(1)))
  {
    if (not rclcpp::ok())
    {
      RCLCPP_ERROR(node->get_logger(), "client interrupted while waiting for action %s to appear.",action_name.c_str());
      return 1;
    }
    RCLCPP_INFO(node->get_logger(), "waiting for action %s to appear...",action_name.c_str());
  }

  std::string ns = node->get_namespace()+std::string("/move_to_test/");
  std:: string w;
  std::string group_name;
  if(cnr::param::has(ns+"group_name",w))
    cnr::param::get(ns+"group_name",group_name,w);
  else
  {
    RCLCPP_ERROR(node->get_logger(),"group_name not defined");
    RCLCPP_ERROR_STREAM(node->get_logger(),w);

    return 1;
  }

  std::string tool_frame;
  if(cnr::param::has(ns+"tool_frame",w))
    cnr::param::get(ns+"tool_frame",tool_frame,w);
  else
  {
    RCLCPP_ERROR(node->get_logger(),"tool_frame not defined");
    RCLCPP_ERROR_STREAM(node->get_logger(),w);

    return 1;
  }

  std::string ik_service_name;
  if(cnr::param::has(ns+"ik_service_name",w))
    cnr::param::get(ns+"ik_service_name",ik_service_name,w);
  else
  {
    RCLCPP_ERROR(node->get_logger(),"ik_service_name not defined");
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

  double z_shift;
  if(cnr::param::has(ns+"z_shift",w))
    cnr::param::get(ns+"z_shift",z_shift,w);
  else
  {
    RCLCPP_ERROR(node->get_logger(),"z_shift not defined");
    RCLCPP_ERROR_STREAM(node->get_logger(),w);

    return 1;
  }

  std::string tf = tool_frame;
  std::string base_frame = tool_frame;

  auto tf_buffer = std::make_unique<tf2_ros::Buffer>(node->get_clock());
  auto tf_listener = std::make_shared<tf2_ros::TransformListener>(*tf_buffer);

  tf2::Duration duration(10000000000);
  geometry_msgs::msg::TransformStamped transform;
  while(not tf_buffer->canTransform(tf,base_frame,tf2::TimePointZero,duration))
  {
    try {
      transform = tf_buffer->lookupTransform(
            tf, base_frame,
            tf2::TimePointZero);
    } catch (const tf2::TransformException & ex) {
      RCLCPP_INFO(
            node->get_logger(), "Could not transform %s to %s: %s",
            tf.c_str(), base_frame.c_str(), ex.what());
      return 1;
    }
  }

  geometry_msgs::msg::PoseStamped pose;
  tf2::convert(transform,pose);

  pose.header.frame_id = tf;
  pose.pose.position.z = pose.pose.position.z+z_shift;

  auto goal = trajectory_loader::action::MoveToAction::Goal();
  goal.group_name = group_name;
  goal.ik_service_name = ik_service_name;
  goal.pose = pose;
  goal.simulation = simulation;


  RCLCPP_INFO(node->get_logger(),"sending goal");

  auto future = client_ptr->async_send_goal(goal);
  auto res = rclcpp::spin_until_future_complete(node,future);
  RCLCPP_INFO_STREAM(node->get_logger(),"Result: "<<res);
  std::cin.get();

  rclcpp::shutdown();
  return 0;
}

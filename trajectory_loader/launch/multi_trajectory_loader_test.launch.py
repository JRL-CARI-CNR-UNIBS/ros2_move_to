# This Python file uses the following encoding: utf-8
from launch import LaunchDescription, LaunchContext
from launch.actions import ExecuteProcess, OpaqueFunction, DeclareLaunchArgument, RegisterEventHandler
from launch.substitutions import FindExecutable, PathJoinSubstitution, LaunchConfiguration, PythonExpression
from launch.event_handlers import OnProcessExit

from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare
from moveit_configs_utils import MoveItConfigsBuilder

def generate_launch_description():
  
  return LaunchDescription([
    ExecuteProcess(
        cmd = [
          FindExecutable(name="cnr_param_server"),
          "--path-to-file",
          PathJoinSubstitution([
            FindPackageShare("trajectory_loader"),
            "config",
            "multi_trajectory_loader_test_config.yaml"
          ])
        ],
        shell=False
      ),
    
    Node(
      package="trajectory_loader",
      executable="trajectory_loader_test",
      output="screen",
      namespace="kuka_trajectory_loader",
      ros_arguments=["--log-level", "info"],
      remappings=[("/kuka_trajectory_loader/joint_states", "/joint_states")]
    ),
    
    Node(
      package="trajectory_loader",
      executable="trajectory_loader_test",
      output="screen",
      namespace="comau_trajectory_loader",
      ros_arguments=["--log-level", "info"],
      remappings=[("/comau_trajectory_loader/joint_states", "/joint_states")]
    )
])

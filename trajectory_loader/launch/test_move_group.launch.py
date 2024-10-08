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
    Node(
      package="trajectory_loader",
      executable="test_move_group",
      output="screen",
      namespace="",
      ros_arguments=["--log-level", "debug"]
    )
])

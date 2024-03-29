# This Python file uses the following encoding: utf-8
from launch import LaunchDescription, LaunchContext
from launch.actions import ExecuteProcess, OpaqueFunction, DeclareLaunchArgument, RegisterEventHandler
from launch.substitutions import FindExecutable, PathJoinSubstitution, LaunchConfiguration, PythonExpression
from launch.event_handlers import OnProcessExit

from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare
from moveit_configs_utils import MoveItConfigsBuilder

def generate_launch_description():
#  moveit_configs = MoveItConfigsBuilder("nj-220-27").to_moveit_configs()
 return LaunchDescription([
    ExecuteProcess(
        cmd = [
          FindExecutable(name="cnr_param_server"),
          "--path-to-file",
          PathJoinSubstitution([
            FindPackageShare("trajectory_loader"),
            "config",
            "trajectory.yaml"
          ])
        ],
        shell=False
      ),
    
    Node(
      package="trajectory_loader",
      executable="trajectory_loader_server",
      output="screen",
      namespace="kuka_trajectory_loader",
      ros_arguments=["--log-level", "warn"],
      parameters=[{"use_sim_time": True}]
    ),

    Node(
      package="trajectory_loader",
      executable="trajectory_loader_server",
      output="screen",
      namespace="comau_trajectory_loader",
      ros_arguments=["--log-level", "warn"],
      parameters=[{"use_sim_time": True}]
    )
])

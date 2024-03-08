# This Python file uses the following encoding: utf-8
from launch import LaunchDescription, LaunchContext
from launch.actions import ExecuteProcess, OpaqueFunction, DeclareLaunchArgument, RegisterEventHandler
from launch.substitutions import FindExecutable, PathJoinSubstitution, LaunchConfiguration, PythonExpression
from launch.event_handlers import OnProcessExit

from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare

def generate_launch_description():
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

    # moveit_config = (
    #   MoveItConfigsBuilder("moveit_resources_panda")
    #   .robot_description(file_path="config/panda.urdf.xacro")
    #   .trajectory_execution(file_path="config/gripper_moveit_controllers.yaml")
    #   .planning_pipelines("ompl", ["ompl"])
    #   .moveit_cpp(
    #       file_path=os.path.join(
    #           get_package_share_directory("moveit2_tutorials"),
    #           "config",
    #            "moveit_cpp.yaml",
    #       )
    #   )
    #   .to_moveit_configs()
    # )
    
    Node(
      package="trajectory_loader",
      executable="trajectory_loader_server",
      output="screen",
      namespace="trajectory_loader",
      prefix=['gdb -ex=r --args'],
      ros_arguments=["--log-level", "info"],
    )
])
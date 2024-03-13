import rclpy
from rclpy.node import Node
from moveit_msgs.msg import DisplayTrajectory
import yaml
from ament_index_python.packages import get_package_share_directory
import os

class TrajectoryWriter(Node):
    def __init__(self):
        super().__init__('display_path_subscriber')
        self.subscription = self.create_subscription(
            DisplayTrajectory,
            '/display_planned_path',
            self.listener_callback,
            10)        
        
    def listener_callback(self, msg):
        self.get_logger().info('Received planned path, writing to YAML file...')
        directory_path = os.path.expanduser('~/.ros/trajectory_loader_helper')
        os.makedirs(directory_path, exist_ok=True)
        yaml_file_path = os.path.join(directory_path, 'trajectory.yaml')
        # Convert the message to a Python dictionary
        msg_dict = self.message_to_dictionary(msg)
        # Write to a YAML file
        with open(yaml_file_path, 'w') as yaml_file:
            yaml.dump(msg_dict, yaml_file, default_flow_style=None, sort_keys=False)
        self.get_logger().info('Planned path written to %s  ' % yaml_file_path)

    def message_to_dictionary(self, msg):
        # Assuming msg.trajectory is a list and we're interested in the last element
        last_trajectory = msg.trajectory[-1].joint_trajectory

        # Initialize the dictionary
        result_dict = {
            "joint_names": list(last_trajectory.joint_names),
            "time_from_start": [],
            "positions": [],
            "velocities": [],
            "accelerations": [],
            "effort": []
        }

        # Iterate over each point in the last trajectory's points
        for point in last_trajectory.points:
            # Convert time_from_start to seconds (assuming it's a ROS duration object)
            time_secs = point.time_from_start.sec + point.time_from_start.nanosec / 1e9
            result_dict["time_from_start"].append(time_secs)

            # Ensure positions, velocities, and accelerations are converted to lists
            result_dict["positions"].append(list(point.positions) if point.positions else [])
            result_dict["velocities"].append(list(point.velocities) if point.velocities else [])
            result_dict["accelerations"].append(list(point.accelerations) if point.accelerations else [])
            result_dict["effort"].append(list(point.effort) if point.effort else [])


        return result_dict

def main(args=None):
    rclpy.init(args=args)
    display_path_subscriber = TrajectoryWriter()
    rclpy.spin(display_path_subscriber)
    display_path_subscriber.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

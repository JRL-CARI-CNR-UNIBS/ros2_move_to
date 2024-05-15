# Trajectory Loader

**trajectory_loader** is a ROS2 package that provides two main actions for handling robot trajectories:

## Actions

### 1. `TrajectoryLoaderAction`
This action allows you to load and execute a pre-computed trajectory. The action server loads the specified trajectory, identified by name, and sends it to a `FollowJointTrajectory` action server for execution. Trajectories should be stored as parameters using [cnr_param](https://github.com/CNR-STIIMA-IRAS/cnr_param.git).

#### Required Fields
- **`string[] trj_names`**: List of trajectories to execute sequentially.
- **`string fjt_action_name`**: Name of the follow joint trajectory action.
- **`string group_name`**: Name of the robotic group that will execute the trajectories.
- **`int16 scaling`**: Speed scaling factor for each trajectory execution (0 to 100).
- **`string speed_scaling_topic`**: Topic name where the speed scaling is published. The fjt action server listens to this topic to scale the trajectory.
- **`int32 repetitions`**: Number of times the sequence of trajectories is repeated.
- **`bool recompute_time_law`**: If true, the time-law is re-computed based on the list of joint configurations. This also occurs if the trajectory parameter contains only the list of joint configurations.
- **`bool simulation`**: If true, the trajectory is only displayed.

#### Note
If the robot's current configuration does not match the first point of the trajectory, a trajectory is computed with MoveIt to move the robot to the start point.

### 2. `MoveToAction`
This action allows the robot to move to a specified pose. The action server requests an IK (inverse kinematics) solver to compute the joint configurations for the desired pose, selects the one closest to the current configuration, computes the trajectory with MoveIt, and sends it to the `FollowJointTrajectory` action server.

#### Required Fields
- **`string ik_service_name`**: Name of the IK service.
- **`string fjt_action_name`**: Name of the follow joint trajectory action.
- **`string group_name`**: Name of the robotic group that will execute the trajectories.
- **`int16 scaling`**: Speed scaling factor for each trajectory execution (0 to 100).
- **`string speed_scaling_topic`**: Topic name where the speed scaling is published. The fjt action server listens to this topic to scale the trajectory.
- **`geometry_msgs/PoseStamped pose`**: The target pose. Note that the IK solver server configuration defines the reference frame for the robot to reach this pose.
- **`bool simulation`**: If true, the trajectory is only displayed.

## Examples
Check the `launch` folder for examples on how to launch the action servers.

For more details on the actions and parameters, refer to the source code and the included examples.

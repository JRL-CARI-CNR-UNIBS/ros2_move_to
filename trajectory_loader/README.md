# Trajectory Loader

**trajectory_loader** is a ROS2 package that provides three main actions for handling robot trajectories:

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
- **`int16 scaling`**: Speed scaling factor for each trajectory execution (0 to 100). This scaling factor is read by the fjt controller to slowdown thr trajectory execution.
- **`string speed_scaling_topic`**: Topic name where the speed scaling is published. The fjt action server listens to this topic to scale the trajectory.
- **`geometry_msgs/PoseStamped pose`**: The target pose. Note that the IK solver server configuration defines the reference frame for the robot to reach this pose.
- **`bool simulation`**: If true, the trajectory is only displayed.
- **`string pipeline_id`**: E.g., OMPL.
- **`string planner_id`**: E.g., RRT.
- **`float64 acceleration_scaling_factor`**: MoveIt acceleration scaling factor
- **`float64 velocity_scaling_factor`**: MoveIt velocity scaling factor
- **`joints_weights`**: Among all the IK computed, the closest one to the current robot's configuration is chosen. `joints_weights` allows to weight differently each joint on this distance computation.

`acceleration_scaling_factor` and `velocity_scaling_factor` differs from `scaling` because they allows to compute a slower trajectory, while `scaling` slows down a fast trajectory during motion. Furthermore, `scaling` requires a *ad hoc* controller which listens to `speed_scaling_topic` and slows down the trajectory.

### 3. `MoveToConfAction`
This action allows the robot to move to a configuration. The action server computes a trajectory from the current robot configuration to the target one using MoveIt, and sends it to the `FollowJointTrajectory` action server.

#### Required Fields
- **`string[] joints_names`**: Name of the joints for which the target configuration will be specified.
- **`float64[] target_joints_configurations`**: The target configuration for each joint specified in `joints_names`.
- **`string group_name`**: Name of the robotic group that will execute the trajectories.
- **`string fjt_action_name`**: Name of the follow joint trajectory action.
- **`int16 scaling`**: Speed scaling factor for each trajectory execution (0 to 100). This scaling factor is read by the fjt controller to slowdown thr trajectory execution.
- **`string speed_scaling_topic`**: Topic name where the speed scaling is published. The fjt action server listens to this topic to scale the trajectory.
- **`bool simulation`**: If true, the trajectory is only displayed.
- **`string pipeline_id`**: E.g., OMPL.
- **`string planner_id`**: E.g., RRT.
- **`float64 acceleration_scaling_factor`**: MoveIt acceleration scaling factor
- **`float64 velocity_scaling_factor`**: MoveIt velocity scaling factor

`acceleration_scaling_factor` and `velocity_scaling_factor` differs from `scaling` because they allows to compute a slower trajectory, while `scaling` slows down a fast trajectory during motion. Furthermore, `scaling` requires a *ad hoc* controller which listens to `speed_scaling_topic` and slows down the trajectory.

## Examples
Check the `launch` folder for examples on how to launch the action servers.

⚠️ **Please note** that if you launch these nodes using a namespace, you must remap the  `/joint_states` topic as follows:
```py
Node(
    package="trajectory_loader",
    executable="move_to_server",
    output="screen",
    namespace="my_namespace",
    ros_arguments=["--log-level", "info"],
    remappings=[("/my_namespace/joint_states", "/joint_states")] #remapping
    )
```

For more details on the actions and parameters, refer to the source code and the included examples.

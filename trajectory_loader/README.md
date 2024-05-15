**trajectory_loader** is a package which mainly provides two ROS2 actions:
1. `TrajectoryLoaderAction` which allows to load a pre-computed trajectory and to execute it. Basically, the action server loads the required trajectory, identified by name, and sends it to a `FollowJointTrajectory` action server, which is in charge of the trajectory execution. Trajectories must be saved as parameters using [cnr_param](https://github.com/CNR-STIIMA-IRAS/cnr_param.git). The action requires the following fields:
   1. `string[] trj_names`, the list of trajectories to execute sequentially
   2. `string fjt_action_name`, the name of the follow joint trajectory action
   3. `string group_name`, the name of the robotic group whcih will execute the trajectories
   4. `int16 scaling`, the speed scaling factor for the execution of each trajectory (between 0 and 100)
   5. `string speed_scaling_topic`, the name of the topic where the speed scaling needs to be published (the fjt action server needs to listen this topic to scale the trajectory)
   6. `int32 repetitions`, the number of time the sequence of trajectories is repeated
   7. `bool recompute_time_law`, if true, the time-law is re-computed based on the list of joints configurations. This happens also when the trajectory param contains only the list of joints configurations
   8. `bool simulation`, if true the trajectory is only displayed
    
   Note that if the robot current configuration does not match the first point of the trajectory a trajectory is computed with Moveit to move the robot to the start point. 

2. `MoveToAction` which allows the robot to move to a specified pose. Basically, the action server asks an ik solver server to compute the inverse kinematics corresponding to the asked pose, chooses the one closest to the current configuration, asks Moveit to compute the trajectory to that pose and send the compute trajectory to the `FollowJointTrajectory` action server.
The action requires the following fields:
   1. `string ik_service_name`, the name of the ik service
   2. `string fjt_action_name`, the name of the follow joint trajectory action
   3. `string group_name`, the name of the robotic group whcih will execute the trajectories
   4. `int16 scaling`, the speed scaling factor for the execution of each trajectory (between 0 and 100)
   5. `string speed_scaling_topic`, the name of the topic where the speed scaling needs to be published (the fjt action server needs to listen this topic to scale the trajectory)
   6. `geometry_msgs/PoseStamped pose`, the pose to reach. Note that the configuration of the ik solver server defines which is the reference frame of the robot that will reach that pose
   7. `bool simulation`, if true the trajectory is only displayed

Check the `launch` folder for examples on how the action servers can be launched.
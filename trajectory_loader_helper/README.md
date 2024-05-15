### Trajectory Loader Helper

The **trajectory_loader_helper** is an utility script designed to save computed trajectories into a YAML file. This tool is especially useful for storing trajectories that will later be executed using the `TrajectoryLoaderAction`.

#### Usage:
The script automatically listens to the topic `/display_planned_path` and writes the received trajectories to `~/.ros/trajectory_loader_helper`. This allows for easy saving and later retrieval of planned paths for execution.

### ros2_move_to

**ros2_move_to** comprises two packages designed for executing both pre-computed and new trajectories. For detailed information on each package, refer to their respective README files:

- [Trajectory Loader](https://github.com/JRL-CARI-CNR-UNIBS/ros2_move_to/blob/master/trajectory_loader/README.md)
- [Trajectory Loader Helper](https://github.com/JRL-CARI-CNR-UNIBS/ros2_move_to/blob/master/trajectory_loader_helper/README.md)

## Install
Download `ros2_move_to`
```bash
cd your/ws/path/src
git clone https://github.com/JRL-CARI-CNR-UNIBS/ros2_move_to
```
 
 Download dependencies using vcstool
 ```bash
 sudo apt-get install python3-vcstool #or sudo pip install vcstool
 cd ..
 vcs import < src/ros2_move_to/deps.repos
 ```

 Build the ws
 ```bash
 colcon build --symlink-install
 ```

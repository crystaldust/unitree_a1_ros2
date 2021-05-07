# Unitree A1 ROS2 Driver
The UNOFFICIAL ROS2 driver for Unitree robotics dog A1



## Setting up

#### Workspace setup
Please make sure you have the following checked out in your colcon workspace together:
- https://github.com/huawei-ros/unitree_legged_sdk
- https://github.com/lcm-proj/lcm
- http://github.com/crystaldust/unitree_a1_ros2.git

Once the two former packages are released upstream, `rosdep install` should be sufficient to pull in dependencies.

## Unitree A1 high level state support list

The Unitree SDK define a "HighState" to present the high level control of the robotics dog, there are still some constraints of the driver because some features are missing from the SDK([unitree_legged_sdk](https://github.com/unitreerobotics/unitree_legged_sdk))

| HighState         | Explanation                                                  | Supported or not                                             |
| ----------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| levelFlag         | High level or low level flag,"0x00" for high level,"0xff" for low level | Supported                                                    |
| mode              | Robot mode, "1" for stand mode, "2" for walk mode            | Setting mode is supported, while accessing the mode is not   |
| imu               | Quaternion、angular velocity、accelerometer、temperature     | Partially supported(temperature under sport mode is not accessible) |
| forwardSpeed      | Walk forward speed                                           | Supported                                                    |
| sideSpeed         | The speed of lateral walk                                    | Supported                                                    |
| rotateSpeed       | Rotate speed                                                 | Supported                                                    |
| bodyHeight        | Current body height                                          | Supported                                                    |
| updownSpeed       | Standing or squatting speed                                  | Supported                                                    |
| forwardPosition   | front or rear displacement(?)                                | Supported                                                    |
| sidePosition      | left or right displacement(?)                                | Supported                                                    |
| footPosition2Body | Position of the feet relative to the body                    | Supported                                                    |
| footSpeed2Body    | Foot speed relative to the body                              | Supported                                                    |
| footForce         | The force on the foot                                        | Supported                                                    |
| wirelessRemote    | Wireless command                                             | Supported                                                    |
| crc               | Checksum                                                     | Supported                                                    |

### Comment:
1.Setting sport mode is not supported through calling unitree sdk.

2.In normal mode, the robot dog will drift when stepping, It's best to develop in sport mode.

3.Getting temperature in sport mode is not supported.

4.Getting the current mode of the robot dog is not supported.

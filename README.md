# unitree_a1_ros2
The UNOFFICIAL ROS2 driver for Unitree robotics dog A1
## Unitree A1 high level status support
|    HighState    |                          Explanation                          |Support or not|
|-----------------|---------------------------------------------------------------|--------------|
|levelFlag        |High level or low level flag,"0x00":high level,"0xff":low level|     Support  |
|   mode          |Robot currently mode, "1":stand mode, "2":walk mode            |   Not Support|
|   imu           |Quaternion、angular velocity、accelerometer、temperture         |     Support  |
|forwardSpeed     |Walk forward speed                                             |     Support  |
| sideSpeed       |The speed of lateral walk                                      |     Support  |
|rotateSpeed      |Rotate speed                                                   |     Support  |
| bodyHeight      |Current body height                                            |     Support  |
|updownSpeed      |Standing or squatting speed                                    |     Support  |
|forwardPosition  |Target position in front of your                               |     Support  |
| sidePosition    |Target position in side of your body                           |     Support  |
|footPosition2Body|Position of the feet relative to the body                      |     Support  |
|footSpeed2Body   |Foot speed relative to the body                                |     Support  |
|footForce        |The force on the foot                                          |     Support  |
|wirelessREmote   |Wireless command                                               |     Support  |
|crc              |Checksum                                                       |     Support  |

### Comment:  
1.Setting sport mode is not supported through call unitree sdk.  
2.In normal mode, the robot dog will drift when stepping, It's best to develop in sport mode.  
3.Getting temperature in sport mode is not supported.  
4.Getting the current mode of the robot dog is not supported.  

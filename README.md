# Unitree A1 ROS2 Driver
The UNOFFICIAL ROS2 driver for Unitree robotics dog A1



## Setting up

#### Setup the unitree legged SDK
- Get the SDK's headers and libs at [unitree_legged_sdk](https://github.com/unitreerobotics/unitree_legged_sdk), let's assume you put it to `/home/yourname/unitree_legged_sdk`
- Set the environment variables(bash as an example):
```bash
# Put the scripts to .bashrc to take effect every time a new shell session is started
export UNITREE_LEGGED_SDK_PATH=/home/yourname/unitree_legged_sdk
export UNITREE_PLATFORM=arm64 # Or 'amd64' if you run the code on a x86 architecure
```

#### Install lcm
[LCM](https://github.com/lcm-proj/lcm) is a messaging tool that unitree SDK relies on for real time messaging. While ROS2 natively support real-time messaging based on DDS. So LCM is actually not needed for the ROS2 driver. But the unitree SDK's lib files are complied to link the LCM library, so we have to provide the lib files to make the driver run.
To install LCM, just download the code at https://github.com/lcm-proj/lcm, and follow the general cmake project compilation steps:
```bash
$ git clone https://github.com/lcm-proj/lcm
$ mkdir lcm/build
$ cd lcm/build
$ cmake cmake -DCMAKE_INSTALL_PREFIX:PATH=/usr ../ # by default, cmake set the prefix to /usr/local, where on some distributions is not obtained by default.
$ make # add -jN to enable multi core compiling
$ sudo make install
```

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

5.If you want to set low command, hang the unitree A1 dog.

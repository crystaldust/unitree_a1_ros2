cmake_minimum_required(VERSION 3.5)
project(unitree_legged_msgs)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

cmake_minimum_required(VERSION 3.5)
project(unitree_legged_msgs)

#-----------------------delete------------------------------
set(FastRTPS_INCLUDE_DIR /opt/ros/foxy/include)
set(FastRTPS_LIBRARY_RELEASE /opt/ros/foxy/lib/libfastrtps.so)
#-----------------------delete------------------------------

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(builtin_interfaces REQUIRED)
find_package(rosidl_default_generators REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
        "msg/HighCmd.msg"
        "msg/Cartesian.msg"
        "msg/HighState.msg"
        "msg/IMU.msg"
        "msg/LED.msg"
        "msg/LowCmd.msg"
        "msg/LowState.msg"
        "msg/MotorCmd.msg"
        "msg/MotorState.msg"
        "msg/Walk.msg"
        DEPENDENCIES builtin_interfaces
)


ament_package()

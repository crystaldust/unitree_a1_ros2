cmake_minimum_required(VERSION 3.5)
project(a1_msgs)

find_package(ament_cmake REQUIRED)

find_package(rosidl_default_generators REQUIRED)

rosidl_generate_interfaces(
  ${PROJECT_NAME}
  "msg/Cartesian.msg"
  "msg/IMU.msg"
  "msg/MotorState.msg"
  "msg/Pose.msg"
  "srv/Cartesian.srv"
  "srv/HighState.srv"
  "srv/Imu.srv"
  "srv/Mode.srv"
  "srv/State.srv")

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()

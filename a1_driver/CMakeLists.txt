cmake_minimum_required(VERSION 3.5)
project(unitree_legged_real)

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

# find dependencies
find_package(ament_cmake REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

find_package(rclcpp REQUIRED)
find_package(unitree_legged_msgs REQUIRED)
find_package(Eigen3 REQUIRED)

#target_include_directories(my_target
#  PUBLIC
#    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
#    $<INSTALL_INTERFACE:include>)

##########################
#export ROS_PACKAGE_PATH=/root/ros2_ws_b:${ROS_PACKAGE_PATH}
#export GAZEBO_PLUGIN_PATH=~/catkin_ws/devel/lib:${GAZEBO_PLUGIN_PATH}
#export LD_LIBRARY_PATH=/rootunitree_legged_sdk/lib:${LD_LIBRARY_PATH}
#export UNITREE_LEGGED_SDK_PATH=/root/unitree_legged_sdk
#export UNITREE_PLATFORM="arm64"
#######################
include_directories(
    include
    ${Boost_INCLUDE_DIR}
    ${colcon_INCLUDE_DIRS}
    ${EIGEN3_INCLUDE_DIR}
    $ENV{UNITREE_LEGGED_SDK_PATH}/include
)
#include_directories(include ${colcon_INCLUDE_DIRS})
link_directories($ENV{UNITREE_LEGGED_SDK_PATH}/lib)
string(CONCAT LEGGED_SDK_NAME libunitree_legged_sdk_$ENV{UNITREE_PLATFORM}.so)
set(EXTRA_LIBS ${LEGGED_SDK_NAME} lcm)

set(CMAKE_CXX_FLAGS "-O3")

find_package(unitree_legged_msgs REQUIRED)
add_executable(walk_operator src/exe/walk_operators.cpp)
target_link_libraries(walk_operator ${EXTRA_LIBS} ${catkin_LIBRARIES})
ament_target_dependencies(walk_operator rclcpp ${${PEOJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS} unitree_legged_msgs)
install(TARGETS
  walk_operator
  DESTINATION lib/${PROJECT_NAME})

add_executable(simple_pub src/exe/simple_pub.cpp)
target_link_libraries(simple_pub ${EXTRA_LIBS} ${catkin_LIBRARIES})
ament_target_dependencies(simple_pub rclcpp ${${PEOJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS} unitree_legged_msgs)
install(TARGETS
  simple_pub
  DESTINATION lib/${PROJECT_NAME})

add_executable(setup_udp src/exe/setup_udp.cpp)
target_link_libraries(setup_udp ${EXTRA_LIBS} ${colcon_LIBRARIES})
ament_target_dependencies(setup_udp rclcpp ${${PEOJECT_NAME}_EXPORTED_TARGETS} ${colcon_EXPORTED_TARGETS})
install(TARGETS
  setup_udp
  DESTINATION lib/${PROJECT_NAME})


#add_executable(send_msg src/exe/send_msg.cpp)
#target_link_libraries(send_msg ${EXTRA_LIBS} ${catkin_LIBRARIES})
#ament_target_dependencies(send_msg ${${PEOJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

#add_executable(lcm_server_3_2 $ENV{UNITREE_LEGGED_SDK_PATH}/examples/lcm_server.cpp)
#target_link_libraries(lcm_server_3_2 ${EXTRA_LIBS} ${catkin_LIBRARIES})
#ament_target_dependencies(lcm_server_3_2 ${${PEOJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
ament_package()

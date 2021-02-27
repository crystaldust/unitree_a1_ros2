cmake_minimum_required(VERSION 3.5)
project(unitree_driver)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

#-----------------------delete------------------------------
set(FastRTPS_INCLUDE_DIR /opt/ros/foxy/include)
set(FastRTPS_LIBRARY_RELEASE /opt/ros/foxy/lib/libfastrtps.so)
#-----------------------delete------------------------------

find_package(ament_cmake REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(rclcpp REQUIRED)

set(dependencies
		rclcpp
		geometry_msgs
		)

include_directories(
		include
		$ENV{UNITREE_LEGGED_SDK_PATH}/include
)

link_directories($ENV{UNITREE_LEGGED_SDK_PATH}/lib)
string(CONCAT LEGGED_SDK_NAME libunitree_legged_sdk_$ENV{UNITREE_PLATFORM}.so)
set(EXTRA_LIBS ${LEGGED_SDK_NAME} lcm)

add_executable(unitree_ros src/unitree_ros.cpp
							src/unitree_wrapper.cpp
							include/unitree_driver/unitree_wrapper.h)
ament_target_dependencies(unitree_ros
		${dependencies}
		)
target_link_libraries(unitree_ros
		${EXTRA_LIBS}
		)

add_executable(msg_pub src/msg_pub.cpp)
ament_target_dependencies(msg_pub
		${dependencies}
		)

ament_export_include_directories(include)
ament_export_dependencies(${dependencies})

install(TARGETS
        unitree_ros
		msg_pub
        DESTINATION lib/${PROJECT_NAME}
)

ament_package()


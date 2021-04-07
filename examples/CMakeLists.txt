cmake_minimum_required(VERSION 3.5)
project(a1_example)

# Default to C++14
if (NOT CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 14)
endif ()

if (CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
endif ()

find_package(ament_cmake REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(rclcpp REQUIRED)
find_package(a1_msgs REQUIRED)
set(dependencies
        rclcpp
        geometry_msgs
        )

include_directories(
        include
        $ENV{A1_COMM_PATH}/include
)

#pub velocity msg
add_executable(pub_vel_msg src/pub_vel_msg.cpp)
ament_target_dependencies(pub_vel_msg ${dependencies} a1_msgs)
#pub pose msg
add_executable(pub_pose_msg src/pub_pose_msg.cpp)
ament_target_dependencies(pub_pose_msg ${dependencies} a1_msgs)
#client get imu info
add_executable(client_get_imu src/client_get_imu_msg.cpp)
ament_target_dependencies(client_get_imu ${dependencies} a1_msgs)
#client get high state info
add_executable(client_get_state src/client_get_state.cpp)
ament_target_dependencies(client_get_state ${dependencies} a1_msgs)
#client get Cartesian info
add_executable(client_get_cartesian src/client_get_cartesian_msg.cpp)
ament_target_dependencies(client_get_cartesian ${dependencies} a1_msgs)
#client set mode
add_executable(client_set_mode src/client_set_mode.cpp)
ament_target_dependencies(client_set_mode ${dependencies} a1_msgs)
ament_export_include_directories(include)
ament_export_dependencies(${dependencies})

install(TARGETS
        pub_vel_msg
		pub_pose_msg
		client_get_imu
		client_get_state
		client_set_mode
		client_get_cartesian
        DESTINATION lib/${PROJECT_NAME}
        )

ament_package()


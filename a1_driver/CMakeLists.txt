cmake_minimum_required(VERSION 3.5)
project(a1_driver)

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
        $ENV{UNITREE_LEGGED_SDK_PATH}/include
)

link_directories($ENV{UNITREE_LEGGED_SDK_PATH}/lib)
string(CONCAT LEGGED_SDK_NAME libunitree_legged_sdk_$ENV{UNITREE_PLATFORM}.so)
set(EXTRA_LIBS ${LEGGED_SDK_NAME} lcm)

add_executable(a1_main src/main.cpp
        src/A1_ros.cpp
        include/a1_driver/A1_ros.h
        src/A1_wrapper.cpp
        include/a1_driver/A1_wrapper.h
		include/comm/comm_ros.h)
ament_target_dependencies(a1_main ${dependencies} a1_msgs)
target_link_libraries(a1_main ${EXTRA_LIBS})
#---------------------------------------------------------
#pub velocity msg
add_executable(pub_vel_msg examples/pub_vel_msg.cpp
			   include/comm/comm_ros.h)
ament_target_dependencies(pub_vel_msg ${dependencies} a1_msgs)
#pub pose msg
add_executable(pub_pose_msg examples/pub_pose_msg.cpp
			   include/comm/comm_ros.h)
ament_target_dependencies(pub_pose_msg ${dependencies} a1_msgs)
#client get imu info
add_executable(client_get_imu examples/client_get_imu_msg.cpp
			   include/comm/comm_ros.h)
ament_target_dependencies(client_get_imu ${dependencies} a1_msgs)

#client get high state info
add_executable(client_get_state examples/client_get_state.cpp
			   include/comm/comm_ros.h)
ament_target_dependencies(client_get_state ${dependencies} a1_msgs)

#client set mode
add_executable(client_set_mode examples/client_set_mode.cpp
			   include/comm/comm_ros.h)
ament_target_dependencies(client_set_mode ${dependencies} a1_msgs)
#------------------------------------------------------------
ament_export_include_directories(include)
ament_export_dependencies(${dependencies})

install(TARGETS
        a1_main
        pub_vel_msg
		pub_pose_msg
		client_get_imu
		client_get_state
		client_set_mode
        DESTINATION lib/${PROJECT_NAME}
        )

ament_package()


cmake_minimum_required(VERSION 3.5)
project(unitree_driver)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(tf2 REQUIRED)
find_package(rclcpp REQUIRED)
find_package(Eigen3 REQUIRED)

set(dependencies
        rclcpp
        tf2
        geometry_msgs
        )

include_directories(
        include
        ${Boost_INCLUDE_DIR}
        $ENV{UNITREE_LEGGED_SDK_PATH}/include
)

link_directories($ENV{UNITREE_LEGGED_SDK_PATH}/lib)
string(CONCAT LEGGED_SDK_NAME libunitree_legged_sdk_$ENV{UNITREE_PLATFORM}.so)
set(EXTRA_LIBS ${LEGGED_SDK_NAME} lcm)


add_library(unitree_wrapper SHARED
			src/unitree_wrapper.cpp 
			include/unitree_driver/unitree_wrapper.h)

ament_target_dependencies(unitree_wrapper
        ${dependencies}
        )
target_link_libraries(unitree_wrapper
        ${EXTRA_LIBS}
        )

add_executable(unitree_ros src/unitree_ros.cpp)
ament_target_dependencies(unitree_ros
		${dependencies}
		)
target_link_libraries(unitree_ros
		${EXTRA_LIBS}
		unitree_wrapper
		)
ament_export_targets(export_unitree_wrapper HAS_LIBRARY_TARGET)
install(
  DIRECTORY include/
  DESTINATION include
)
install(
  TARGETS unitree_wrapper
  EXPORT export_unitree_wrapper
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES DESTINATION include
)



add_executable(msg_pub src/msg_pub.cpp)
ament_target_dependencies(msg_pub
		${dependencies}
		)

ament_export_include_directories(include)
ament_export_dependencies(${dependencies})

install(TARGETS
        unitree_ros
		unitree_wrapper
		msg_pub
        DESTINATION lib/${PROJECT_NAME}
)

ament_package()


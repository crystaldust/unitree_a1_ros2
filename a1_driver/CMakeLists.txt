cmake_minimum_required(VERSION 3.5)
project(a1_driver)

find_package(a1_msgs REQUIRED)
find_package(ament_cmake REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(rclcpp REQUIRED)
find_package(unitree_legged_sdk REQUIRED)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(dependencies
    a1_msgs
    geometry_msgs
    rclcpp
    unitree_legged_sdk
)

include_directories(
    include
)

add_definitions(-DSPORT_MODE)

add_library(a1_ros
    src/A1_ros.cpp
    src/A1_wrapper.cpp
)

ament_target_dependencies(a1_ros
  ${dependencies}
)

# ament_export_dependencies(lcm) triggers the equivalent of find_package(lcm) here, however
# this doesn't seem to populate the expected CMake variables.
target_link_libraries(a1_ros
    lcm
)

add_executable(${PROJECT_NAME}
    src/main.cpp
)

target_link_libraries(${PROJECT_NAME} a1_ros)

install(TARGETS a1_ros ${PROJECT_NAME}
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY include/
  DESTINATION include/
)

if(BUILD_TESTING)
    find_package(ament_lint_auto REQUIRED)
    ament_lint_auto_find_test_dependencies()
endif()

# TODO(pbovbel) add component
# rclcpp_components_register_nodes(a1_ros "${PROJECT_NAME}::A1Driver")

ament_export_include_directories(include)
ament_export_libraries(a1_ros)
ament_export_dependencies(${dependencies})
ament_package()

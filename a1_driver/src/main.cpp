//
// Created by sun on 2021/3/1.
//

#include "a1_driver/A1_ros.h"
#include "a1_driver/A1_wrapper.h"

int main(int argc, char *argv[]) {
    std::string node_name = "A1_node";
    std::string arg_mode;
    if (argc != 2) {
        std::cerr << "Usage:" << std::endl;
        std::cerr << "[BASIC_MODE]: ros2 run a1_driver a1_main basic" << std::endl;
        std::cerr << "[SPORT_MODE]: ros2 run a1_driver a1_main sport" << std::endl;
        return -1;
    }
    arg_mode = argv[1];
    if (arg_mode == "sport") {
        A1ROS a1_ros = A1ROS(node_name, STARTUP_SPORT_MODE);
        std::cout << "[SPORT_MODE]:creating a node named :" << node_name << std::endl;
        a1_ros.node_init(argc, argv);
    } else if (arg_mode == "basic") {
        A1ROS a1_ros = A1ROS(node_name);
        std::cout << "[BASIC_MODE]:creating a node named :" << node_name << std::endl;
        a1_ros.node_init(argc, argv);
    } else {
        std::cerr << "Usage:" << std::endl;
        std::cerr << "[BASIC_MODE]: ros2 run a1_driver a1_main basic" << std::endl;
        std::cerr << "[SPORT_MODE]: ros2 run a1_driver a1_main sport" << std::endl;
    }
    return 0;
}

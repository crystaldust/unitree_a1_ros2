//
// Created by sun on 2021/3/1.
//

#include "a1_driver/A1_ros.h"
#include "a1_driver/A1_wrapper.h"
#define STARTUP_SPORT_MODE 1
int main(int argc, char *argv[]) {
    std::string node_name = "A1_node";
    std::string arg;
    if (argc < 3) {
        std::cerr << "running ros2 run a1_driver a1_main --node-name A1_node" << std::endl;
    }
    for (int i = 1; i < argc; ++i) {
        arg = argv[i];
        if (arg == "--node-name") {
            node_name = argv[i + 1];
        }
    }
    if (arg == "sport") {
        A1ROS a1_ros = A1ROS(node_name, STARTUP_SPORT_MODE);
        std::cout << "[SPORT_MODE]:creating a node named :" << node_name << std::endl;
        a1_ros.node_init(argc, argv);
    } else {
        A1ROS a1_ros = A1ROS(node_name);
        std::cout << "[BASIC_MODE]:creating a node named :" << node_name << std::endl;
        a1_ros.node_init(argc, argv);
    }
    return 0;
}

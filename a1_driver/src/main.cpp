//
// Created by sun on 2021/3/1.
//

#include "unitree_a1_ros2/A1_ros.h"
#include "unitree_a1_ros2/A1_wrapper.h"

int main(int argc, char* argv[]){
    rclcpp::init(argc, argv);
    std::string node_name = "A1_node";
    if (argc < 3 ){
        std::cerr << "running ros2 run unitree_a1_ros2 a1_main --node-name A1_node" << std::endl;
    }
    for (int i =1; i < argc ; ++i) {
        std::string arg = argv[i];
        if (arg == "--node-name") {
            node_name = argv[i+1];
        }
    }

    A1ROS a1_ros = A1ROS(node_name);
    std::cout << "creating a node named :" << node_name << std::endl;
    a1_ros.node_init(argc, argv);

    return 0;
}

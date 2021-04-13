//
// Created by sun on 2021/3/1.
//
#include "a1_driver/A1_ros.h"
#include "a1_driver/A1_wrapper.h"
#include <iostream>
#include <unistd.h>
#include <getopt.h>
#include <iomanip>

using namespace std;

void print_help() {
    std::cout <<
    "Usage:" << endl <<
    std::left << std::setw(20) << "--node_name -n:" << "Name of the serving ROS node, 'a1_node' by default" << endl <<
    std::left << std::setw(20) << "--mode -m:" << "Mode of A1 dog, sports(default) or basic" << endl <<
    "Example:" << endl <<
    "PATH_TO_CMD -m sports" << endl <<
    "PATH_TO_CMD --mode sports --node_name my_a1_node" << endl;
}

const char *get_arg(char *argv[]) {
    if (optarg != nullptr) {
        return optarg;
    }
    if (argv[optind] != nullptr) {
        return argv[optind];
    }

    print_help();
    exit(1);
}
// works: ./cmd --mode sports
// works: ./cmd --mode=sports
bool parse_commandline(int argc, char *argv[], std::string &node_name, std::string &mode) {
    const char *short_options = "m::n::";
    const option long_options[] = {
        {"mode", optional_argument, nullptr, 'm'},
        {"node_name", optional_argument, nullptr, 'n'},
        {0, 0 ,0 ,0}
    };

    int opt;
    while ((opt = getopt_long(argc, argv, short_options, long_options, nullptr)) != -1) {
        switch (opt) {
            case 'm':
                mode = std::string(get_arg(argv));
                break;
            case 'n':
                node_name = std::string(get_arg(argv));
                break;
            default:
                return false;
        }
    }
    cout << "running node [" << node_name << "] in {" << mode << "} mode" << endl;
    return true;
}

int main(int argc, char *argv[]) {
    std::string node_name = "a1_node";
    std::string arg_mode = "sports";
    //  Parse the commandline arguments
    if (false == parse_commandline(argc, argv, node_name, arg_mode)) {
        print_help();
        return -1;
    }
    
    if (arg_mode == "sports") {
        A1ROS a1_ros = A1ROS(node_name, STARTUP_SPORT_MODE);
        cout << "[SPORT_MODE]:creating a node named :" << node_name << endl;
        a1_ros.node_init(argc, argv);
    } else if (arg_mode == "basic") {
        A1ROS a1_ros = A1ROS(node_name);
        cout << "[BASIC_MODE]:creating a node named :" << node_name << endl;
        a1_ros.node_init(argc, argv);
    } else {
        print_help();
        return -1;
    }
    
    return 0;
}

// Copyright 2015 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <getopt.h>
#include <unistd.h>
#include <iomanip>
#include <iostream>
#include <string>
#include "a1_driver/A1_ros.hpp"
#include "a1_driver/A1_wrapper.hpp"

using std::cout;
using std::endl;


void print_help()
{
  std::cout << "Usage:" << endl <<
    std::left << std::setw(20) << "--node_name -n:" <<
    "Name of the serving ROS node, 'a1_node' by default" << endl <<
    std::left << std::setw(20) << "--mode -m:" <<
    "Mode of A1 dog, sports(default) or basic" << endl <<
    std::left << std::setw(20) << "--level -l:" <<
    "Level of A1 dog, high level(default) or low level" << endl <<
    "Example:" << endl <<
    "PATH_TO_CMD -m sports" << endl <<
    "PATH_TO_CMD --mode sports --node_name my_a1_node --level high" << endl;
}

const char * get_arg(char * argv[])
{
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
bool parse_commandline(
  int argc, char * argv[], std::string & node_name,
  std::string & mode, std::string & level)
{
  const char * short_options = "m::n::l";
  const option long_options[] = {{"mode", optional_argument, nullptr, 'm'},
    {"node_name", optional_argument, nullptr, 'n'},
    {"level", optional_argument, nullptr, 'l'},
    {0, 0, 0, 0}};

  int opt;
  while ((opt = getopt_long(
      argc, argv, short_options, long_options,
      nullptr)) != -1)
  {
    switch (opt) {
      case 'm':
        mode = std::string(get_arg(argv));
        break;
      case 'n':
        node_name = std::string(get_arg(argv));
        break;
      case 'l':
        level = std::string(get_arg(argv));
        break;
      default:
        return false;
    }
  }
  cout << "running node [" << node_name << "] in {" << mode << "} mode" <<
    " {" << level << "} level" << endl;
  return true;
}

int main(int argc, char * argv[])
{
  std::string node_name = "a1_node";
  std::string arg_mode = "sports";
  std::string arg_level = "high";
  //  Parse the commandline arguments
  if (false == parse_commandline(argc, argv, node_name, arg_mode, arg_level)) {
    print_help();
    return -1;
  }
  int level;
  if (arg_level == "high") {
    level = HIGH_LEVEL;
  } else if (arg_level == "low") {
    level = LOW_LEVEL;
  } else {
    print_help();
    return -1;
  }

  if (arg_mode == "sports") {
    A1ROS a1_ros = A1ROS(node_name, STARTUP_SPORT_MODE, level);
    cout << "[SPORT_MODE]:creating a node named :" << node_name << endl;
    a1_ros.node_init(argc, argv);
  } else if (arg_mode == "basic") {
    A1ROS a1_ros = A1ROS(node_name, level);
    cout << "[BASIC_MODE]:creating a node named :" << node_name << endl;
    a1_ros.node_init(argc, argv);
  } else {
    print_help();
    return -1;
  }
  return 0;
}

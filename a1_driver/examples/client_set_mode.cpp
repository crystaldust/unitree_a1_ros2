#include <memory>
#include <chrono>
#include <unistd.h>
#include "rclcpp/rclcpp.hpp"
#include "comm/comm_ros.h"

using namespace std::chrono_literals;

class ClientNode : public rclcpp::Node {
public:
    ClientNode(uint8_t mode) : Node("SetMode"), count_(5) {
        set_mode = mode;
        client = this->create_client<a1_msgs::srv::Mode>(ROS2_TOPIC_SET_MODE);
        timer_c = this->create_wall_timer(500ms, std::bind(&ClientNode::client_set_mode, this));
    }
private:
    void client_set_mode();
    rclcpp::TimerBase::SharedPtr timer_c;
    rclcpp::Client<a1_msgs::srv::Mode>::SharedPtr client;
    uint8_t set_mode;
    size_t count_;
};

void ClientNode::client_set_mode() {
    int times = 0;
    auto request = std::make_shared<a1_msgs::srv::Mode::Request>();
    while (!client->wait_for_service(1s)) {
        times++;
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "service not available, waiting times(%d)...", times);
        if (count_ == times)
            return;
    }
    request->mode = set_mode;
    auto result = client->async_send_request(request);
    // Wait for the result.
    if (rclcpp::spin_until_future_complete(node, result) ==
        rclcpp::executor::FutureReturnCode::SUCCESS)
    {
        auto cmd = result.get();
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "service return value : %d", cmd->value);
    } 
    else {
        RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Failed to call service");
    }
    
    return;
}


int main(int argc, char *argv[]) {
    uint8_t mode;
    rclcpp::init(argc, argv);
    if (argv[1] == NULL || (atoi(argv[1]) < 0 || atoi(argv[1]) > 2))
    {
        RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Failed to call service");
        return -1;
    }
    mode = atoi(argv[1]);
    auto node = std::make_shared<ClientNode>(mode);
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}


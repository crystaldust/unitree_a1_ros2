#include <memory>
#include <chrono>
#include <unistd.h>
#include "rclcpp/rclcpp.hpp"
#include "a1_comm/A1_comm.h"

using namespace std::chrono_literals;
class ClientNode 
{
public:
    ClientNode(uint8_t mode) :count_(5) {
        set_mode = mode;
        node = rclcpp::Node::make_shared("server_client");
        client = node->create_client<a1_msgs::srv::Mode>(ROS2_SERVICE_SET_MODE);
    }
    void client_set_mode();
private:
    rclcpp::TimerBase::SharedPtr timer_c;
    rclcpp::Client<a1_msgs::srv::Mode>::SharedPtr client;
    std::shared_ptr<rclcpp::Node> node;
    uint8_t set_mode;
    size_t count_;
};

void ClientNode::client_set_mode() {
    size_t times = 0;
     
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
        RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Invalid number of input parameters.");
        return -1;
    }
    mode = atoi(argv[1]);
    ClientNode client(mode);
    //rclcpp::WallRate loop_rate(10.0);
    //while (rclcpp::ok())
    {
        client.client_set_mode();
    //    loop_rate.sleep();
    }
    
    rclcpp::shutdown();
    return 0;
}

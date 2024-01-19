#include "ros/ros.h"
#include "bev_package/Pesan.h"
#include <iomanip>

void callbackHandler(const bev_package::Pesan::ConstPtr &msg) {
    ROS_INFO("\033[32m\n Informasi Kehadiran: \n\033[0m");
    ROS_INFO("\033[34mUsia: %ld\n\033[0m", msg->usia);
    ROS_INFO("\033[34mTinggi: %.2f\n\033[0m", msg->tinggi);
    ROS_INFO("\033[34mNama: %s\n\033[0m", msg->nama.c_str());
    ROS_INFO("\033[34mKehadiran: %s\n\033[0m", msg->kehadiran ? "\033[32mHadir\033[0m" : "\033[31mTidak Hadir\033[0m");
}

int main(int argc, char**argv) {
    ros::init(argc, argv,"simple_subscriber_node");
    
    ros::NodeHandle nh;

    ros::Subscriber data_subscriber = nh.subscribe("topik_utama",1000,callbackHandler);

    ros::spin();
    
    return 0;
}

#include "ros/ros.h"
#include "bev_package/Pesan.h"

int main(int argcm, char**argv) {
    ros::init(argcm, argv,"simple_publisher_node");

    ros::NodeHandle nh;

    ros::Publisher data_publisher = nh.advertise<bev_package::Pesan>("topik_utama",1000);

    ros::Rate loop_rate(1);

    while(ros::ok()) {
        bev_package::Pesan dataVariabel;

        dataVariabel.usia = 18;
        dataVariabel.tinggi = 163.0;
        dataVariabel.nama = "Bevinda Vivian";
        dataVariabel.kehadiran = true;

        ROS_INFO("\nUsia: %ld\nTinggi: %lf\nNama: %s\nKehadiran: %s",dataVariabel.usia, dataVariabel.tinggi, dataVariabel.nama.c_str(), dataVariabel.kehadiran ? "true" : "false");

        data_publisher.publish(dataVariabel);

        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}

#include "ros/ros.h"
#include "bev_package/service.h"

bool magnitude_formula(bev_package::service::Request &req, bev_package::service::Response &res){
  double magnitude = sqrt(pow(req.komponenX, 2) + pow(req.komponenY, 2) + pow(req.komponenZ, 2));
  ROS_INFO("Nilai magnitude: %f", magnitude);
  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "service_server");
  ros::NodeHandle nh;
  ros::ServiceServer service = nh.advertiseService("service", magnitude_formula);

  ROS_INFO("Service siap dijalankan.");

  ros::spin();

  return 0;
}

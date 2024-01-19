#include "ros/ros.h"
#include "bev_package/service.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "service_client");

  ros::NodeHandle nh;

  ros::ServiceClient client = nh.serviceClient<bev_package::service>("service");

  bev_package::service::Request req;
  req.komponenX = 2.0;
  req.komponenY = 3.0;
  req.komponenZ = 6.0;

  bev_package::service::Response res;
  if (client.call(req, res))
  {
    ROS_INFO("Nilai magnitudenya adalah %f", res.magnitude);
  }
  else  {
    ROS_ERROR("Gagal untuk memanggil service.");
    return 1;
  }

  return 0;
}

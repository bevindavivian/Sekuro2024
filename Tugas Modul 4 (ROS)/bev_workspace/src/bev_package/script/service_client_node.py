import rospy
from bev_package.srv import service, serviceResponse

def magnitude_formula(req):
    magnitude = (req.komponenX ** 2 + req.komponenY ** 2 + req.komponenZ ** 2) ** 0.5
    rospy.loginfo("Nilai magnitudenya adalah %f", magnitude)
    return serviceResponse(magnitude)

if __name__ == '__main__':
    rospy.init_node('service_client')
    rospy.wait_for_service('service')
    try:
        client = rospy.ServiceProxy('service', service)
        req = serviceRequest()
        req.komponenX = 2.0
        req.komponenY = 3.0
        req.komponenZ = 6.0
        res = client(req)
        rospy.loginfo("Nilai magnitudenya adalah %f", res.magnitude)
    except rospy.ServiceException as e:
        rospy.loginfo("Gagal untuk memanggil service: %s", e)


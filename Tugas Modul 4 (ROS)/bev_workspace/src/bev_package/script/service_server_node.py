import rospy
from bev_package.srv import service, serviceResponse

def magnitude_formula(req):
    magnitude = (req.komponenX ** 2 + req.komponenY ** 2 + req.komponenZ ** 2) ** 0.5
    rospy.loginfo("Nilai magnitude: %f", magnitude)
    return serviceResponse(magnitude)

if __name__ == '__main__':
    rospy.init_node('service_server')
    service = rospy.Service('service', service, magnitude_formula)
    rospy.loginfo("Service siap dijalankan.")
    rospy.spin()


import rospy
from bev_package.msg import Pesan

def callbackHandler(msg):
    rospy.loginfo("\nUsia: %d\nTinggi: %lf\nNama: %s\nKehadiran: %s",msg.usia, msg.tinggi, msg.nama, "true" if msg.kehadiran else "false")

if __name__ == '__main__':
    rospy.init_node('simple_publisher_node', anonymous=True)
    data_publisher = rospy.Publisher("topik_utama", Pesan, queue_size=1000)
    rate = rospy.Rate(1)
    while not rospy.is_shutdown():
        dataVariabel = Pesan()
        dataVariabel.usia = 18
        dataVariabel.tinggi = 163.0
        dataVariabel.nama = "Bevinda Vivian"
        dataVariabel.kehadiran = True
        rospy.loginfo("\nUsia: %d\nTinggi: %lf\nNama: %s\nKehadiran: %s",dataVariabel.usia, dataVariabel.tinggi, dataVariabel.nama, "true" if dataVariabel.kehadiran else "false")
        data_publisher.publish(dataVariabel)
        rate.sleep()

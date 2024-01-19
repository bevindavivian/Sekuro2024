import rospy
from bev_package.msg import Pesan

def callbackHandler(msg):
    rospy.loginfo("\033[32m\n Informasi Kehadiran: \n\033[0m")
    rospy.loginfo("\033[34mUsia: %d\n\033[0m", msg.usia)
    rospy.loginfo("\033[34mTinggi: %.2f\n\033[0m", msg.tinggi)
    rospy.loginfo("\033[34mNama: %s\n\033[0m", msg.nama)
    rospy.loginfo("\033[34mKehadiran: %s\n\033[0m", "Hadir" if msg.kehadiran else "Tidak Hadir")

if __name__ == '__main__':
    rospy.init_node('simple_subscriber_node', anonymous=True)
    rospy.Subscriber("topik_utama", Pesan, callbackHandler)
    rospy.spin()

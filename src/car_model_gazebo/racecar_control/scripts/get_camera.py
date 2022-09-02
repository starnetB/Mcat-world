import rospy
from sensor_msgs.msg import Image
import cv2
from cv_bridge import CvBridge

bridge=CvBridge()

def image_callback(message):
    frame=bridge.imgmsg_to_cv2(message, "bgr8")
    cv2.namedWindow("Frame",cv2.WINDOW_NORMAL)
    cv2.imshow("Frame",frame)

    if cv2.waitKey(1) & 0xFF==ord('q'):
        cv2.destroyAllWindows()

def camera_listener():
    rospy.Subscriber("/camera_lees/image_raw", Image, image_callback)
    rospy.spin()    

rospy.init_node("dddd")
camera_listener()
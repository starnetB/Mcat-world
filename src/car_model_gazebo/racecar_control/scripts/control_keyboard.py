#1/usr/bin/env python

from multiprocessing.dummy import active_children
import rospy
from std_msgs.msg import Bool
from std_msgs.msg import Float32 
from std_msgs.msg import Float64  
from ackermann_msgs.msg import AckermannDriveStamped

if __name__=="__main__":
    rospy.init_node('servo_control_test',anonymous=True)

    test_pub=rospy.Publisher("/racecar/ackermann_cmd_mux/output",AckermannDriveStamped,queue_size=1)

    acktest=AckermannDriveStamped()

    acktest.drive.speed=-1
    acktest.drive.steering_angle=0.3
    rate=rospy.Rate(100)

    while not rospy.is_shutdown():
        test_pub.publish(acktest) 
        rate.sleep()
#!/usr/bin/env python
from __future__ import print_function
import roslib
roslib.load_manifest('hexapod')
import sys
import rospy
import cv2
from std_msgs.msg import String
from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError
bool DEBUG = True;
class image_converter:

    def __init__(self):
        self.image_pub = rospy.Publisher("/hexapod/flame",Image,queue_size=1)

        self.bridge = CvBridge()
        self.image_sub = rospy.Subscriber("/camera/color/image_rect_color",Image,self.callback)

    def callback(self,cb_msg):
        cvImg = toCV(cb_msg)
        (rows,cols,channels) = cvImg.shape
        rosMsg =
        self.image_pub.publish(self.bridge.cv2_to_imgmsg(cvImg, "bgr8"))

    if (DEBUG):
        cv2.imshow("Image window", cvImg)
        cv2.waitKey(3)

    """
    Convert from ROS sensor_msgs/Image message to CV2 Image
    """
    def toCV(rosMsg):
        try:
            cvImg = self.bridge.imgmsg_to_cv2(rosMsg, "bgr8")
            return cvImg
        except CvBridgeError as e:
            print(e)

    """
    Convert from CV2 Image to ROS sensor_msgs/Image message
    """
    def toROSMsg(cvImg):
        try:
            rosMsg = self.bridge.cv2_to_imgmsg(cvImg, "bgr8")
            return rosMsg
        except CvBridgeError as e:
            print(e)

def main(args):
  rospy.init_node('image_converter', anonymous=True)
  ic = image_converter()
  try:
    rospy.spin()
  except KeyboardInterrupt:
    print("Shutting down")
  cv2.destroyAllWindows()

if __name__ == '__main__':
    main(sys.argv)

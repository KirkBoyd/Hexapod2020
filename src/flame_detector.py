#!/usr/bin/env python
# @author Shelby
import cv2
import numpy as np
import rospy
import sys
from geometry_msgs.msg import Point
from std_msgs.msg import Bool
from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError

# vis = True
vis = False
candleFound = False
#frame is numpy array of image
# frame = cv2.imread('/home/kirk/hex_ws/src/hexapod/img/flame5.jpg',1)
max_bbox_length = 500
min_bbox_length = 50
min_point_list = 25

bridge = CvBridge()

candle_bbox_pub = rospy.Publisher("/candle/bbox",Image,queue_size=1)
position_pub = rospy.Publisher('/candle/pixel_position', Point,queue_size=1)
found_pub = rospy.Publisher('/candle/found', Bool,queue_size=1)
lit_pub = rospy.Publisher('/candle/lit', Bool,queue_size=1)

def imageCallback(msg):
  cvImg = bridge.imgmsg_to_cv2(msg, desired_encoding="bgr8")
  center = findFlameCenter(cvImg)
  position_pub.publish(center)
  found_pub.publish(candleFound)

def visualize(cvImgWithBbox):
  if vis:
      cv2.rectangle(cvImgWithBbox, (min(point_list[1]),max(point_list[0])),(max(point_list[1]),min(point_list[0])) , (255,0,0), 4)
      # cv2.circle(cvImgWithBbox,center,5,(0,0,255),20)
      scale_percent = 20
      width = int(cvImgWithBbox.shape[1] * scale_percent / 100)
      height = int(cvImgWithBbox.shape[0] * scale_percent / 100)

      dsize = (width, height) 
      cvImgWithBbox = cv2.resize(cvImgWithBbox, dsize)
      cv2.imshow("original", cvImgWithBbox)
      cv2.waitKey(0)
      cv2.destroyAllWindows()


def overlayBbox(cvImg,point_list):
  cv2.rectangle(cvImg, (min(point_list[1]),max(point_list[0])),(max(point_list[1]),min(point_list[0])) , (255,0,0), 4)
  scale_percent = 20
  width = int(cvImg.shape[1] * scale_percent / 100)
  height = int(cvImg.shape[0] * scale_percent / 100)

  dsize = (width, height) 
  cvImgWithBbox = cv2.resize(cvImg, dsize)
  return cvImgWithBbox

def findFlameCenter(cvImg):

  blur = cv2.GaussianBlur(cvImg, (21, 21), 0)
  hsv = cv2.cvtColor(blur, cv2.COLOR_BGR2HSV)

  lower = [18, 50, 50]
  upper = [35, 255, 255]
  lower = np.array(lower, dtype="uint8")
  upper = np.array(upper, dtype="uint8")
  mask = cv2.inRange(hsv, lower, upper)
  
  point_list = np.nonzero(mask)
  if (len(point_list) < min_point_list):
    # return False
    candleFound = False
    return Point(0,0,0)
  if ((max(point_list[1])-min(point_list[1])) > max_bbox_length) or ((max(point_list[1])-min(point_list[1])) < min_bbox_length):
    # return False
    candleFound = False
    return Point(0,0,0)
  
  candleFound = True
  center_x = min(point_list[1])+ (max(point_list[1])-min(point_list[1]))//2
  center_y=  min(point_list[0])+ (max(point_list[0])-min(point_list[0]))//2
  # center = (center_x,center_y)
  center = Point(center_x,center_y, 0)

  cvImgWithBbox = overlayBbox(cvImg, point_list)
  rosImgWithBbox = bridge.cv2_to_imgmsg(cvImgWithBbox, encoding="bgr8")
  candle_bbox_pub.publish(rosImgWithBbox)

  visualize(cvImgWithBbox)

  return center

def main(args):
  
  rospy.init_node('flame_detector')
  # image_sub = rospy.Subscriber("/image_publisher/image_raw",Image,imageCallback)
  image_sub = rospy.Subscriber("/camera/color/image_raw",Image,imageCallback)

  try:
    rospy.spin()
    

  except KeyboardInterrupt:
    print("Shutting down")
  cv2.destroyAllWindows()

if __name__ == '__main__':
    main(sys.argv)


# center = findFlameCenter(frame) 
# while (found_pub is False):
#     center = findFlameCenter(frame)
#     if (center == False):
#         #publish false to /candle/found
#     else:
#         #publish true to found

# while




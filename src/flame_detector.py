# @author Shelby
import cv2
import numpy as np
import rospy
from geometry_msgs.msg import Point
from std_msgs.msg import Bool

vis = True
#frame is numpy array of image
frame = cv2.imread('flame5.jpg',1)
max_bbox_length = 500
min_bbox_length = 50
min_point_list = 25


position_pub = rospy.Publisher('/candle/Position', Point,queue_size=1)
found_pub = rospy.Publisher('/candle/Found', Bool,queue_size=1)
lit_pub = rospy.Publisher('/candle/Lit', Bool,queue_size=1)


def findFlameCenter(frame):

    blur = cv2.GaussianBlur(frame, (21, 21), 0)
    hsv = cv2.cvtColor(blur, cv2.COLOR_BGR2HSV)

    lower = [18, 50, 50]
    upper = [35, 255, 255]
    lower = np.array(lower, dtype="uint8")
    upper = np.array(upper, dtype="uint8")
    mask = cv2.inRange(hsv, lower, upper)
    

    point_list = np.nonzero(mask)
    if (len(point_list) < min_point_list):
        return False
    if ((max(point_list[1])-min(point_list[1])) > max_bbox_length) or ((max(point_list[1])-min(point_list[1])) < min_bbox_length):
        return False
    center_x = min(point_list[1])+ (max(point_list[1])-min(point_list[1]))//2
    center_y=  min(point_list[0])+ (max(point_list[0])-min(point_list[0]))//2
    center = (center_x,center_y)
    return center





center = findFlameCenter(frame) 
while (found_pub is False):
    center = findFlameCenter(frame)
    if (center == False):
        #publish false to /candle/found
    else:
        #publish true to found

while




if vis:
    # cv2.rectangle(frame, (min(point_list[1]),max(point_list[0])),(max(point_list[1]),min(point_list[0])) , (255,0,0), 4)
    cv2.circle(frame,center,5,(0,0,255),20)
    scale_percent = 20
    width = int(frame.shape[1] * scale_percent / 100)
    height = int(frame.shape[0] * scale_percent / 100)

    dsize = (width, height) 
    frame = cv2.resize(frame, dsize)
    cv2.imshow("original", frame)
    cv2.waitKey(0)
    cv2.destroyAllWindows()

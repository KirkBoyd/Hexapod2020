#! /usr/bin/env python

import rospy
from geometry_msgs.msg import Twist
from sensor_msgs.msg import LaserScan
vel = Twist()
vel.linear.x = 0.5
vel.linear.y = 0
vel.linear.z = 0
vel.angular.x = 0
vel.angular.y = 0
vel.angular.z = 0
turn = False


def callback(msg):
    print (msg.ranges[180])
    if (msg.ranges[360] < 1.5):
        vel.linear.x = 0
        vel.angular.z = 0.25
    elif (msg.ranges[180] < 1):
        vel.linear.x = 0
        vel.angular.z = 0.25
    else:
        vel.linear.x = 0.5
        vel.angular.z = 0
#need to modify so that we have array values for depth
# should be a depth for each angle
# this publishes op=ur depth data, and we do the math here, and just pass a distance from the candle

rospy.init_node('topics_quiz_node')
pub = rospy.Publisher('/cmd_vel', Twist, queue_size=1)
sub = rospy.Subscriber('/kobuki/laser/scan', LaserScan, callback)
rate = rospy.Rate(2)

while not rospy.is_shutdown():
    pub.publish(vel)
    rate.sleep()
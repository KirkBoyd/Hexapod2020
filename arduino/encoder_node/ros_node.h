#include <ros.h>
#include <std_msgs/Float32.h>
ros::NodeHandle  nh;

//std_msgs::Float32 left_rpm_msg;
//ros::Publisher left_rpm_pub("sqrl/encoder/left_rpm", &left_rpm_msg);

//std_msgs::Float32 right_rpm_msg;
//ros::Publisher right_rpm_pub("sqrl/encoder/right_rpm", &right_rpm_msg);

std_msgs::Float32 left_ang_vel_msg;
ros::Publisher left_ang_vel_pub("sqrl/encoder/left_ang_vel", &left_ang_vel_msg);

std_msgs::Float32 right_ang_vel_msg;
ros::Publisher right_ang_vel_pub("sqrl/encoder/right_ang_vel", &right_ang_vel_msg);

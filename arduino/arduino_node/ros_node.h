#include <ros.h>
#include <std_msgs/Float32.h>
#include <std_msgs/Bool.h>
#include <geometry_msgs/Point.h>

ros::NodeHandle  nh;

bool candleFound = false;
bool candleLit = false;
float candleX = 0; //may need to change type
float candleY = 0;


ros::Subscriber<geometry_msgs::Point> subCandlePosition("candle/position", cbCandlePosition);
ros::Subscriber<std_msgs::Bool> subCandleFound("candle/found", cbCandleFound);
ros::Subscriber<std_msgs::Bool> subCandleLit("candle/is_lit", cbCandleIsLit);

void cbCandleFound(const std_msgs::Bool& msg){
    candleFound = msg.data;
}

void cbCandleIsLit(const std_msgs::Bool& msg){
    candleLit = msg.data;
}

void cbCandlePosition(const geometry_msgs::Point& msg){
    candleX = msg.x;
    candleY = msg.y;
}
// examples from SQRL:
// std_msgs::Float32 left_ang_vel_msg;
// ros::Publisher left_ang_vel_pub("sqrl/encoder/left_ang_vel", &left_ang_vel_msg);

// std_msgs::Float32 right_ang_vel_msg;
// ros::Publisher right_ang_vel_pub("sqrl/encoder/right_ang_vel", &right_ang_vel_msg);

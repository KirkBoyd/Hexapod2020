/*@author Kirk Boyd*/
#include "ros_node.h"    // Import tab containing ROS related code
#include "legLimits.h"   // Import tab containing lots of position and index data

void setup() {
    nh.initNode();                    // Initialize ROS node
    nh.subscribe(subCandlePosition);
    nh.subscribe(subCandleFound);
    nh.subscribe(subCandleLit);
    nh.advertise(chatter); // for testing purposes
}// end void setup

void loop() {
//    if (!candleFound){
//       / fwd();
//    /}
    str_msg.data = hello;
    chatter.publish( &str_msg );
    //if ()
    // if (command == 0){
    //     stand();
    // }
    // else if(command == 1){
    //     fwd();
    // }
    // else if(command == 2){
    //     turnR();
    // }
    // else if(command == 3){
    //     turnL();
    // }
    // else if(command == 4){
    //     back();
    // }
    nh.spinOnce();
}// end void loop

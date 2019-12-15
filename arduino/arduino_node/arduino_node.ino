/*@author Kirk Boyd*/
#include "ros_node.h"    // Import tab containing ROS related code
#include "encoders.h"   // Import tab containing encoder related code

void setup() {
    nh.initNode();                    // Initialize ROS node
    nh.subscribe(subCandlePosition);
    nh.subscribe(subCandleFound);
    nh.subscribe(subCandleLit);
}

void loop() {
    nh.spinOnce();
    if (!candleFound){
        fwd();
    }
    if ()
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

}

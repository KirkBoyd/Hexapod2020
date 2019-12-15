/*@author Chris Rowe (rwbot)
 * Reads the A & B channels of a quadrature encoder (HEDS-9100#E00) on both the left and right wheels, 
 * and calculates the RPM and angular velocity, then publishes the RPM and/or angular velocity to its associated ROS topic
 * Only the A channel of encoders is used for incrementing the counter, while the B channel serves to determine direction.
 * Channel A is used as an External Interrupt, which calls its Interrupt Sub-Routine (ISR) to increment its counter.
 *  
 * NOTE about 'volatile' variables (http://www.gammon.com.au/forum/?id=11488&reply=7#reply7)
 * |-> Since ISRs can be called at any time, variables shared between an ISR and main code can be updated while being accessed. 
 *     Marking a variable as volatile tells the compiler to not "cache" the variables contents into a 
 *     processor register, but always read it from memory, when needed. 
 *     
 * More info about external interrupts: http://www.gammon.com.au/interrupts 
 */

#include "ros_node.h"    // Import tab containing ROS related code
#include "encoders.h"   // Import tab containing encoder related code
#include <TimerOne.h>   // Library that simplifies Timer Overflow interrupts


void setup() {
  nh.initNode();                    // Initialize ROS node
  //nh.advertise(left_rpm_pub);       // Initialize publisher for left_rpm
  //nh.advertise(right_rpm_pub);      // Initialize publisher for right_rpm
  nh.advertise(left_ang_vel_pub);   // Initialize publisher for left_ang_vel
  nh.advertise(right_ang_vel_pub);  // Initialize publisher for right_ang_vel
  
  // Initializing Timer Overflow Interrupt - Counter overflows every period, and triggers an Overflow Interrupt ISR
  Timer1.initialize(100000);            // Period in MICROseconds (1ms=1000us). Set manually, do not use a variable! 
  Timer1.attachInterrupt(calculateRPM); // calls calculateRPM every overflow

  pinMode(leftEncoderChannelA, INPUT_PULLUP);
  pinMode(leftEncoderChannelB, INPUT_PULLUP);
  // Left Encoder Channel A set to trigger external interrupt on RISING edge, thus calling the ISR isrLeftA   
  attachInterrupt(digitalPinToInterrupt(leftEncoderChannelA), isrLeftA, RISING);
  
  pinMode(rightEncoderChannelA, INPUT_PULLUP);
  pinMode(rightEncoderChannelB, INPUT_PULLUP);
  // Right Encoder Channel A set to trigger external interrupt on RISING edge, thus calling the ISR isrRightA 
  attachInterrupt(digitalPinToInterrupt(rightEncoderChannelA), isrRightA, RISING);     

//  Serial.begin(9600);
}

void loop() {
// Because data types float & int are multi-byte, interrupts must be disabled when accessing them outside their ISR, 
// to ensure the value doesn't change while it is being accessed. See reference in description.
  noInterrupts();
  rpmLeft_Protected = rpmLeft;
  rpmRight_Protected = rpmRight;
  interrupts();

/*
  // Publisher left_rpm_pub publishes the message left_rpm_msg to topic sqrl/encoder/left_rpm
  left_rpm_msg.data = rpmLeft_Protected;    
  left_rpm_pub.publish( &left_rpm_msg );
  
  // Publisher right_rpm_pub publishes the message right_rpm_msg to topic sqrl/encoder/right_rpm
  right_rpm_msg.data = rpmRight_Protected;
  right_rpm_pub.publish( &right_rpm_msg );
*/
  // Publisher left_ang_vel_pub publishes the message left_ang_vel_msg to topic sqrl/encoder/left_ang_vel
  left_ang_vel_msg.data = rpmLeft_Protected * RPM_to_AngularVelocity;    
  left_ang_vel_pub.publish( &left_ang_vel_msg );
  
  // Publisher right_ang_vel_pub publishes the message right_ang_vel_msg to topic sqrl/encoder/right_ang_vel
  right_ang_vel_msg.data = rpmRight_Protected * RPM_to_AngularVelocity;    
  right_ang_vel_pub.publish( &right_ang_vel_msg );
  
  nh.spinOnce();

  
//  Serial.print("RPM-L ");
//  Serial.print(rpmLeft_Protected);
//  Serial.print("\tRPM-R ");
//  Serial.println(rpmRight_Protected);
//  delay(100);
}

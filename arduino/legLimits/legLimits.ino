#include <ax12.h>
#define serPort 1   /*this is the serial port that communicates with the servos.
//ensure the connection is plugged into both digital ports 18 [TXD1] and 19 [RXD1]
//on the DFROBOT Bluno Mega 2560 */

#define waitTime 100

#define CFR 1
#define CMR 2
#define CRR 3
#define CRL 4
#define CML 5
#define CFL 6
#define FFR 7
#define FMR 8
#define FRR 9
#define FRL 10
#define FML 11
#define FFL 12
#define TFR 13
#define TMR 14
#define TRR 15
#define TRL 16
#define TML 17
#define TFL 18

#define CFRdef 512
#define CMRdef 512
#define CRRdef 512
#define CRLdef 512
#define CMLdef 512
#define CFLdef 512
#define FFRdef 512
#define FMRdef 512
#define FRRdef 512
#define FRLdef 512
#define FMLdef 512
#define FFLdef 512
#define TFRdef 512
#define TMRdef 512
#define TRRdef 512
#define TRLdef 512
#define TMLdef 512
#define TFLdef 512

#define CFRmin 390  //fwd
#define CFRmax 680  //back
#define CMRmin 420  //fwd
#define CMRmax 650  //back
#define CRRmin 360  //fwd
#define CRRmax 680  //back
#define CRLmin 360  //back
#define CRLmax 650  //fwd
#define CMLmin 420  //back
#define CMLmax 575  //fwd
#define CFLmin 360  //back
#define CFLmax 650  //fwd

#define CFRfwd 448  //fwd
#define CFRback 576  //back
#define CMRfwd 448  //fwd
#define CMRback 576  //back
#define CRRfwd 448  //fwd
#define CRRback 576  //back
#define CRLback 448  //back
#define CRLfwd 576  //fwd
#define CMLback 448  //back
#define CMLfwd 576  //fwd
#define CFLback 448  //back
#define CFLfwd 576  //fwd

#define TFRmin 400//up
#define TFRmax 600//down
#define TMRmin 450//down
#define TMRmax 620//up
#define TRRmin 410//down
#define TRRmax 610//up
#define TRLmin 420//up
#define TRLmax 600//down
#define TMLmin 420//up
#define TMLmax 600//down
#define TFLmin 420//down
#define TFLmax 600//up

#define TFRup 400//up
#define TFRdown 576//down
#define TMRdown 448//down
#define TMRup 600//up
#define TRRdown 448//down
#define TRRup 610//up
#define TRLup 420//up
#define TRLdown 576//down
#define TMLup 420//up
#define TMLdown 576//down
#define TFLdown 448//down
#define TFLup 600//up

#define FFRmin 400//down
#define FFRmax 640//up
#define FMRmin 448//up **DO NOT EXCEED**POWER HUB AT MAX**
#define FMRmax 600//down
#define FRRmin 448//UP
#define FRRmax 620//dOWN
#define FRLmin 420//DOWN
#define FRLmax 640//UP
#define FMLmin 420//DOWN
#define FMLmax 620//up **DO NOT EXCEED**POWER HUB AT MAX**
#define FFLmin 448//up
#define FFLmax 600//down

#define FFRdown 432//down
#define FFRup 512//up
#define FMRup 512//up
#define FMRdown 592//down
#define FRRup 512//UP
#define FRRdown 592//dOWN
#define FRLdown 432//DOWN
#define FRLup 512//UP
#define FMLdown 432//DOWN
#define FMLup 512//up
#define FFLup 512//up
#define FFLdown 592//down


void setup() {
  Serial.begin(9600);
  stand();
  delay(1500);
  
}

void loop() {
  //SetPosition(2,600);
   fwd();
  //relaxAll();
  //coxCtr();
  //toesUp();
  
//  stand();
//  //femUp();
//
//  delay(500);
//  relaxAll();
//  delay(1000);
}

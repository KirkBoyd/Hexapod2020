#include <ax12.h>
#define serPort 1   /*this is the serial port that communicates with the servos.
//ensure the connection is plugged into both digital ports 18 [TXD1] and 19 [RXD1]
//on the DFROBOT Bluno Mega 2560 */

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
#define TLL 16
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
#define TLLdef 512
#define TMLdef 512
#define TFLdef 512

#define CFRmin 0
#define CFRmax 0 
#define CMRmin 0
#define CMRmax 0 
#define CRRmin 0
#define CRRmax 0 
#define CRLmin 0
#define CRLmax 0 
#define CMLmin 0
#define CMLmax 0 
#define CFLmin 0
#define CFLmax 0 

#define FFRmin 0
#define FFRmax 0
#define FMRmin 0
#define FMRmax 0
#define FRRmin 0
#define FRRmax 0
#define FRLmin 0
#define FRLmax 0
#define FMLmin 0
#define FMLmax 0
#define FFLmin 0
#define FFLmax 0


#define TFRmin 0
#define TFRmax 0
#define TMRmin 0
#define TMRmax 0
#define TRRmin 0
#define TRRmax 0
#define TRLmin 0
#define TRLmax 0
#define TMLmin 0
#define TMLmax 0
#define TFLmin 0
#define TFLmax 0

void setup() {
  Serial.begin(9600);
  
}

void loop() {
  //SetPosition(CFR,512);
  stand();

}

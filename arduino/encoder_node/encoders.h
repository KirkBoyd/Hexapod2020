// Counts per revolution of encoder (+/-10). Will determine precisely if more resolution is necessary.
const float CPR = 5156;
const float RPM_to_AngularVelocity = 0.10472;   //  PI/30

#define leftEncoderChannelA 2       // Pin for Channel A of Left Encoder
#define leftEncoderChannelB 4       // Pin for Channel B of Left Encoder
#define stateLeftA bitRead(PIND,leftEncoderChannelA)  // Macros to get state (HIGH/LOW) of Channel A/B 
#define stateLeftB bitRead(PIND,leftEncoderChannelB)  // bitRead() is used because it is faster than digitalRead()
volatile unsigned int countLeft;    // Current tick count of Encoder Channel A  
volatile bool isForwardLeft;        // Boolean of whether the wheel is spinning forward
volatile float rpmLeft;             // Current signed RPM of wheel
unsigned int countLeft_Protected;   // Protected copies of multi-byte variables to be used for printing 
float rpmLeft_Protected;

#define rightEncoderChannelA 3      // Pin for Channel A of Right Encoder
#define rightEncoderChannelB 5      // Pin for Channel B of Right Encoder
#define stateRightA bitRead(PIND,rightEncoderChannelA)  // Macros to get state (HIGH/LOW) of Channel A/B 
#define stateRightB bitRead(PIND,rightEncoderChannelB)  // bitRead() is used because it is faster than digitalRead()
volatile unsigned int countRight;   // Current tick count of Encoder Channel A
volatile bool isForwardRight;       // Boolean of whether the wheel is spinning forward 
volatile float rpmRight;            // Current signed RPM of wheel
unsigned int countRight_Protected;  // Protected copies of multi-byte variables to be used for printing 
float rpmRight_Protected;

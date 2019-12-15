/*External Interrupt Sub-Routines for Channel A of each encoder.
 * 1-Called every RISING edge of Channel A, and increments the count for that side encoder 
 * 2-Evaluates the direction by logically comparing the current phases of the channels. 
 * |->  We know Channel A currently has a Raised edge.
 *      If the phase of Channel B is also HIGH, the wheel is moving backwards. (A==B)
 *      If the phase of Channel B is LOW, then the wheel is moving forwards.   (A!=B)
 * The result of this logical comparison sets the isForward flag
 * 
 * NOTE 
 * The evaluation of the Right wheel is inverted because the right wheel is a mirror to the left wheel. !(A!=B)
 * An equivalent correction would be 
 *    isForwardRight = (stateRightA == stateRightB); 
 * since !(A!=B) is logically equivalent to (A==B) 
 * This correction could have also been done in hardware by flipping the A & B channel on the encoder.
 */

void isrLeftA() {
  countLeft++;
  isForwardLeft = (stateLeftA != stateLeftB);
}

void isrRightA() {
  countRight++;
  // Correct the inversion of the right wheel
  isForwardRight = !(stateRightA != stateRightB);
}



/*Timer Overflow Interrupt Sub-Routine for RPM Calculation. Called every {period} milliseconds
 * 1-Calculates Un-Signed RPM for each side using the ticks counted from the last calculation. periodMultiplier is used to allow for different periods (if needed)
 * 2-Resets the count value
 * 3-Signs the RPM by multiplying by -1 if the isForward flag is FALSE
 */

// Period in ms. This variable is only used to calculate periodMultiplier. 
// The Timer Overflow Period must be explicitly set numerically in setup()
int periodMilli = 100; 
int periodMultiplier = 1000 / periodMilli;

void calculateRPM(void){
  rpmLeft = float(countLeft) / CPR * 60 * periodMultiplier;
  countLeft = 0;
  if(!isForwardLeft){ rpmLeft *= -1; }    // Sign backwards movement as negative
  if(rpmLeft == 0){rpmLeft = 0;}          // Prevent negative zero (-0.0) value
  
  rpmRight = float(countRight) / CPR * 60 * periodMultiplier;
  countRight = 0;
  if(!isForwardRight){ rpmRight *= -1; }  // Sign backwards movement as negative
  if(rpmRight == 0){rpmRight = 0;}        // Prevent negative zero (-0.0) value
}

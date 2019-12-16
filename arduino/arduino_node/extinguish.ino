#define versaPin 14

void extinguish(){
  stand();
  delay(longWait);
  digitalWrite(versaPin, HIGH);
  delay(waitTime);
  digitalWrite(versaPin, LOW);
  delay(waitTime);
  digitalWrite(versaPin, HIGH);
  delay(waitTime);
  digitalWrite(versaPin, LOW);
  delay(waitTime);
  digitalWrite(versaPin, HIGH);
  delay(waitTime);
  digitalWrite(versaPin, LOW);
  delay(waitTime);
}

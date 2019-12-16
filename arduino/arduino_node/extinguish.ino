void extinguish(){
  stand();
  delay(longWait/2);
  digitalWrite(versaPin, HIGH);
  delay(longWait/2);
  digitalWrite(versaPin, LOW);
  delay(longWait/2);
  digitalWrite(versaPin, HIGH);
  delay(longWait/2);
  digitalWrite(versaPin, LOW);
  delay(longWait/2);
  digitalWrite(versaPin, HIGH);
  delay(longWait/2);
  digitalWrite(versaPin, LOW);
  delay(longWait/2);
}

#define port 1//analog port 1 input

void setup() {
  pinMode(port,INPUT);  
  Serial.begin(9600);
}

void loop() {
  Serial.println(analogRead(port));
}

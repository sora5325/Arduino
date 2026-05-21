#include <Arduino.h>

void setup() {
  //intialize serial communication
  Serial.begin(9600);
  Serial.println("Hello Arduino");

}

void loop() {
  Serial.println("in the loop");
  delay(500);

}

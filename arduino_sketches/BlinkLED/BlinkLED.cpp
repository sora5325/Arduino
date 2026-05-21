#include <Arduino.h>

void setup() {
  // set LED pin to output
  pinMode(13, OUTPUT);

}

void loop() {
  // LED high:on, low:off 
  digitalWrite(13, HIGH);
  //delay for 1 sec because loop() runs too fast
  delay(1000);
  digitalWrite(13, LOW);
  delay(1000);

}

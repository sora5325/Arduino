//a way to include an already written code
#include <Servo.h>

//define a new Servo object
Servo myServo;

void setup() {
  myServo.attach(12);

}

void loop() {
  int joystick_value = analogRead(A0);
  int angle = map(joystick_value, 0, 1023, 0, 180);

  myServo.write(angle);

}

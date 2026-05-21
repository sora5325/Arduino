//a way to include an already written code
#include <Servo.h>

//define a new Servo object
Servo myServo;

void setup() {
  myServo.attach(12);
  Serial.begin(9600);

}

void loop() {
  int joystick_value = analogRead(A0);
  Serial.println(joystick_value);

  //by default the joystick position is 0-1023.
  //mapping it to 400-600 means moving it in the range of 200, which makes it sensitive.
  //only the difference matters here.
  int angle = map(joystick_value, 400, 600, 0, 180);

  myServo.write(angle);

}

#include <Arduino.h>
#include <Servo.h>

Servo myServo;  // create servo object to control a servo

void setup() {
  // put your setup code here, to run once:
  myServo.attach(9);  // attaches the servo on pin 9 to the servo object
  //distance sensor
  pinMode(11,OUTPUT);
  pinMode(12,INPUT);
  //LED
  pinMode(13,OUTPUT);
}

void loop() {

  int joystick_value = analogRead(A0);

  if (joystick_value<400 || joystick_value>600){
    //joystick is being moved
    Serial.println(joystick_value);
    int angle = map(joystick_value, 400, 600, 0, 180);
    myServo.write(angle);

  }else{
    //idle state
    myServo.write(0);  
    delay(1000);      
    myServo.write(1020);
    delay(1000);
  }

  //read distance
  int sensor_output = digitalRead(11);
  if (sensor_output>10){
    digitalWrite(12, HIGH);
  }

  
  
}

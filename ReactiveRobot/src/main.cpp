#include <Arduino.h>
#include <Servo.h>

Servo myServo;  // create servo object to control a servo
//set pin numbers
const int trigPin = 11;
const int echoPin = 12;
const int LEDPin = 13;

//variables for the distance sensor. long is for bigger int
int distance;
long duration;

void setup() {
  myServo.attach(7);  
  //distance sensor
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  //LED
  pinMode(LEDPin,OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int joystick_value = analogRead(A0);

  //reset, send pulse, pause
  digitalWrite(trigPin, LOW);
  delayMicroseconds(20);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  //measures pulse duration. how long echo stayed HIGH
  //digitalRead only reads ON or OFF, which is insufficient here
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; //in cm
  Serial.println(distance);

  if (distance>0 && distance<10){
    digitalWrite(LEDPin, HIGH);
    delay(100);
    digitalWrite(LEDPin, LOW);
    delay(100);
  }else if (joystick_value<400 || joystick_value>600){
    //joystick is being moved
    Serial.println(joystick_value);
    int angle = map(joystick_value, 400, 600, 0, 180);
    myServo.write(angle);
  }else{
    //idle state
    myServo.write(0);
    delay(500);      
    myServo.write(180);
    delay(500);
  }

  
  
}

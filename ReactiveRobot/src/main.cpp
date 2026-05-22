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
  myServo.attach(9);  
  //distance sensor
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  //LED
  pinMode(LEDPin,OUTPUT);

  Serial.begin(9600);
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

  //reset, send pulse, pause
  digitalWrite(trigPin, LOW);
  delay(2000);
  digitalWrite(trigPin, HIGH);
  delay(10000);
  digitalWrite(trigPin, LOW);

  //measures pulse duration. how long it took to change from high to low
  //digitalRead only reads ON or OFF, which is insufficient here
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; //in cm

  if (distance<2.5){
    digitalWrite(LEDPin, HIGH);
  }

  
  
}

#include <Arduino.h>
#include <Servo.h>

Servo myServo;  // create servo object to control a servo
//set pin numbers
const int trigPin = 12;
const int echoPin = 11;
const int LEDPin = 13;
const int buzzerPin = 2;

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
  //passive buzzer
  pinMode(buzzerPin,OUTPUT);

  Serial.begin(9600);
}

void loop() {

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
  //Serial.println(duration);
  //Serial.println(distance);

  if (distance>0 && distance<10){
    myServo.write(0);
    tone(buzzerPin, 200);

    digitalWrite(LEDPin, HIGH);
    delay(100);
    digitalWrite(LEDPin, LOW);
    delay(100);

     noTone(buzzerPin);

  }else{
    //idle state
    myServo.write(0);
    delay(500);      
    myServo.write(180);
    delay(500);
  }

  
  
}

/*

Code for eBOT Z
by eLab Peers (C) 2015.

Visit us at:
http://www.elabpeers.com

All rights reserved.

Arduino Pins:
1.  Pin 3 to Trig on Ultrasonic Sensor Module
2.  Pin 2 to Echo on Ultrasonic Sensor Module
3.  Pin 10 to servo (yellow wire)
4.  Pin 13 to Red LED
5.  Pin 12 to Green LED

Wiring:
For the Ultrasonic Sensor Module:
1.  5V to VCC on Ultrasonic Sensor
2.  GND to GND on Ultrasonic Sensor

For the servo:
1.  VCC to 5V pin on Arduino
2.  GND to GND on Arduino

For the power input and output of Motor Shield:
1.  VIN to +ve (red wire) of AA x 4 battery box
2.  GND to -ve (black wire) of AA x 4 battery box
3.  A+ to +ve of the right motor
4.  A- to -ve of the right motor
5.  B+ to -ve of the left motor
6.  B- to +ve of the left motor


For the power input of Arduino:
Connect the power jack on Arduino to the 9V battery box

Features:
1. The robot will react and follow the object in front of the ultransonic sensor.
2. Learn how to use ultransoice sensor to control motors.
*/

#include <Elab.h>
#include <Servo.h> //We make use of Servo in library to control the servo with Ultrasonic Sensor

Elab  elab;
Servo myservo; //let's name the servo "myservo"

const int TrigPin = 3;
const int EchoPin = 2;

const int DirAPin = 4;  // corresponds pin 4 in Arduino to DirAPin in Motor Shield, direction of the right wheel
const int PwmAPin = 5;  // corresponds pin 5 in Arduino to PwmAPin in Motor Shield, speed of the right wheel
const int PwmBPin = 6;  // corresponds pin 6 in Arduino to PwmBPin in Motor Shield, speed of the left wheel
const int DirBPin = 7;  // corresponds pin 7 in Arduino to DirBPin in Motor Shield, direction of the left wheel
const int RedLedPin = 13; // corresponds pin 13 in Arduino to Red LED
const int GreenLedPin = 12; // corresponds pin 12 on Arduino to Green LED

const int ClearDistance =30; // set the clear distance between the sensor and the object to 30 cm

const int FSpeed = 255;
const int blinktime = 800;

void setup()
{
  Serial.begin(9600);
  myservo.attach(10); //"myservo" corresponds pin 10 to the signal wire of the servo
  pinMode(TrigPin, OUTPUT); //set TrigPinPin as output
  pinMode(EchoPin, INPUT); //set EchoPinPin as input
  pinMode(PwmAPin, OUTPUT); // set PwmAPin as output
  pinMode(DirAPin, OUTPUT); // set DirAPin as output 
  pinMode(PwmBPin, OUTPUT); // set PwmBPin as output
  pinMode(DirBPin, OUTPUT); // set DirBPin as output
  pinMode(RedLedPin, OUTPUT); // set Red LED as output
  pinMode(GreenLedPin, OUTPUT); // set Green LED as output
}

void loop()
{
  myservo.write(90); //move the servo to 90 degree
  delay(500);
  myservo.detach(); 
  delay(100);        

  int TestDistance = elab.UltrasonicSenDistance(TrigPin, EchoPin); //check the distance
  Serial.print(TestDistance);
  Serial.println(" cm");
 
  if ( TestDistance < ClearDistance)   //if the distance is shorter than 30 cm, Backward
  {
    elab.MotorStop(PwmAPin, DirAPin);
    elab.MotorStop(PwmBPin, DirBPin);
    elab.MotorBackward(PwmAPin, DirAPin);
    elab.MotorBackward(PwmBPin, DirBPin);
    elab.LedBlink(GreenLedPin, blinktime);
    elab.LedBlink(RedLedPin, blinktime);   
    Serial.println("backward");
    delay(100);
  }
  else
  {
    elab.MotorForward(PwmAPin, DirAPin, FSpeed);  //if the distance is longer than 30 cm, Forward
    elab.MotorForward(PwmBPin, DirBPin, FSpeed);
    elab.LedOn(GreenLedPin);
    elab.LedOn(RedLedPin);     
    Serial.println("forward");
    delay(100);
  }
}


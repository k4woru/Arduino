/*
Code for eBOT Z
by eLab Peers (C) 2015.

Visit us at:
http://www.elabpeers.com

All rights reserved.

Arduino Pins:
1.  Pin A0 to Left SpeedSensor
2.  Pin A5 to Right SpeedSensor

Wiring:
For the Speed Sensor Module:
1.  VCC to 5V pin on Arduino
2.  GND to GND on Arduino

For the servo:
1.  5V to 5V pin on Arduino
2.  GND to GND on Arduino

For the power input and output of Motor Shield:
1.  VIN to +ve (red wire) of AA x 4 battery box
2.  GND to -ve (black wire) of AA x 4 battery box
3.  A+ to +ve of the right motor
4.  A- to -ve of the right motor
5.  B+ to -ve of the left motor
6.  B- to +ve of the left motor

Features:
Making a two wheels Robot runnging in a straight line is not "Straightforward"
It is very diffcult to make eBOT Z to run perfectly straight with a few line of code, 
the purpose following code allowed user to learn how diffcult is that.
Reviewing Lab6, Lab6b help a lot to find the key parameter "SpeedOffset" in the code below.

Having a relatively long (> 10 meters) test runway for eBOT Z to test out the ablity to run StraightForward.

From Lab 6b, if reported "Speed difference" is able to brounce between +ve and -ve back and forward after couple test cycles
then SpeedOffset should set to 0

*/

#include <Elab.h>

Elab elab;

const int DirAPin = 4;  // corresponds pin 4 in Arduino to DirAPin in Motor Shield, direction of the right wheel
const int PwmAPin = 5;  // corresponds pin 5 in Arduino to PwmAPin in Motor Shield, speed of the right wheel
const int PwmBPin = 6;  // corresponds pin 6 in Arduino to PwmBPin in Motor Shield, speed of the left wheel
const int DirBPin = 7;  // corresponds pin 7 in Arduino to DirBPin in Motor Shield, direction of the left wheel

const int SpdSenLPin = A0;
const int SpdSenRPin = A5;

const int SpeedSenSample = 6;

int SpeedR = 220;
int SpeedL = 220;

long SpeedDiff ;

//From Lab 6b, if reported "Speed difference" is able to brounce between +ve and -ve back and forward after couple test cycles
//then SpeedOffset should set to 0
const int SpeedOffset = 0; // a +ve number if eBOT Z tilted left or -ve number if eBOT Z tilted right

void setup()
{
  Serial.begin (9600);

  pinMode(PwmAPin, OUTPUT); 
  pinMode(DirAPin, OUTPUT); 
  pinMode(PwmBPin, OUTPUT); 
  pinMode(DirBPin, OUTPUT);
  pinMode(SpdSenLPin, INPUT);
  pinMode(SpdSenRPin, INPUT);
}

void loop()
{
    elab.MotorForward(PwmAPin, DirAPin, SpeedR);
    elab.MotorForward(PwmBPin, DirBPin, SpeedL);
    SpeedDiff = elab.SpeedSenLRSpeedDiff(SpdSenLPin, SpdSenRPin, SpeedSenSample);
    Serial.println();
    Serial.println("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    Serial.print("Speed difference (+ve Right Faster / -ve Left Faster):  ");
    Serial.println(SpeedDiff);
    Serial.println("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    Serial.println();
    delay(500);

    SpeedR = elab.SpeedBalance(SpeedR, SpeedDiff, SpeedOffset);
    Serial.print("Current Left Motor PWM Speed:  ");
    Serial.println(SpeedL);
    Serial.print("Current Right Motor PWM Speed:  ");
    Serial.println(SpeedR);    
    delay(1000); 
}
 

/*

Code for Speed Encoder/Sensor with MotorShield
by eLab Peers (C) 2015.

Visit us at:
http://www.elabpeers.com

All rights reserved.

Lab 6b - Testing Speed Sensors

Arduino Pins:
1.  Pin A0 to Left SpeedSensor
2.  Pin A5 to Right SpeedSensor

Wiring:
For the Speed Sensor Module:
1.  VCC to 5V pin on Arduino
2.  GND to GND on Arduino
3.  Left Sensor OUT to A5 and Righ Sensor OUT to A0 accordingly

For the power input and output of Motor Shield:
1.  VIN to +ve (red wire) of AA x 4 battery box
2.  GND to -ve (black wire) of AA x 4 battery box
3.  A+ to +ve of the right motor
4.  A- to -ve of the right motor
5.  B+ to -ve of the left motor
6.  B- to +ve of the left motor

Features:
Sense the speed of the two motors.
Report the speed difference of the two motors.
Control and Balance the speed of the two motors
*/

#include <Elab.h>
Elab elab;

const int DirAPin = 4;  // corresponds pin 4 in Arduino to DirAPin in Motor Shield, direction of the right wheel
const int PwmAPin = 5;  // corresponds pin 5 in Arduino to PwmAPin in Motor Shield, speed of the right wheel
const int PwmBPin = 6;  // corresponds pin 5 in Arduino to PwmAPin in Motor Shield, speed of the left wheel
const int DirBPin = 7;  // corresponds pin 4 in Arduino to DirAPin in Motor Shield, direction of the left wheel

const int SpdSenLPin = A0;
const int SpdSenRPin = A5;

const int SpeedOffset = 0;
const int SpeedSenSample = 20;

int SpeedR = 230;
int SpeedL = 230;

long SpeedDiff ;

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
    elab.MotorStop(PwmAPin, DirAPin);
    elab.MotorStop(PwmBPin, DirBPin);

    Serial.println();
    Serial.print("Current Left Motor PWM Speed:  ");
    Serial.println(SpeedL);
    Serial.print("Current Right Motor PWM Speed:  ");
    Serial.println(SpeedR);    
    
    SpeedR = elab.SpeedBalance(SpeedR, SpeedDiff, SpeedOffset);
    Serial.print("New     Right Motor PWM Speed:  ");
    Serial.println(SpeedR);
    Serial.println("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    Serial.println();
    delay(160000);
}
 





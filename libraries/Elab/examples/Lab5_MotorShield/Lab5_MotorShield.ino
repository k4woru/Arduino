/*

Test code for Motor Shield
by eLab Peers (C) 2015.

Visit us at:
http://www.elabpeers.com

All rights reserved.

Lab 5 - Testing Motor Shield

Arduino Pins:
All pins on Arduino are connected with Motor Shield already.

Wiring:
For the power input and output of Motor Shield:
1.  VIN to +ve (red wire) of AA x 4 battery box
2.  GND to -ve (black wire) of AA x 4 battery box
3.  A+ to +ve of the right motor
4.  A- to -ve of the right motor
5.  B+ to -ve of the left motor
6.  B- to +ve of the left motor

Features:
1.  Test the motor can be moved properly.
2.  Test the sequence of movement and check if the motors are connectly correctly.
    The sequence is as follow:
    one direction
    opposite direction
    Each movement lasts 5 second and then loop again.
*/

#include <Elab.h>

Elab elab;


const int PwmAPin = 5;  // corresponds pin 5 in Arduino to PwmAPin in Motor Shield, speed of the right wheel
const int DirAPin = 4;  // corresponds pin 4 in Arduino to DirAPin in Motor Shield, direction of the right wheel
const int PwmBPin = 6;  // corresponds pin 6 in Arduino to PwmBPin in Motor Shield, speed of the left wheel
const int DirBPin = 7;  // corresponds pin 7 in Arduino to DirBPin in Motor Shield, direction of the left wheel

int SpeedR = 220;  //255 fastest and 175 slowest
int SpeedL = 220;  //255 fastest and 175 slowest


void setup()
{
  //Serial.begin (9600); 
  pinMode(PwmAPin, OUTPUT); // set PwmAPin as output
  pinMode(DirAPin, OUTPUT); // set DirAPin as output
  pinMode(PwmBPin, OUTPUT); // set PwmBPin as output
  pinMode(DirBPin, OUTPUT); // set DirBPin as output
}


void loop() 
{
  while (SpeedL > 175){
      elab.MotorForward(PwmAPin, DirAPin, SpeedR);
      elab.MotorForward(PwmBPin, DirBPin, SpeedL);           
      delay(100000);
      elab.MotorBackward(PwmAPin, DirAPin);
      elab.MotorBackward(PwmBPin, DirBPin); 
      delay(50000);
      SpeedL = SpeedL - 5;
      SpeedR = SpeedR - 5;
      delay(50000);
  }
    while (SpeedL < 255){
      elab.MotorForward(PwmAPin, DirAPin, SpeedR);
      elab.MotorForward(PwmBPin, DirBPin, SpeedL);     
      delay(100000);
      elab.MotorBackward(PwmAPin, DirAPin);
      elab.MotorBackward(PwmBPin, DirBPin); 
      delay(50000);
      SpeedL = SpeedL + 5;
      SpeedR = SpeedR + 5;
      delay(50000);
  }
}

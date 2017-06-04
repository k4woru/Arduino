/*
Code for eBOT Z
by eLab Peers (C) 2015.

Visit us at:
http://www.elabpeers.com

All rights reserved.

Arduino Pins:
1.  Pin A0 to Left SpeedSensor
2.  Pin A5 to Right SpeedSensor
3.  Pin 13 to Red LED
4.  Pin 12 to Green LED

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
Try to control your eBOT Z to keep running in a cicle that can always return to the starting point.
By utilizing how many pulses are sense from speed sensor, an accurate degree of turn can be made by eBOT Z.

Note:
Our default code may not works for all eBOT Z
Try to find out the optimal 
CountTurnAround, CountSharpTurn, and CountTurn for your own eBOT Z
*/


#include<Elab.h>

Elab elab;

const int DirAPin = 4;  // corresponds pin 4 in Arduino to DirAPin in Motor Shield, direction of the right wheel
const int PwmAPin = 5;  // corresponds pin 5 in Arduino to PwmAPin in Motor Shield, speed of the right wheel
const int PwmBPin = 6;  // corresponds pin 6 in Arduino to PwmBPin in Motor Shield, speed of the left wheel
const int DirBPin = 7;  // corresponds pin 7 in Arduino to DirBPin in Motor Shield, direction of the left wheel

const int SpdSenLPin = A0;
const int SpdSenRPin = A5;
const int RedLedPin = 13; // corresponds pin 13 in Arduino to Red LED
const int GreenLedPin = 12; // corresponds pin 12 on Arduino to Green LED

const int SpeedSenSample = 6;

int SpeedR = 220;
int SpeedL = 220;

long SpeedDiff ;

const int SpeedOffset = 0; // refer to Lab6b and Project 3
const int CountTurnAround = 7;
const int CountSharpTurn = 3;
const int CountTurn = 2;

void setup()
{
  Serial.begin (9600);

  pinMode(PwmAPin, OUTPUT); 
  pinMode(DirAPin, OUTPUT); 
  pinMode(PwmBPin, OUTPUT); 
  pinMode(DirBPin, OUTPUT); 
  pinMode(RedLedPin, OUTPUT); 
  pinMode(GreenLedPin, OUTPUT); 
  pinMode(SpdSenLPin, INPUT);
  pinMode(SpdSenRPin, INPUT);
}

void loop()
{
    elab.MotorBothForward(PwmAPin, DirAPin, PwmBPin, DirBPin);
    delay(300);
   
    RightTurn();
    
    elab.MotorBothForward(PwmAPin, DirAPin, PwmBPin, DirBPin);
    delay(300);    

    SharpRightTurn();    
    
    elab.MotorBothForward(PwmAPin, DirAPin, PwmBPin, DirBPin);
    delay(300);    
    
    RightTurn();
    
    elab.MotorBothForward(PwmAPin, DirAPin, PwmBPin, DirBPin);
    delay(300);    

    SharpRightTurn();
    
    elab.MotorBothForward(PwmAPin, DirAPin, PwmBPin, DirBPin);
    delay(300);  
    
    UTurn();
     
    elab.MotorBothForward(PwmAPin, DirAPin, PwmBPin, DirBPin);
    delay(300); 
    
    LeftTurn();
    
    elab.MotorBothForward(PwmAPin, DirAPin, PwmBPin, DirBPin);
    delay(300); 
    
    SharpLeftTurn();
    
    elab.MotorBothForward(PwmAPin, DirAPin, PwmBPin, DirBPin);
    delay(300); 
    
    LeftTurn();

    elab.MotorBothForward(PwmAPin, DirAPin, PwmBPin, DirBPin);
    delay(300); 
    
    SharpLeftTurn();

    elab.MotorBothForward(PwmAPin, DirAPin, PwmBPin, DirBPin);
    delay(300); 
    
    UTurn();
}


void LeftTurn()
{
    elab.MotorSLeftTurn(PwmAPin, DirAPin, PwmBPin, DirBPin);
    elab.SpeedSenLRSpeedDiff(SpdSenLPin, SpdSenRPin, CountTurn);
    elab.MotorBothStop(PwmAPin, DirAPin, PwmBPin, DirBPin);
    elab.LedOn(GreenLedPin);
    elab.LedOff(RedLedPin);   
    delay(100);
}

void SharpLeftTurn()
{
    elab.MotorSLeftTurn(PwmAPin, DirAPin, PwmBPin, DirBPin);
    elab.SpeedSenLRSpeedDiff(SpdSenLPin, SpdSenRPin, CountSharpTurn);
    elab.MotorBothStop(PwmAPin, DirAPin, PwmBPin, DirBPin);
    elab.LedOn(GreenLedPin);
    elab.LedOff(RedLedPin);   
    delay(100);
}

void RightTurn()
{
    elab.MotorSRightTurn(PwmAPin, DirAPin, PwmBPin, DirBPin);
    elab.SpeedSenLRSpeedDiff(SpdSenLPin, SpdSenRPin, CountTurn);
    elab.MotorBothStop(PwmAPin, DirAPin, PwmBPin, DirBPin);
    elab.LedOff(GreenLedPin);
    elab.LedOn(RedLedPin);
    delay(100);
}

void SharpRightTurn()
{
    elab.MotorSRightTurn(PwmAPin, DirAPin, PwmBPin, DirBPin);
    elab.SpeedSenLRSpeedDiff(SpdSenLPin, SpdSenRPin, CountSharpTurn);
    elab.MotorBothStop(PwmAPin, DirAPin, PwmBPin, DirBPin);
    elab.LedOff(GreenLedPin);
    elab.LedOn(RedLedPin);
    delay(100);
}

void UTurn()
{
    elab.MotorSLeftTurn(PwmAPin, DirAPin, PwmBPin, DirBPin);
    elab.SpeedSenLRSpeedDiff(SpdSenLPin, SpdSenRPin, CountTurnAround);
    elab.MotorBothStop(PwmAPin, DirAPin, PwmBPin, DirBPin);
    elab.LedOn(GreenLedPin);
    elab.LedOff(RedLedPin);   
    delay(100);
}

/*
Code for eBOT Z
by eLab Peers (C) 2015.

Visit us at:
http://www.elabpeers.com

All rights reserved.

Arduino Pins:
1.  Pin A1 to OUT1 on control board of Tracking Sensor
2.  Pin A2 to OUT2 on control board of Tracking Sensor
3.  Pin A3 to OUT3 on control board of Tracking Sensor
4.  Pin A4 to OUT4 on control board of Tracking Sensor
5.  Pin 13 to Red LED
6.  Pin 12 to Green LED

Wiring:
For the control board of the Tracking Sensors:
1.  VCC to 5V pin on Arduino
2.  GND to GND on Arduino

For the IR Sensors to the control board:
1.  The left IR sensor to Sig1
2.  The middle left IR sensor to Sig2
3.  The middle right IR sensor to Sig3
4.  The right IR sensor to Sig4

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
1.  The robot can be moved following the black-tape line automatically with checking the Tracking Sensor continuously.
*/

#include <Elab.h>

Elab elab;

const int PwmAPin = 5;  // corresponds pin 5 in Arduino to PwmAPin in Motor Shield, speed of the right wheel
const int DirAPin = 4;  // corresponds pin 4 in Arduino to DirAPin in Motor Shield, direction of the right wheel
const int PwmBPin = 6;  // corresponds pin 6 in Arduino to PwmBPin in Motor Shield, speed of the left wheel
const int DirBPin = 7;  // corresponds pin 7 in Arduino to DirBPin in Motor Shield, direction of the left wheel
const int RedLedPin = 13; // corresponds pin 13 in Arduino to Red LED
const int GreenLedPin = 12; // corresponds pin 12 on Arduino to Green LED
const int IR1Pin = A1; // corresponds pin A1 in Arduino to OUT1 in Tracking Sensor, the left IR sensor
const int IR2Pin = A2; // corresponds pin A2 in Arduino to OUT2 in Tracking Sensor, the middle left IR sensor
const int IR3Pin = A3; // corresponds pin A3 in Arduino to OUT3 in Tracking Sensor, the middle right IR sensor
const int IR4Pin = A4; // corresponds pin A4 in Arduino to OUT4 in Tracking Sensor, the right IR sensor


void setup()
{
  pinMode(PwmAPin, OUTPUT); // set PwmAPin as output
  pinMode(DirAPin, OUTPUT); // set DirAPin as output 
  pinMode(PwmBPin, OUTPUT); // set PwmBPin as output
  pinMode(DirBPin, OUTPUT); // set DirBPin as output
  pinMode(RedLedPin, OUTPUT); // set Red LED as output
  pinMode(GreenLedPin, OUTPUT); // set Green LED as output
  pinMode(IR1Pin, INPUT); // set IR1Pin as input
  pinMode(IR2Pin, INPUT); // set IR2Pin as input
  pinMode(IR3Pin, INPUT); // set IR3Pin as input
  pinMode(IR4Pin, INPUT); // set IR4Pin as input
}

void loop()
{
  int IR1PinValue = digitalRead(IR1Pin); //set the reading of IR1Pin as IR1PinValue
  int IR2PinValue = digitalRead(IR2Pin); //set the reading of IR2Pin as IR2PinValue
  int IR3PinValue = digitalRead(IR3Pin); //set the reading of IR3Pin as IR3PinValue
  int IR4PinValue = digitalRead(IR4Pin); //set the reading of IR4Pin as IR4PinValue
  
  
  if (IR1PinValue == 1 && IR2PinValue == 0 && IR3PinValue == 0 && IR4PinValue == 0) // "1" means the IR sensor detects the black line. "0" means it detects no black line.
  {
  	  elab.MotorSLeftTurn(PwmAPin, DirAPin, PwmBPin, DirBPin);
          elab.LedOn(GreenLedPin);
          elab.LedOff(RedLedPin);          
  }
  else if (IR2PinValue == 1 && IR3PinValue == 0 && IR4PinValue == 0)
  {
          elab.MotorLeftTurn(PwmAPin, DirAPin, PwmBPin, DirBPin);
          elab.LedOn(GreenLedPin);
          elab.LedOff(RedLedPin);    
  }
  else if (IR1PinValue == 0 && IR2PinValue == 0 && IR3PinValue == 1)
  {
  	  elab.MotorRightTurn(PwmAPin, DirAPin, PwmBPin, DirBPin);
          elab.LedOff(GreenLedPin);
          elab.LedOn(RedLedPin);    
  }
  else if (IR1PinValue == 0 && IR2PinValue == 0 && IR3PinValue == 0 && IR4PinValue == 1)
  {
  	  elab.MotorSRightTurn(PwmAPin, DirAPin, PwmBPin, DirBPin);
          elab.LedOff(GreenLedPin);
          elab.LedOn(RedLedPin);    
  }
  else 
  {
  	  elab.MotorForward(PwmAPin, DirAPin, 255);
  	  elab.MotorForward(PwmBPin, DirBPin, 255);
          elab.LedOn(GreenLedPin);
          elab.LedOn(RedLedPin);    
  }
}




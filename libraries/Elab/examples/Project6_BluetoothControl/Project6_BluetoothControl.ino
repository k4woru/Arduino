/*
Code for eBOT Z
by eLab Peers (C) 2015.

Visit us at:
http://www.elabpeers.com

All rights reserved.

Project 6 - Bluetooth Control
1.  The car can be controlled with computer or Android app via Bluetooth

Arduino Pins:
1.  Pin 8 to TXD of the Bluetooth Module
2.  Pin 9 to RXD of the Bluetooth Module
3.  Pin A0 to Left SpeedSensor
4.  Pin A5 to Right SpeedSensor
5.  Pin 13 to Red LED
6.  Pin 12 to Green LED

Wiring:
For the Bluetooth Module:
1.  Pin 8 to TXD of the Bluetooth Module
2.  Pin 9 to RXD of the Bluetooth Module
3.  VCC to 5V pin on Arduino
4.  GND to GND on Arduino

For the Speed Sensor Module:
1.  VCC to 5V pin on Arduino
2.  GND to GND on Arduino

For the power input and output of Motor Shield:
1.  VIN to +ve (red wire) of AA x 4 battery box
2.  GND to -ve (black wire) of AA x 4 battery box
3.  A+ to +ve of the right motor
4.  A- to -ve of the right motor
5.  B+ to -ve of the left motor
6.  B- to +ve of the left motor


Features:
1.  Full control of the car in Android app.
2.  It is also applicable for computers with Bluetooth Module, 
    Type "w" moving forward,
    Type "x" moving backward,
    Type "a" turning left,
    Type "d" turning right,
    Type "q" turning sharp left,
    Type "e" turning sharp right,
    Type "r" moving U-turn,
    Type "s" to stop.
*/

#include <Elab.h>
#include <SoftwareSerial.h> //We choose not to use the system serial on Arduino, so we include a library call "SoftwareSerial"

Elab elab;
SoftwareSerial BT(8, 9); //set the pin 8 on Arduino as RXD and pin 9 as TXD. Arduino will transmit the signal from TXD to RXD on Bluetooth Module, and receive with RXD from TXD on Bluetooth Module.

char command; //let "command" be a character value

const int DirAPin = 4;  // corresponds pin 4 in Arduino to DirAPin in Motor Shield, direction of the right wheel
const int PwmAPin = 5;  // corresponds pin 5 in Arduino to PwmAPin in Motor Shield, speed of the right wheel
const int PwmBPin = 6;  // corresponds pin 6 in Arduino to PwmBPin in Motor Shield, speed of the left wheel
const int DirBPin = 7;  // corresponds pin 7 in Arduino to DirBPin in Motor Shield, direction of the left wheel

const int SpdSenLPin = A0;
const int SpdSenRPin = A5;
const int RedLedPin = 13; // corresponds pin 13 in Arduino to Red LED
const int GreenLedPin = 12; // corresponds pin 12 on Arduino to Green LED

const int SpeedOffset = 0; // a more +ve number if you want it to lean left and vice versa
const int CountTurnAround = 7;
const int CountSharpTurn = 3;
const int CountTurn = 2;
const int blinktime = 800;

long SpeedDiff ;

const int SpeedSenSample = 6;
int SpeedR = 220;
int SpeedL = 220;

void setup()
{
  BT.begin (9600);
  pinMode(PwmAPin, OUTPUT); // set PwmAPin as output
  pinMode(DirAPin, OUTPUT); // set DirAPin as output
  pinMode(PwmBPin, OUTPUT); // set PwmBPin as output
  pinMode(DirBPin, OUTPUT); // set DirBPin as output
  pinMode(SpdSenLPin, INPUT);
  pinMode(SpdSenRPin, INPUT);
  pinMode(RedLedPin, OUTPUT); // set Red LED as output
  pinMode(GreenLedPin, OUTPUT); // set Green LED as output
}

void loop()
{
  if (BT.available() > 0)  //check if anything available with Bluetooth Module
  {
    command = BT.read(); //let "command" be the letter the Bluetooth Module reads
    switch (command) //the switch statement allows the robot moves accordingly if specific letter is received.
    { 
      case 'w': // if the Module reads the letter "w"
      elab.MotorForward(PwmAPin, DirAPin, SpeedL); 
      elab.MotorForward(PwmBPin, DirBPin, SpeedR); // the robot moves forward
      elab.LedOn(GreenLedPin);
      elab.LedOn(RedLedPin);
      break; //exit from the switch statement
      case 'x':
      elab.MotorBothBackward(PwmAPin, DirAPin, PwmBPin, DirBPin);
      elab.LedBlink(GreenLedPin, blinktime);
      elab.LedBlink(RedLedPin, blinktime);
      break;
      case 'a':
          LeftTurn();
      break;
      case 'd':
          RightTurn();  
      break;
      case 'q':
         SharpLeftTurn();
      break;
      case 'e':
         SharpRightTurn();   
      break;
      case 'r':
         UTurn();
      break;
      case 's':
        elab.MotorBothStop(PwmAPin, DirAPin, PwmBPin, DirBPin);
        elab.LedOff(GreenLedPin);
        elab.LedOff(RedLedPin);
      break;
    }
  }  
}
 

void LeftTurn()
{
    elab.MotorLeftTurn(PwmAPin, DirAPin, PwmBPin, DirBPin);
    elab.SpeedSenLRSpeedDiff(SpdSenLPin, SpdSenRPin, CountTurn);
    elab.MotorBothStop(PwmAPin, DirAPin, PwmBPin, DirBPin);
    elab.LedOn(GreenLedPin);
    elab.LedOff(RedLedPin);   
    delay(1000);
}

void SharpLeftTurn()
{
    elab.MotorSLeftTurn(PwmAPin, DirAPin, PwmBPin, DirBPin);
    elab.SpeedSenLRSpeedDiff(SpdSenLPin, SpdSenRPin, CountSharpTurn);
    elab.MotorBothStop(PwmAPin, DirAPin, PwmBPin, DirBPin);
    elab.LedOn(GreenLedPin);
    elab.LedOff(RedLedPin);   
    delay(1000);
}

void RightTurn()
{
    elab.MotorRightTurn(PwmAPin, DirAPin, PwmBPin, DirBPin);
    elab.SpeedSenLRSpeedDiff(SpdSenLPin, SpdSenRPin, CountTurn);
    elab.MotorBothStop(PwmAPin, DirAPin, PwmBPin, DirBPin);
    elab.LedOff(GreenLedPin);
    elab.LedOn(RedLedPin);
    delay(1000);
}

void SharpRightTurn()
{
    elab.MotorSRightTurn(PwmAPin, DirAPin, PwmBPin, DirBPin);
    elab.SpeedSenLRSpeedDiff(SpdSenLPin, SpdSenRPin, CountSharpTurn);
    elab.MotorBothStop(PwmAPin, DirAPin, PwmBPin, DirBPin);
    elab.LedOff(GreenLedPin);
    elab.LedOn(RedLedPin);
    delay(1000);
}

void UTurn()
{
    elab.MotorSLeftTurn(PwmAPin, DirAPin, PwmBPin, DirBPin);
    elab.SpeedSenLRSpeedDiff(SpdSenLPin, SpdSenRPin, CountTurnAround);
    elab.MotorBothStop(PwmAPin, DirAPin, PwmBPin, DirBPin);
    elab.LedOn(GreenLedPin);
    elab.LedOff(RedLedPin);   
    delay(2000);
}



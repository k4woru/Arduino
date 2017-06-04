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
5.  Pin 3 to TrigPin on Ultrasonic Sensor Module
6.  Pin 2 to echoPin on Ultrasonic Sensor Module


Wiring:
For the Speed Sensor Module:
1.  VCC to 5V pin on Arduino
2.  GND to GND on Arduino

For the servo:
1.  5V to 5V pin on Arduino
2.  GND to GND on Arduino

For the power input and output of Motor Shield:
1.  VIN to + (red wire) of AA x 4 battery box
2.  GND to - (black wire) of AA x 4 battery box
3.  A+ to + of the right motor
4.  A- to - of the right motor
5.  B+ to - of the left motor
6.  B- to + of the left motor

Features:

*/

#include<Elab.h>
#include <Servo.h> //We make use of Servo in library to control the servo with Ultrasonic Sensor

Elab elab;
Servo myservo; //let's name the servo "myservo"

const int DirAPin = 4;  // corresponds pin 4 in Arduino to DirAPin in Motor Shield, direction of the right wheel
const int PwmAPin = 5;  // corresponds pin 5 in Arduino to PwmAPin in Motor Shield, speed of the right wheel
const int PwmBPin = 6;  // corresponds pin 6 in Arduino to PwmBPin in Motor Shield, speed of the left wheel
const int DirBPin = 7;  // corresponds pin 7 in Arduino to DirBPin in Motor Shield, direction of the left wheel

const int SpdSenLPin = A0;
const int SpdSenRPin = A5;
const int RedLedPin = 13; // corresponds pin 13 in Arduino to Red LED
const int GreenLedPin = 12; // corresponds pin 12 on Arduino to Green LED
const int TrigPin = 3; //corresponds pin 3 on Arduino to TrigPin in Ultrasonic Sensor
const int echoPin = 2; //corresponds pin 2 on Arduino to echoPin in Ultrasonic Sensor


const int SpeedOffset = 0; // a more +ve number if you want it to lean left and vice versa
const int CountTurnAround = 7;
const int CountSharpTurn = 3;
const int CountTurn = 2;
const int blinktime = 800;

long SpeedDiff ;

const int SpeedSenSample = 6;
int SpeedR = 220;
int SpeedL = 220;
const int LAngle = 160;
const int RAngle = 20;

int pos = 90; //set initial position of the servo to 90 degree
const int ClearDistance = 30;
const int SharpTurnDistance = 10;
int Startup = 1;
int CurrentDistance = 50;

void setup()
{
  Serial.begin (9600);
  myservo.attach(10); //"myservo" corresponds pin 10 to the signal wire of the servo
  pinMode(TrigPin, OUTPUT); //set TrigPinPin as output
  pinMode(echoPin, INPUT); //set echoPinPin as input
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
  elab.setPwmFrequency(PwmAPin, 1);
  elab.setPwmFrequency(PwmBPin, 1);
  
  int LeftDistance = 0;
  int RightDistance = 0;
  
  while(Startup == 1) {
        myservo.write(90);
        delay(60000);
        myservo.detach();
        Startup = 0;
  }

  myservo.detach();
  delay(100);
  CurrentDistance = elab.UltrasonicSenDistance(TrigPin, echoPin);
  
  if ( CurrentDistance <= ClearDistance) //if the distance is shorter than the clear distance 30 cm
  {
    LeftDistance = TurnAndSenDistance(LAngle);
    RightDistance = TurnAndSenDistance(RAngle);
    myservo.attach(10);
    myservo.write(90);
    delay(60000);
    myservo.detach(); 
    delay(30000);
    TurnToDirection(RightDistance, LeftDistance);
    
    elab.MotorForward(PwmAPin, DirAPin, SpeedR);
    elab.MotorForward(PwmBPin, DirBPin, SpeedL);
    elab.LedOn(GreenLedPin);
    elab.LedOn(RedLedPin);
    SpeedDiff = elab.SpeedSenLRSpeedDiff(SpdSenLPin, SpdSenRPin, SpeedSenSample);
    SpeedR = elab.SpeedBalance(SpeedR, SpeedDiff, SpeedOffset);
  }
  else
  {
    elab.MotorForward(PwmAPin, DirAPin, SpeedR);
    elab.MotorForward(PwmBPin, DirBPin, SpeedL);
    elab.LedOn(GreenLedPin);
    elab.LedOn(RedLedPin);
    SpeedDiff = elab.SpeedSenLRSpeedDiff(SpdSenLPin, SpdSenRPin, SpeedSenSample);
    SpeedR = elab.SpeedBalance(SpeedR, SpeedDiff, SpeedOffset);      
  }
}
 

int TurnAndSenDistance(int ServoAngle) //if there is obstacle, the servo will move to the right and left and measure the distance
{
  elab.MotorBothStop(PwmAPin, DirAPin, PwmBPin, DirBPin); //stop the robot 
  delay(5000);
  myservo.attach(10);
  myservo.write(ServoAngle); //move the servo
  delay(80000);
  myservo.detach();
  delay(10000);
  return elab.UltrasonicSenDistance(TrigPin, echoPin); //check the distance
 
}


void TurnToDirection(int RightDistance, int LeftDistance) //compare the distance of two sides and make decision
{
  if (RightDistance < ClearDistance & LeftDistance < ClearDistance)
  {
      UTurn();
  }
  else if(RightDistance < SharpTurnDistance & LeftDistance > ClearDistance) 
  {
      SharpLeftTurn();
  }
  else if(LeftDistance < SharpTurnDistance & RightDistance > ClearDistance) 
  {
      SharpRightTurn();
  }
  else if(RightDistance > LeftDistance) //if the distance on the right is greter than left
  {
      RightTurn();
  }
  else if(LeftDistance > RightDistance) //if the distance on the left is greater than right
  {
      LeftTurn();
  }
  else
  {
    delay(1000);
  }
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

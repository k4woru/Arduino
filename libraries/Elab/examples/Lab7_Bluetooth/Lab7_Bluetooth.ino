/*

Test code for eBOT Z
by eLab Peers (C) 2015.

Visit us at:
http://www.elabpeers.com

All rights reserved.

Lab 7 - Testing and Learn Bluetooth Functions

Arduino Pins:
All pins on Arduino are connected with Motor Shield already.

1.  Pin 8 to TXD of the Bluetooth Module
2.  Pin 9 to RXD of the Bluetooth Module
*  TXD stands for Transmitted Data
*  RXD stands for Received Data

Wiring:
For the Bluetooth Module:
1.  Pin 8 to TXD of the Bluetooth Module
2.  Pin 9 to RXD of the Bluetooth Module
3.  VCC to 5V pin on Arduino
4.  GND to GND on Arduino

For the power input and output of Motor Shield:
1.  VIN to + (red wire) of AA x 4 battery box
2.  GND to - (black wire) of AA x 4 battery box
3.  A+ to + of the right motor
4.  A- to - of the right motor

Features:
1.  The motor moves when press START in Android app and stop when press STOP.
2.  It is also applicable for computers with Bluetooth Module, type "w" to start and "s" to stop.
*/

#include <Elab.h>
#include <SoftwareSerial.h> //We choose not to use the system serial on Arduino, so we include a library call "SoftwareSerial"

Elab elab;
SoftwareSerial BT(8, 9); //set the pin 8 on Arduino as RXD and pin 9 as TXD. Arduino will transmit the signal from TXD to RXD on Bluetooth Module, and receive with RXD from TXD on Bluetooth Module.


char command; //let "command" be a character value
int PwmAPin = 5;  // corresponds pin 5 in Arduino to PwmAPin in Motor Shield, speed of the right wheel
int DirAPin = 4;  // corresponds pin 4 in Arduino to DirAPin in Motor Shield, direction of the right wheel

void setup()
{
  BT.begin (9600); //set the baud rate communicated with the Bluetooth Module
  pinMode(PwmAPin, OUTPUT); // set PwmAPin as output
  pinMode(DirAPin, OUTPUT); // set DirAPin as output
}


void loop()
{
  if (BT.available() > 0)  //check if anything available with Bluetooth Module
  {
    command = BT.read(); //let "command" be the letter the Bluetooth Module reads
    switch (command) //the switch statement allows the robot moves accordingly if specific letter is received.
    { 
      case 'w': // if the Module reads the letter "w"
      elab.MotorForward(PwmAPin, DirAPin, 250); // the robot moves forward
      break; //exit from the switch statement
      case 's':
      elab.MotorStop(PwmAPin, DirAPin);
      break;
    }
  }
}




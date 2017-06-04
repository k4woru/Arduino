/*

Test code for LED
by eLab Peers (C) 2015.

Visit us at:
http://www.elabpeers.com

All rights reserved.

Lab 1 - Testing and Learn LED Functions
1. Led On Function
2. Led Off Function
3. Using Elab library functions

Wiring:
1.  GND to -ve of the LED (shorter leg)
2.  +ve of the LED (longer leg) to resistor 
3.  Pin 13 to another end of resistor

Features:
1.  Test LED blinks.
*/


//Libraries Setup
#include <Elab.h>    // to include needed functions from eLab Peers library 

Elab elab;             // define/create elab object to call functions from eLab Peers 

//Variable Definition
const int LedPin = 13;       // define PIN 13 as Led connected PIN
int blinktime = 1000;  // set blinktime to 1000

//Main setup 
void setup()        
{                
	pinMode(LedPin, OUTPUT);   // define Led connected PIN as an output from Arduino
}

//Main Loop
void loop(){
  	elab.LedOn(LedPin);            // Turns LED on 
        delay(5000);
  	elab.LedOff(LedPin);           // Turns LED off
  	delay(5000);  
  	elab.LedBlink(LedPin, blinktime);    // Blinks LED with 1000 delay
}

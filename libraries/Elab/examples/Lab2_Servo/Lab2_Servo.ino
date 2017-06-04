/*

Test code for Servo
by eLab Peers (C) 2015.

Visit us at:
http://www.elabpeers.com

All rights reserved.

Lab 2 - Servo
1. Using servo library (Arduino Library)
2. Turning servo to a desired angle
3. Detaching servo to stop servo noise
4. Arduino "For loop"

Wiring:
1.  5V to +ve (red wire) of the servo
2.  GND to -ve (black wire) of the servo
3.  Pin 10 to yellow wire of the servo

Features:
1.  Test the servo rotates properly
2.  It should rotates from 0 degree to 180 degree and back to 0 degree repeatedly.
*/

//Libraries Setup
#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 

//Variable Definition 
const int ServoPin = 10; 
int pos = 0;        // variable to store the servo position 

//Main setup
void setup() 
{ 
  myservo.attach(ServoPin);  // attaches the servo on pin 9 to the servo object 
} 
 
//Main Loop
void loop() 
{ 
  myservo.write(180); 
  delay(1000); 
  myservo.write(90); 
  delay(1000); 
  myservo.write(0);
  delay(1000); 
  
  myservo.detach();                  // pay attention servo noise goes away when the servo is detached
  delay(1000); 
  
  myservo.attach(ServoPin); 
  delay(1000); 
  
  for(pos = 0; pos < 180; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  for(pos = 180; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
} 

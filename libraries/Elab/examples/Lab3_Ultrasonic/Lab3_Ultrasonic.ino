/*

Test code for Ultrasonic Sensor
by eLab Peers (C) 2015.

Visit us at:
http://www.elabpeers.com

All rights reserved.

Lab 3 - Ultrasonic
1. Testing and Using Ultrasonic
2. Using Arduino Global Variable 
3. Using Function with return value

Wiring:
1.  5V to VCC on Ultrasonic Sensor
2.  GND to GND on Ultrasonic Sensor
3.  Pin 2 to Echo on Ultrasonic Sensor
4.  Pin 3 to Trig on Ultrasonic Sensor

Features:
1.  Open Serial Monitor and it shows the distance between Ultrasonic Sensor and object.
*/

#include <Elab.h>
  
Elab elab;


const int TrigPin = 3;
const int EchoPin = 2;

void setup() 
{
  Serial.begin (9600);
  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);
}

void loop() 
{
  Serial.print(elab.UltrasonicSenDistance(TrigPin, EchoPin));
  Serial.println(" cm");
  delay(500); 
}




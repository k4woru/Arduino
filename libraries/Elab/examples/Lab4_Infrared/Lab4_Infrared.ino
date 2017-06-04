/*

Test code for 4-Channel IR Sensor
by eLab Peers (C) 2015.

Visit us at:
http://www.elabpeers.com

All rights reserved.

Lab 4 - 4-Channel IR Sensor

Arduino Pins:
1.  Pin A1 to OUT1 on control board of Tracking Sensor
2.  Pin A2 to OUT2 on control board of Tracking Sensor
3.  Pin A3 to OUT3 on control board of Tracking Sensor
4.  Pin A4 to OUT4 on control board of Tracking Sensor

Wiring:
For the control board of the Tracking Sensor:
1.  VCC to 5V pin on Arduino
2.  GND to GND on Arduino

For the IR Sensors to the control board:
1.  The left IR sensor to Sig1
2.  The middle left IR sensor to Sig2
3.  The middle right IR sensor to Sig3
4.  The right IR sensor to Sig4
5.  All VCC and GND connected accordingly

For the power input of Arduino:
Connect the power jack on Arduino to the 9V battery box

Features:
From Serial Monitor, 
each IR detector would report 1 if white surface is detected.
And, 0 if dark surface is detected.
*/

const int IR1Pin = A1; // corresponds pin A1 in Arduino to OUT1 in Tracking Sensor, the left IR sensor
const int IR2Pin = A2; // corresponds pin A2 in Arduino to OUT2 in Tracking Sensor, the middle left IR sensor
const int IR3Pin = A3; // corresponds pin A3 in Arduino to OUT3 in Tracking Sensor, the middle right IR sensor
const int IR4Pin = A4; // corresponds pin A4 in Arduino to OUT4 in Tracking Sensor, the right IR sensor

void setup()
{
  Serial.begin (9600);
  
  pinMode(IR1Pin, INPUT); // set IR1Pin as input
  pinMode(IR2Pin, INPUT); // set IR2Pin as input
  pinMode(IR3Pin, INPUT); // set IR3Pin as input
  pinMode(IR4Pin, INPUT); // set IR4Pin as input
}

void loop()
{
  IRRead();
  delay(1000);
}

void IRRead()
{
  int IR1PinValue = digitalRead(IR1Pin); //set the reading of IR1Pin as IR1PinValue
  Serial.print("IR1Pin :");
  Serial.println(IR1PinValue);

  int IR2PinValue = digitalRead(IR2Pin); //set the reading of IR2Pin as IR2PinValue
  Serial.print("IR2Pin :");
  Serial.println(IR2PinValue);  

  int IR3PinValue = digitalRead(IR3Pin); //set the reading of IR3Pin as IR3PinValue
  Serial.print("IR3Pin :");
  Serial.println(IR3PinValue);  

  int IR4PinValue = digitalRead(IR4Pin); //set the reading of IR4Pin as IR4PinValue
  Serial.print("IR4Pin :");
  Serial.println(IR4PinValue);
  
  if (IR1PinValue == 1 && IR2PinValue == 0 && IR3PinValue == 0 && IR4PinValue == 0) // "1" means the IR sensor detects the black line. "0" means it detects no black line.
  {
    Serial.println("Sharp Left Turn");
  }
  else if (IR1PinValue == 1 && IR2PinValue == 1 && IR3PinValue == 0 && IR4PinValue == 0)
  {
    Serial.println("Left Turn");
  }
  else if (IR1PinValue == 0 && IR2PinValue == 1 && IR3PinValue == 0 && IR4PinValue == 0)
  {
    Serial.println("Left Turn");
  }
    else if (IR1PinValue == 0 && IR2PinValue == 0 && IR3PinValue == 1 && IR4PinValue == 0)
  {
    Serial.println("Right Turn");
  }
    else if (IR1PinValue == 0 && IR2PinValue == 0 && IR3PinValue == 1 && IR4PinValue == 1)
  {
    Serial.println("Right Turn");
  }
  else if (IR1PinValue == 0 && IR2PinValue == 0 && IR3PinValue == 0 && IR4PinValue == 1)
  {
    Serial.println("Sharp Right Turn");
  }
  else 
  {
    Serial.println("Forward");
  }
}

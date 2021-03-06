/*
by eLab Peers (C) 2014.

Visit us at:
http://www.elabpeers.com

All rights reserved.
 */

#include "Elab.h"
#include "Arduino.h"

#include <stdio.h>
#include <string.h>
#include <inttypes.h>

/*
Elab::Elab()
{ 
	// No Initialization if no robot is defined
}*/

// LED
void Elab::LedOn(uint8_t LedPin)
{    
	digitalWrite(LedPin, HIGH);  
    delay(10);
}

void Elab::LedOff(uint8_t LedPin)
{    
	digitalWrite(LedPin, LOW);  
    delay(10);
}

void Elab::LedBlink(uint8_t LedPin, uint8_t time)
{    
	digitalWrite(LedPin, HIGH);  
    delay(time);   
	digitalWrite(LedPin, LOW);  
    delay(time);
}

//Ultrasonic
uint8_t	 Elab::UltrasonicSenDistance(uint8_t TrigPin, uint8_t EchoPin)
{    
	const unsigned long timeout = 99999;
	long duration, distance;
	digitalWrite(TrigPin, LOW);  
	delayMicroseconds(2); 

	digitalWrite(TrigPin, HIGH);
	delayMicroseconds(10); 
	digitalWrite(TrigPin, LOW);
	duration = pulseIn(EchoPin, HIGH, timeout);
	distance = (duration/2) / 29.1;
	if (distance > 4000)
    distance = 0;
    
  	return distance;
}

//MotorShield

void Elab::MotorForward(uint8_t PwmPin, uint8_t DirPin, uint8_t Speed)           
{
  setPwmFrequency(PwmPin,1);
  digitalWrite(DirPin,HIGH); //DirAPin is HIGH means the right wheel moves forward, and vice versa.
  analogWrite(PwmPin, Speed);   //PWM Speed Control
  delay(1000);
}

void Elab::MotorBothForward(uint8_t PwmAPin, uint8_t DirAPin, uint8_t PwmBPin, uint8_t DirBPin)           
{
  digitalWrite(DirAPin,HIGH); 
  digitalWrite(PwmAPin, HIGH);  
  digitalWrite(DirBPin,HIGH); 
  digitalWrite(PwmBPin, HIGH);   
  delay(1000);
}

void Elab::MotorBackward(uint8_t PwmPin, uint8_t DirPin)    
{
  digitalWrite(DirPin,LOW);     
  digitalWrite(PwmPin,HIGH);
  delay(1000);
}


void Elab::MotorBothBackward(uint8_t PwmAPin, uint8_t DirAPin, uint8_t PwmBPin, uint8_t DirBPin)           
{
  digitalWrite(DirAPin, LOW); 
  digitalWrite(PwmAPin, HIGH);  
  digitalWrite(DirBPin, LOW); 
  digitalWrite(PwmBPin, HIGH);   
  delay(1000);
}
void Elab::MotorStop(uint8_t PWM, uint8_t DIR)    
{
  digitalWrite(DIR,LOW);     
  digitalWrite(PWM,LOW);
  delay(1000);
}

void Elab::MotorBothStop(uint8_t PwmAPin, uint8_t DirAPin, uint8_t PwmBPin, uint8_t DirBPin)    
{
  digitalWrite(DirAPin,LOW);     
  digitalWrite(PwmAPin,LOW);
  digitalWrite(DirAPin,LOW);     
  digitalWrite(PwmBPin,LOW);
  delay(1000);
}

void Elab::MotorRightTurn(uint8_t PwmAPin, uint8_t DirAPin, uint8_t PwmBPin, uint8_t DirBPin)
{
  digitalWrite(DirAPin,LOW);     
  digitalWrite(PwmAPin,LOW); 
  digitalWrite(DirBPin,HIGH);
  digitalWrite(PwmBPin,HIGH); 
}

void Elab::MotorSRightTurn(uint8_t PwmAPin, uint8_t DirAPin, uint8_t PwmBPin, uint8_t DirBPin)
{
  digitalWrite(DirAPin,LOW);     
  digitalWrite(PwmAPin,HIGH); 
  digitalWrite(DirBPin,HIGH);
  digitalWrite(PwmBPin,HIGH); 
}

void Elab::MotorLeftTurn(uint8_t PwmAPin, uint8_t DirAPin, uint8_t PwmBPin, uint8_t DirBPin)
{
  digitalWrite(DirAPin,HIGH);     
  digitalWrite(PwmAPin,HIGH);
  digitalWrite(DirBPin,LOW);
  digitalWrite(PwmBPin,LOW); 
}

void Elab::MotorSLeftTurn(uint8_t PwmAPin, uint8_t DirAPin, uint8_t PwmBPin, uint8_t DirBPin)
{
  digitalWrite(DirAPin,HIGH);     
  digitalWrite(PwmAPin,HIGH);
  digitalWrite(DirBPin,LOW);
  digitalWrite(PwmBPin,HIGH); 
}

void Elab::MotorLineFollow(uint8_t PwmAPin, uint8_t DirAPin, uint8_t PwmBPin, uint8_t DirBPin, uint8_t IR1Pin, uint8_t IR2Pin, uint8_t IR3Pin, uint8_t IR4Pin)
{
  uint8_t IR1PinValue = digitalRead(IR1Pin); //set the reading of IR1Pin as IR1PinValue
  uint8_t IR2PinValue = digitalRead(IR2Pin); //set the reading of IR2Pin as IR2PinValue
  uint8_t IR3PinValue = digitalRead(IR3Pin); //set the reading of IR3Pin as IR3PinValue
  uint8_t IR4PinValue = digitalRead(IR4Pin); //set the reading of IR4Pin as IR4PinValue
  if (IR1PinValue == 1 && IR2PinValue == 0 && IR3PinValue == 0 && IR4PinValue == 0) // "1" means the IR sensor detects the black line. "0" means it detects no black line.
  {
  	  MotorSLeftTurn(PwmAPin, DirAPin, PwmBPin, DirBPin);
  }
  else if (IR1PinValue == 1 && IR2PinValue == 1 && IR3PinValue == 0 && IR4PinValue == 0)
  {
      MotorLeftTurn(PwmAPin, DirAPin, PwmBPin, DirBPin);
  }
  else if (IR1PinValue == 0 && IR2PinValue == 1 && IR3PinValue == 0 && IR4PinValue == 0)
  {
  	  MotorLeftTurn(PwmAPin, DirAPin, PwmBPin, DirBPin);
  }
    else if (IR1PinValue == 0 && IR2PinValue == 0 && IR3PinValue == 1 && IR4PinValue == 0)
  {
  	  MotorRightTurn(PwmAPin, DirAPin, PwmBPin, DirBPin);
  }
    else if (IR1PinValue == 0 && IR2PinValue == 0 && IR3PinValue == 1 && IR4PinValue == 1)
  {
  	  MotorRightTurn(PwmAPin, DirAPin, PwmBPin, DirBPin);
  }
  else if (IR1PinValue == 0 && IR2PinValue == 0 && IR3PinValue == 0 && IR4PinValue == 1)
  {
  	  MotorSRightTurn(PwmAPin, DirAPin, PwmBPin, DirBPin);
  }
  else 
  {
  	  MotorForward(PwmAPin, DirAPin, 255);
  	  MotorForward(PwmBPin, DirBPin, 255);
  }
}



//Speed Senor

long Elab::SpeedSenLRSpeedDiff(uint8_t SpeedSenL, uint8_t SpeedSenR, uint8_t NumOfSampels)
{
  const unsigned long timeout = 30000;
  
  long  diff =0;
  uint8_t   index = 0;                              // the index of the current reading
   
  unsigned long readingsL[NumOfSampels];      // the readings from the analog input
  unsigned long totalL = 0;                  // the running total
  unsigned long averageL = 0;                // the average
  unsigned long durationL = 0;

  unsigned long readingsR[NumOfSampels];      // the readings from the analog input
  unsigned long totalR = 0;                  // the running total
  unsigned long averageR = 0;                // the average
  unsigned long durationR = 0;
 
  for (index = 0; index < NumOfSampels; index++) {
    Serial.print("Index:  ");
    Serial.println(index);     
    
    durationR= pulseIn(SpeedSenR, HIGH, timeout);
    readingsR[index] = durationR; 
    Serial.print("right duration:  ");
    Serial.println(durationR); 

    durationL= pulseIn(SpeedSenL, HIGH, timeout);
    readingsL[index] = durationL; 
    Serial.print("left duration:  ");
    Serial.println(durationL);  
  
    totalL= totalL + readingsL[index];       
    totalR= totalR + readingsR[index];    
  }
  
  averageL = totalL / NumOfSampels;
  totalL = 0;
  averageR = totalR / NumOfSampels;
  totalR = 0;
  diff = averageL-averageR;
  return diff; 
} 

int Elab::SpeedBalance(int SelfSpeed, int SenseSpeed, int SpeedOffset)
{
  uint8_t NewSpeed;
  
  if ((SenseSpeed > SpeedOffset) & (SelfSpeed > 195))
      {
        NewSpeed = SelfSpeed - 5;
      }
  else if ((SenseSpeed < SpeedOffset) & (SelfSpeed < 255))
      {
        NewSpeed = SelfSpeed + 5;
      }
  else
      {
        NewSpeed = SelfSpeed;
      }
  return NewSpeed;
}


void Elab::setPwmFrequency(uint8_t pin, uint8_t divisor) {
  byte mode;
  if(pin == 5 || pin == 6 || pin == 9 || pin == 10) {
    switch(divisor) {
      case 1: mode = 0x01; break;
      case 8: mode = 0x02; break;
      case 64: mode = 0x03; break;
      case 256: mode = 0x04; break;
      case 1024: mode = 0x05; break;
      default: return;
    }
    if(pin == 5 || pin == 6) {
      TCCR0B = TCCR0B & 0b11111000 | mode;
    } else {
      TCCR1B = TCCR1B & 0b11111000 | mode;
    }
  } else if(pin == 3 || pin == 11) {
    switch(divisor) {
      case 1: mode = 0x01; break;
      case 8: mode = 0x02; break;
      case 32: mode = 0x03; break;
      case 64: mode = 0x04; break;
      case 128: mode = 0x05; break;
      case 256: mode = 0x06; break;
      case 1024: mode = 0x7; break;
      default: return;
    }
    TCCR2B = TCCR2B & 0b11111000 | mode;
  }
}


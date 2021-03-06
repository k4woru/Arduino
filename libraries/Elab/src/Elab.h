/*
by eLab Peers (C) 2014.

Visit us at:
http://www.elabpeers.com

All rights reserved.
*/

// ensure this library description is only included once
#ifndef Elab_h
#define Elab_h

#include <inttypes.h>
// library uint8_terface description
class Elab{
  public:
  	 
  	// Elab();
    
  	// LED Functions:
    void LedOn(uint8_t LedPin);
  	void LedOff(uint8_t LedPin);
  	void LedBlink(uint8_t LedPin, uint8_t LedBlinkTime);
  	
  	// Ultrasonic Functions:
  	uint8_t	 UltrasonicSenDistance(uint8_t TrigPin, uint8_t EchoPin);
  	
  	// Motor Shield Functions:
  	void MotorForward(uint8_t PwmPin, uint8_t DirPin, uint8_t Speed);           
  	void MotorBackward(uint8_t PwmPin, uint8_t DirPin); 
  	void MotorStop(uint8_t PwmPin, uint8_t DirPin);    
  	void MotorLeftTurn(uint8_t PwmAPin, uint8_t DirAPin, uint8_t PwmBPin, uint8_t DirBPin);
  	void MotorSLeftTurn(uint8_t PwmAPin, uint8_t DirAPin, uint8_t PwmBPin, uint8_t DirBPin);
   	void MotorRightTurn(uint8_t PwmAPin, uint8_t DirAPin, uint8_t PwmBPin, uint8_t DirBPin);
  	void MotorSRightTurn(uint8_t PwmAPin, uint8_t DirAPin, uint8_t PwmBPin, uint8_t DirBPin);	
	void MotorLineFollow(uint8_t PwmAPin, uint8_t DirAPin, uint8_t PwmBPin, uint8_t DirBPin, uint8_t IR1Pin, uint8_t IR2Pin, uint8_t IR3Pin, uint8_t IR4Pin);
	void MotorBothForward(uint8_t PwmAPin, uint8_t DirAPin, uint8_t PwmBPin, uint8_t DirBPin);   
  	void MotorBothBackward(uint8_t PwmAPin, uint8_t DirAPin, uint8_t PwmBPin, uint8_t DirBPin);
  	void MotorBothStop(uint8_t PwmAPin, uint8_t DirAPin, uint8_t PwmBPin, uint8_t DirBPin);
  	
  	//Speed Encoder
  	long SpeedSenLRSpeedDiff(uint8_t SpdSenLPin, uint8_t SpdSenRPin, uint8_t numReadings);
  	int  SpeedBalance(int SelfSpeed, int SenseSpeed, int SpeedOffset);
  	
  	//Other
  	void setPwmFrequency(uint8_t pin, uint8_t divisor);
  		
  private:

};

#endif


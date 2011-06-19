/*
 * PWM.cpp
 *
 *  Created on: May 11, 2011
 *      Author: dejagerd
 */
#include "PWM.h"

void PWMinit(){
	TCCR0A 	= 0
			| _BV(COM0B0)
			| _BV(COM0B1)//set OC0B on compare match
			|_BV(WGM01)		//set timer mode 7 (fastpwm /w OCRA as TOP) Bit1
			|_BV(WGM00);	//Bit0
	OCR0A	= 255;			//Timer runs at 8MHz/256 = ~ 31tkHz
	TCCR0B 	= 0
			|_BV(WGM02)		//set timer mode 7 (fastpwm /w OCRA as TOP) Bit2
			|_BV(CS00); 	//set clock source no scaling
	DDRD 	= 0x60; 		//enable output on pwm pin
	PORTD	&= ~0x60;
	//OCR0B	= 0x80;
}
void PWMsetDutyCycle(uint8_t duty){
	OCR0B = duty;
}
uint8_t PWMgetDutyCycle(){
	return OCR0B;
}

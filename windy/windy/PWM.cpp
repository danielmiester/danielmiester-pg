/*
 * PWM.cpp
 *
 *  Created on: May 11, 2011
 *      Author: dejagerd
 */
#include "PWM.h"
void PWMinit(){
	TCCR0A 	= 0
			| _BV(COM0A1)//clear OC0B on compare match
			|_BV(WGM01)		//set timer mode 7 (fastpwm /w OCRA as TOP) Bit1
			|_BV(WGM00);	//Bit0
	OCR0A	= 0xff;			//Timer runs at 16MHz/256 = ~ 62kHz
	TCCR0B 	= 0
			|_BV(WGM02)		//set timer mode 7 (fastpwm /w OCRA as TOP) Bit2
			|_BV(CS00); 	//set clock source no scaling
	DDRD 	= 0x40; 		//enable output on pwm pin
}
void PWMsetDutyCycle(uint8_t duty){
	OCR0B = duty;
}
uint8_t PWMgetDutyCycle(){
	return OCR0B;
}

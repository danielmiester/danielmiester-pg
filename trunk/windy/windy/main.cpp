/*
 * main.c
 *
 *  Created on: Mar 15, 2011
 *      Author: dejagerd
 */

#include "main.h"
#include "ADC.h"
#include "PWM.h"
void init1(void)
{
	init();
	Serial.begin(9600);
	ADCinit();
	ADCstart();
	PWMinit();
	DDRB = 0x20;
}


int main(void) {
	char * s = (char *)malloc( 17);
	while (1) {
		if(ADCdataFresh == 3){
			ADCdataFresh = 0;
			PWMsetDutyCycle(ADCdata[0]>>8);
			sprintf(s,"%04x|%04x\n",ADCdata[0],ADCdata[1]);
			Serial.write(s);
			delay(100);
			ADCstart();
		}

	}
}

/*
 * main.c
 *
 *  Created on: Mar 15, 2011
 *      Author: dejagerd
 */

#include "WProgram.h"
#include "main.h"
//#include "c++compat.h"
#include "ADC.h"
void init1(void)
{
	init();
	Serial.begin(9600);
	ADCinit();
	ADCstart();
	DDRB = 0x20;
}


int main(void) {
	char * s = (char *)malloc( 17);
	while (1) {
		if(ADCdataFresh == 3){
			ADCdataFresh = 0;
			sprintf(s,"%04x|%04x\n",ADCdata[0],ADCdata[1]);
			Serial.write(s);
			delay(100);
			ADCstart();
		}

	}
}

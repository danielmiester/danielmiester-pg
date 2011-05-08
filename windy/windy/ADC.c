/*
 * ADC.cpp
 *
 *  Created on: May 7, 2011
 *      Author: dejagerd
 */
#include "ADC.h"
//#include <stdlib.h>
#include "WProgram.h"
//#include <limits.h>
//char ADCchannel = 0;
//volatile int ADCData[2] = {0,0};

void ADCinit(){
	DIDR0 = 0x3f;		//disable Digital buffers on all Analog inputs
	ADCSRB =  0;		//MUX is not used for analog comparator
						//free running
	ADMUX =   0 <<REFS0 // Set to external reference source
			| 1 <<ADLAR // Left adjust the result
			| 0; 		// select input 0
	ADCSRA =  1 << ADEN		//enable ADC
			| 1 << ADATE	//enable autotriggering
			| 1 << ADSC		//trigger first conversion;
//			| 1 << ADIE		//enable interrupts
			| 6;			//prescale by 64 for ADC speed of 250kHz

	ADCSRA |= ADSC;		//start ADC Running.
	delayMicroseconds(ADC_1ST_CONVERSION_DELAY);
}
void ADCgetSamples(){



}
//ISR(ADC_vect,ISR_NOBLOCK){
//	ADCSRA |=((char)(1<< ADIF));
//	ADMUX ^= ((char)0x01);
//	if(ADMUX % 2)
//		ADCSRA
//}

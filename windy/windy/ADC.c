/*
 * ADC.cpp
 *
 *  Created on: May 7, 2011
 *      Author: dejagerd
 */
#include "ADC.h"
//#include <stdlib.h>
#include "WProgram.h"
#include "wiring_private.h"
//#include "util/atomic.h"
//#include <limits.h>
//char ADCchannel = 0;
//volatile int ADCData[2] = {0,0};
volatile uint16_t ADCdata[ADC_CHANNELS];// = {0,0};
//uint8_t low,high,channel;


void ADCinit() {
	DIDR0 = 0x3f; //disable Digital buffers on all Analog inputs
	DDRC = 0;
	PORTC = 0;
	ADMUX = 1 << REFS0 // Set to external reference source
			| 1 << ADLAR // Left adjust the result
			| 0; // select input 0
	ADCSRA = 1 << ADEN //enable ADC
			| 6; //prescale by 64 for ADC speed of 250kHz
}
void ADCstart() {
	ADCSRA |= 1 << ADSC //trigger conversion;
			| 1 << ADIE; //enable interrupts
}

volatile uint8_t ADCdataFresh;
ISR(ADC_vect)
{
	if (bit_is_set(ADCSRA,ADIE)) {
		PORTB ^= 0x20;
		low = ADCL;
		high = ADCH;
		ADCdata[channel] = (high << 8) | low;
		ADCdataFresh |= (uint8_t) (1 << channel);

		if (++channel == ADC_CHANNELS) {
			channel = 0;
			bitClear(ADCSRA,ADIE);
		}

		ADMUX = (ADMUX & 0xF0) | channel; // Set to next channel

		ADCSRA |= _BV(ADSC); // Start next conversion}
	}
}


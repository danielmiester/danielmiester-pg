/*
 * ADC.cpp
 *
 *  Created on: May 7, 2011
 *      Author: dejagerd
 */
#include "ADC.h"
//char ADCchannel = 0;
//volatile int ADCData[2] = {0,0};
volatile int32_t ADCdata[ADC_CHANNELS];// = {0,0};
//volatile uint8_t low,high,channel;
int16_t ADCVref = -1;

void ADCinit() {
	DIDR0 = 0x3f; //disable Digital buffers on all Analog inputs
	DDRC = 0;
	PORTC = 0;
	//PORTD |= 0x80;
	if (PIND & 0x80) {
		ADMUX = //_BV(REFS0)|//_BV(REFS1)| // Set to external reference source
				0; // select input 0

	} else {
		ADMUX = 0 | _BV(REFS0);
	}

	ADCSRA = _BV(ADEN) //enable ADC
			| 5; //prescale by 32 for ADC speed of 250kHz
}
void ADCstart() {
	ADCSRA |= _BV(ADSC) //trigger conversion;
			| _BV(ADIE); //enable interrupts
}

volatile uint8_t ADCdataFresh;
ISR(ADC_vect,ISR_NOBLOCK)
{
	++ticks;
	if (bit_is_set(ADCSRA,ADIE)) {
		ADCdata[channel] = ADCW;
		ADCdataFresh |= (uint8_t) (1 << channel);

		if (++channel == ADC_CHANNELS) {
			channel = 0;
			bitClear(ADCSRA,ADIE);
		}

		ADMUX = (ADMUX & 0xF0) | channel; // Set to next channel

		ADCSRA |= _BV(ADSC); // Start next conversion}
	}
}


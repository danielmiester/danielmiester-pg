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
	ADMUX = _BV(REFS0) // Set to external reference source
			//| _BV(ADLAR) // Left adjust the result
			| 0; // select input 0
	ADCSRA = _BV(ADEN) //enable ADC
			| 6; //prescale by 64 for ADC speed of 250kHz
}
void ADCcalibrate(){
	char old = ADMUX;
	ADMUX = 0x0e;//select internal VREF;
	ADCSRA |= _BV(ADSC);//start conversion
	loop_until_bit_is_clear(ADCSRA,ADSC);
	ADCVref = ADCW;
	printf("\e[4;0H%4.4x",ADCVref);
	ADMUX = old;
}
float ADCgetAVREF(){
	return BANDGAP*1024.0/ADCVref;
}
void ADCstart() {
	ADCSRA |= _BV(ADSC) //trigger conversion;
			| _BV(ADIE); //enable interrupts
}

volatile uint8_t ADCdataFresh;
ISR(ADC_vect)
{
	if (bit_is_set(ADCSRA,ADIE)) {
		PORTB ^= 0x20;
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


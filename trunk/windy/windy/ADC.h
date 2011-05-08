/*
 * ADC.h
 *
 *  Created on: May 7, 2011
 *      Author: dejagerd
 */

#ifndef ADC_H_
#define ADC_H_
#include "WProgram.h"
#define CLOCKCYCLES_PER_ADC_CYCLE 64
#define ADC_1STCONVERSION_CYCLES 25 * CLOCKCYCLES_PER_ADC_CYCLE
#define ADC_2NDCONVERSION_CYCLES 13 * CLOCKCYCLES_PER_ADC_CYCLE
#define ADC_1ST_CONVERSION_DELAY clockCyclesToMicroseconds((ADC_1STCONVERSION_CYCLES))
#define ADC_2ND_CONVERSION_DELAY clockCyclesToMicroseconds((ADC_2NDCONVERSION_CYCLES))
//uint8_t ADCchannel = 0;
//volatile uint16_t ADCdata[2];
void ADCinit();
void ADCgetSamples() __attribute__((always_inline));


#endif /* ADC_H_ */

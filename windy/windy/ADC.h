/*
 * ADC.h
 *
 *  Created on: May 7, 2011
 *      Author: dejagerd
 */

#ifndef ADC_H_
#define ADC_H_
#include "commonincludes.h"

#ifdef __cplusplus
extern "C"{
#endif

#define ADC_CHANNELS 2
//#define CLOCKCYCLES_PER_ADC_CYCLE 64
//#define ADC_1STCONVERSION_CYCLES 25 * CLOCKCYCLES_PER_ADC_CYCLE
//#define ADC_2NDCONVERSION_CYCLES 13 * CLOCKCYCLES_PER_ADC_CYCLE
//#define ADC_1ST_CONVERSION_DELAY clockCyclesToMicroseconds((ADC_1STCONVERSION_CYCLES))
//#define ADC_2ND_CONVERSION_DELAY clockCyclesToMicroseconds((ADC_2NDCONVERSION_CYCLES))
#define BANDGAP 1.092
extern volatile int32_t ADCdata[];
extern volatile uint8_t ADCdataFresh;
static volatile  uint8_t channel;
extern int16_t ADCVref;

void ADCinit();
void ADCstart();
void ADCcalibrate();
float ADCgetAVREF();
#ifdef __cplusplus
}
#endif
#endif /* ADC_H_ */

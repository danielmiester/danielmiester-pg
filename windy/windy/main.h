/*
 * main.c
 *
 *  Created on: Mar 15, 2011
 *      Author: dejagerd
 */
#ifndef MAIN_H
#define MAIN_H
#include "commonincludes.h"
#ifdef __cplusplus
#define filterpower 2
#define filterlength 2<<filterpower
extern "C"{
#endif
void init(void) __attribute__ ((naked,section (".init8")));
void main() __attribute__ ((noreturn));
#define VOLTAGE 0
#define CURRENT 1
#define hysteresis 1
float voltage;
float voltage2;
float current;
float current2;
float power;
float rpm;
float lastPower;
float Vref;
char * buffer;
#define EXPO(VAL) ((int32_t)((int8_t)((VAL)+127))<<23)
#define EMA(STORAGE,INPUT,OVERSAMPLE) (STORAGE) = fma((STORAGE),\
		(OVERSAMPLE) - 1.0,(INPUT));\
	(STORAGE) /= (OVERSAMPLE)

#ifdef __cplusplus
}
#endif
#endif

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
extern "C" {
#endif
#define Vref 5.0
#define VOLTAGE 0
#define CURRENT 1
#define hysteresis .00001
/**
 * Exponential Moving Average function
 * takes the form of
 * STORAGE = (INPUT + INPUT*(SAMPLES -1))/SAMPLES
 */
#define EMA(STORAGE,INPUT,SAMPLES) \
	(STORAGE) = fma((STORAGE), (SAMPLES) - 1.0,(INPUT));\
	(STORAGE) /= (SAMPLES)
#define MAPADC(IN,MIN,MAX) ((IN) * ((MAX) - (MIN))) / (1024) + (MIN)


void init(void) __attribute__ ((naked,section (".init8")));
void main() __attribute__ ((noreturn));

float voltage;
float voltage2;
float current;
float current2;
float power;
float rpm;
float lastrpm;
float lastpower;
float deltarpm;
float deltapower;
uint16_t duty;

#ifdef __cplusplus
}
#endif
#endif

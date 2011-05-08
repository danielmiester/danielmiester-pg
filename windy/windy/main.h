/*
 * main.c
 *
 *  Created on: Mar 15, 2011
 *      Author: dejagerd
 */
#ifndef MAIN_H
#define MAIN_H
void init1(void) __attribute__ ((naked))  __attribute__ ((section (".init8")));
void increment_power() __attribute__((always_inline));
void decrement_power() __attribute__((always_inline));
int getSpeed();
int getPower();
void filter();
#endif

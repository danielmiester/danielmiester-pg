/*
 * PWM.h
 *
 *  Created on: May 11, 2011
 *      Author: dejagerd
 */

#ifndef PWM_H_
#define PWM_H_
#include "WProgram.h"
#include "avr/sfr_defs.h"
#include "avr/io.h"
#ifdef __cplusplus
extern "C"{
#endif
void PWMinit();
void PWMsetDutyCycle(uint8_t) __attribute__((always_inline));
uint8_t PWMgetDutyCycle() __attribute__((always_inline));
#ifdef __cplusplus
}
#endif

#endif /* PWM_H_ */

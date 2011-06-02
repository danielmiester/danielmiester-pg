/*
 * PWM.h
 *
 *  Created on: May 11, 2011
 *      Author: dejagerd
 */

#ifndef PWM_H_
#define PWM_H_
#include "commonincludes.h"

#ifdef __cplusplus
extern "C"{
#endif
#define PWMdutyCycle OCR0B
void PWMinit();
void PWMsetDutyCycle(uint8_t) __attribute__((always_inline));
uint8_t PWMgetDutyCycle() __attribute__((always_inline));
#ifdef __cplusplus
}
#endif

#endif /* PWM_H_ */

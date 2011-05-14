/*
 * RPM.h
 *
 *  Created on: May 11, 2011
 *      Author: dejagerd
 */

#ifndef RPM_H_
#define RPM_H_
#include "WProgram.h"
#ifdef __cplusplus
extern "C" {
#endif
//extern volatile uint8_t seconds;
extern volatile uint16_t event1;
extern volatile uint16_t event2;
void RPMinit();
uint16_t RPMgetSpeed();


#ifdef __cplusplus
}
#endif
#endif /* RPM_H_ */

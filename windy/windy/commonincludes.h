/*
 * commonincludes.h
 *
 *  Created on: May 14, 2011
 *      Author: dejagerd
 */

#ifndef COMMONINCLUDES_H_
#define COMMONINCLUDES_H_
//#define __AVR_ATmega168__
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>
#include <ctype.h>
#include <inttypes.h>
#include <math.h>
#include <avr/pgmspace.h>


#define lowByte(w) ((uint8_t) ((w) & 0xff))
#define highByte(w) ((uint8_t) ((w) >> 8))

#define bitRead(value, bit) (((value) >> (bit)) & 0x01)
#define bitSet(value, bit) ((value) |= (1UL << (bit)))
#define bitClear(value, bit) ((value) &= ~(1UL << (bit)))
#define bitWrite(value, bit, bitvalue) (bitvalue ? bitSet(value, bit) : bitClear(value, bit))

#define clockCyclesPerMicrosecond() ( F_CPU / 1000000L )
#define clockCyclesToMicroseconds(a) ( ((a) * 1000L) / (F_CPU / 1000L) )
#define microsecondsToClockCycles(a) ( ((a) * (F_CPU / 1000L)) / 1000L )

typedef uint8_t boolean;


#endif /* COMMONINCLUDES_H_ */

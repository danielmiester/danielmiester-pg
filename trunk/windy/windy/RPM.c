/*
 * RPM.cpp
 *
 *  Created on: May 11, 2011
 *      Author: dejagerd
 */

#include "RPM.h"
volatile uint16_t event1 = 0xffff;
volatile uint16_t event2 = 0xffff;
void RPMinit() {
	//select mode 15
	TCCR1A = 0 | _BV(WGM10) | _BV(WGM11);
	TCCR1B = 0 | _BV(WGM12) | _BV(WGM13)
	//end mode select
			| _BV(ICNC1) //enable noise canceler
			| _BV(ICES1); //select positive edge
	TCCR1C = 0;
	OCR1A = 0xffff;//62499; //to get an overflow 1/sec;
	TIMSK1 = 0 | _BV(ICIE1) //enable counter match
	;
	TCCR1B |= _BV(CS12);// | _BV(CS10); //enable timer at CLKio/256
}
uint16_t RPMgetSpeed() {
	return event2 - event1;
}

ISR(TIMER1_CAPT_vect,ISR_NOBLOCK)
{
	event1 = event2;
	event2 = ICR1;
}


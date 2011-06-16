/*
 * main.c
 *
 *  Created on: Mar 15, 2011
 *      Author: dejagerd
 */

#include "main.h"
#include "ADC.h"
#include "PWM.h"
#include "RPM.h"
#include "serial.h"
volatile uint16_t ticks;
char string_1[] PROGMEM = "\e[2J" __TIMESTAMP__;
char string_2[] PROGMEM = "\e[2;0H"
	"%7.4gv|%7.4gA|%7.4gW|%7.4gRPM|%7.4gdW|%7.4gdRPM|%7d\e[K";

void init(void) {
	sei();
	UCSR0B = 0;
	Serial57600();
	printf_P(string_1);
	ADCinit();
	ADCstart();
	PWMinit();
	RPMinit();
	PWMdutyCycle = 128;

}

void main(void) {

	for (;;) {
		lastrpm = rpm;
		rpm = 62500.0 / RPMgetSpeed();//62500 ticks/sec; 60secs/min; x10 to get a decimal place.
		voltage = MAPADC(ADCdata[VOLTAGE],0,30);
		current = MAPADC(ADCdata[CURRENT],-2.5,2.5);
		EMA(voltage2,voltage,16);
		EMA(current2,current,16);
		EMA(deltarpm,rpm-lastrpm,16);
		EMA(deltapower,power-lastpower,16);
		lastpower = power;
		power = voltage2 * current2;
		if (((power - lastpower) > hysteresis) && PWMdutyCycle) {
			PWMdutyCycle--;
		} else if (lastpower - power > hysteresis) {
			PWMdutyCycle++;
		}
		PWMdutyCycle = (PWMdutyCycle > 192) ? 192 : PWMdutyCycle;

		if (ADCdataFresh >= 3) {
			ADCdataFresh = 0;
			ADCstart();
		}
		if (ticks >= 1500) {
			ticks = 0;
			printf_P(string_2, voltage2, current2, power, rpm, deltapower,
					deltarpm,PWMdutyCycle);
		}

	}
}

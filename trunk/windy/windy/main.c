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
#include <avr/pgmspace.h>
char string_1[] PROGMEM = "\e[2JBuild: " __DATE__ " " __TIME__ "\n"
"voltage\t|current\t|power\t\n";
char string_2[] PROGMEM = "\e[3;0H"
	"% 1.4g|% 1.4g|% 1.4g\e[K";
PGM_P string_table[] PROGMEM = { string_1, string_2, };

void init(void) {
	sei();
	UCSR0B = 0;
	Serial57600();
	buffer = (char*) malloc(strlen_P((PGM_P) pgm_read_word(&string_table[0])));
	strcpy_P(buffer, (char*) pgm_read_word(&(string_table[0])));
	printf(buffer);
	ADCinit();
	ADCcalibrate();
	Vref = ADCgetAVREF();
	ADCstart();
	PWMinit();
	DDRB = 0x20;
	PORTB = 0x1;
	RPMinit();
	DDRC = 0;
	PORTC = 0x3;

}

void main(void) {

	buffer = (char*) malloc(strlen_P((PGM_P) pgm_read_word(&string_table[1])));
	strcpy_P(buffer, (char*) pgm_read_word(&(string_table[1])));
	for (;;) {
		rpm = 62500.0 / RPMgetSpeed();//62500 ticks/sec; 60secs/min; x10 to get a decimal place.
		voltage = ADCdata[VOLTAGE] / 1024.0 * Vref;
		current = ADCdata[CURRENT] / 1024.0 * Vref - 2.55;
		EMA(voltage2,voltage,16);
		EMA(current2,current,16);
		power = voltage2 * current2;
		if (power - lastPower > hysteresis) {
			PWMdutyCycle--;
		} else if (lastPower - power > hysteresis) {
			PWMdutyCycle++;
		}

		if (ADCdataFresh >= 3) {
			ADCdataFresh = 0;
			ADCstart();
		}

		if (tick > 0) {
			tick = 0;
			printf(buffer, voltage2, current2, power);
		}
	}
}

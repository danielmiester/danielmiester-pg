/*
 * serial.c
 *
 *  Created on: May 14, 2011
 *      Author: dejagerd
 */
#include "serial.h"
FILE mystdout = FDEV_SETUP_STREAM(uart_putchar, NULL,
		_FDEV_SETUP_WRITE);
void Serial57600() {
	bitSet(DDRD,0); //set D[1] as output;
	bitSet(DDRD,1); //set D[1] as output;
	bitClear(PORTD,0);//set D[1] LOW;
	bitClear(PORTD,1);//set D[1] LOW;
	bitSet(PORTD,0);//set D[1] HIGH;
	bitSet(PORTD,1);//set D[1] HIGH;
	_delay_ms(1000);//delay 1s to send break;
#define BAUD 57600
#define F_CPU 8000000UL
#include <util/setbaud.h>
	UBRR0H = UBRRH_VALUE;
	UBRR0L = UBRRL_VALUE;
#if USE_2X
	UCSR0A |= (1 << U2X0);
#else
	UCSR0A &= ~(1 << U2X0);
#endif
	stdout = &mystdout;
	UCSR0B |= _BV(TXEN0);

}

 int uart_putchar(char c, FILE *stream) {

	if (c == '\n')
		uart_putchar('\r', stream);
	loop_until_bit_is_set(UCSR0A, UDRE0);
	UDR0 = c;
	return 0;
}

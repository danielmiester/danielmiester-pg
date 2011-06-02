/*
 * serial.h
 *
 *  Created on: May 14, 2011
 *      Author: dejagerd
 */

#ifndef SERIAL_H_
#define SERIAL_H_
#include "commonincludes.h"
void Serial57600();
 int uart_putchar(char c, FILE *stream);
FILE mystdout;


#endif /* SERIAL_H_ */

/*
 * buffer.h
 *
 *  Created on: Dec 8, 2010
 *      Author: dejagerd
 */

#ifndef BUFFER_H_
#define BUFFER_H_
#include <stdint.h>
#include <stdio.h>
#include <LPC17xx.h>
typedef struct {
	char* tail;
	char* head;
	uint32_t n;
	char* buf;
}fifo;
uint32_t bufget(fifo* buf);
uint32_t bufput(fifo* buf,char c);
fifo*  bufmake(uint32_t n);

#endif /* BUFFER_H_ */

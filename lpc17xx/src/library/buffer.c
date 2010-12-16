/*
 * buffer.cpp
 *
 *  Created on: Dec 8, 2010
 *      Author: dejagerd
 */

#include "buffer.h"
#define FREE(buf)
__attribute__((always_inline)) inline uint32_t bufget(fifo* buf)
{
	register uint32_t val;
	__disable_irq();
	if(buf->tail == buf->head){__enable_irq(); return 0x100;}
	val = *(buf->tail++);
	if(buf->tail >= buf->buf+buf->n) buf->tail = buf->buf;
	__enable_irq();
	return val;
}
__attribute__((always_inline)) inline uint32_t bufput(fifo* buf,char c)
{
	register uint32_t val;
	__disable_irq();
	if(buf->head+1 == buf->tail||(buf->tail==buf->buf&&buf->head==(buf->buf+buf->n-1))){
		__enable_irq();
		return 0x100;
	}
	val = *(buf->tail++);
	if(buf->tail >= buf->buf+buf->n) buf->tail = buf->buf;
	__enable_irq();
	return val;
}




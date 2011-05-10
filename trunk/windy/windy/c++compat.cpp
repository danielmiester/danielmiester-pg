/*
 * c++compat.cpp
 *
 *  Created on: May 7, 2011
 *      Author: dejagerd
 */
#include "c++compat.h"
#include <WProgram.h>
void __cxa_pure_virtual() {
	cli();
	for (;;)
		;
}



void * operator new(size_t size) {
	return malloc(size);
}

void operator delete(void * ptr) {
	free(ptr);
}

void * operator new[](size_t size) {
	return malloc(size);
}

void operator delete[](void * ptr) {
	if (ptr)
		free(ptr);
}

int __cxa_guard_acquire(__guard *g) {
	return !*(char *) (g);
}
void __cxa_guard_release(__guard *g) {
	*(char *) g = 1;
}
void __cxa_guard_abort(__guard *) {
}

/*
 * c++compat.h
 *
 *  Created on: May 7, 2011
 *      Author: dejagerd
 */

#ifndef C__COMPAT_H_
#define C__COMPAT_H_

extern "C" void __cxa_pure_virtual();
__extension__ typedef int __guard __attribute__((mode (__DI__)));

void operator delete[](void * ptr);
int __cxa_guard_acquire(__guard *g);
void __cxa_guard_release(__guard *g);
void __cxa_guard_abort(__guard *);
#endif /* C__COMPAT_H_ */

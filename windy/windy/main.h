/*
 * main.c
 *
 *  Created on: Mar 15, 2011
 *      Author: dejagerd
 */
#ifndef MAIN_H
#define MAIN_H
#ifdef __cplusplus
extern "C"{
#endif
void init1(void) __attribute__ ((naked))  __attribute__ ((section (".init8")));
int main(void)__attribute__ ((naked)) __attribute__ ((noreturn));
#ifdef __cplusplus
}
#endif
#endif

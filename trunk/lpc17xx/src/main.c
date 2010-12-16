/**************************************************************************//**
 * @file     main.c
 * @brief    CMSIS Cortex-M3 Blinky example
 *           Blink a LED using CM3 SysTick
 * @version  V1.03
 * @date     24. September 2009
 *
 * @note
 * Copyright (C) 2009 ARM Limited. All rights reserved.
 *
 * @par
 * ARM Limited (ARM) is supplying this software for use with Cortex-M 
 * processor based microcontrollers.  This file can be freely distributed 
 * within development tools that are supporting such ARM based processors. 
 *
 * @par
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * ARM SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 ******************************************************************************/

#include "LPC17xx.h"
#include "newlibMinimal.h"
#include "library/Serial.h"

volatile uint32_t msTicks;                            /* counts 1ms timeTicks */



void SysTick_Handler(void) {
  msTicks++;                        /* increment counter necessary in Delay() */
}

__INLINE static void Delay (uint32_t dlyTicks) {
  uint32_t curTicks;
  curTicks = msTicks;
  while ((msTicks - curTicks) < dlyTicks);
}

__INLINE static void LED_Config(void) {
  LPC_GPIO1->FIODIR = -1;               /* LEDs PORT1 are Output */
}

__INLINE static void LED_On (uint32_t led) {

  LPC_GPIO1->FIOPIN |=  (led);                  /* Turn On  LED */
}
__INLINE static void LED_Off (uint32_t led) {

  LPC_GPIO1->FIOPIN &= ~(led);                  /* Turn Off LED */
}
void _start(void){}

int main (void) {
	SystemCoreClockUpdate();

  if (SysTick_Config(SystemCoreClock / 1000)) { /* Setup SysTick Timer for 1 msec interrupts  */
    while (1);                                  /* Capture error */
  }
  
  LED_Config();
  SerialInit(UART0,9600);
  uart_putchar('h',NULL);
  uart_putchar('e',NULL);
  uart_putchar('l',NULL);
  uart_putchar('l',NULL);
  uart_putchar('o',NULL);
  uart_putchar(' ',NULL);
  uart_putchar('w',NULL);
  uart_putchar('o',NULL);
  uart_putchar('r',NULL);
  uart_putchar('l',NULL);
  uart_putchar('d',NULL);
  uart_putchar('!',NULL);
 //putst("helloWorld");
  while(1) {
    LED_On ((-1));                           /* Turn on the LED. */
    Delay (100);                                /* delay  100 Msec */
    LED_Off ((-1));                          /* Turn off the LED. */
    Delay (900);                                /* delay  100 Msec */
  }
  
}


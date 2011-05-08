/*
 * main.c
 *
 *  Created on: Mar 15, 2011
 *      Author: dejagerd
 */

#include "WProgram.h"
#include "main.h"
#include "ADC.h"

const int DEADZONE = 1;
int power;
int speed;
int prev_power;
int prev_speed;
int dp;
int ds;
int prev_dp;
int prev_ds;
int dp_ds;

void init1(void)
{
	TCCR0B = (TCCR0B & 0xf8) | 1;
   // analogWrite(5, 63);
	ADCinit();
}

int getSpeed() {return 0;}
int getPower() {return 0;}
void filter() {
	int p = getPower();
	int s = getSpeed();
	prev_power = power;
	prev_speed = speed;
	prev_dp = dp;
	prev_ds = ds;
	power = (7 * power + p) << 3;
	speed = (7 * speed + s) << 3;
	dp = power - prev_power;
	ds = speed - prev_speed;
	dp_ds = dp/ds;
}

void increment_power(){
	//if(255!=OCR2A)
		OCR2A++;
		OCR2B++;
}
void decrement_power(){
	if(OCR2A)
		OCR2A = OCR2B--;
}
/*
 * TODO Implement SPEED/POWER LIMITS
 *
const int MAX_SPEED = INT_MAX;
const int MAX_POWER = INT_MAX;
*/


int main(void) {
	while (1) {
		filter();
		if(dp_ds > DEADZONE){
			increment_power();
		}
		if(dp_ds < DEADZONE){
			decrement_power();
		}
	}
}

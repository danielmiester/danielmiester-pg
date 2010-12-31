/* dcc_link.c
opend2cc
	Copyright (C) 2010  Daniel De Jager

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.

Daniel De Jager
danielmiester at gmail dot com
3804 110th Ave. E.
Edgewood WA 98372
 */

#include "dcc_link.h"
#include "stdlib.h"
#include "iodefine.h"

void dccInit(void)
{
	dccData = malloc(sizeof dccdata_td);
	dccData->dc_component = 0;
	dccData->dc_setting = 0;
	dccData->power_level = 0;
	dccData->VAL = 0;
}
void dccPoll(void){


}
void dccIdle(void){
	short t1=t2=100;
	if(dccData->dc_setting > 0){
		t2+=dccData->dc_setting;
	}
	if(dccData->dc_setting < 0){
		t1+=dccData->dc_setting;
	}

	DCC_PORT = 0;
	//delay(t1);
	DCC_PORT = 1;
	//delay(t2);
	ema(t2-t1);

}
void dccTransmit1(void){
	DCC_PORT = 0;
	//delay(58);
	DCC_PORT = 1;
	//delay(58);
	ema(0);
}
inline void ema( int newVal)
{
	dccData->dc_component = newVal + dccData->dc_component*3;
	dccData->dc_component >>= 2;
}





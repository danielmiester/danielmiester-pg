/*
 dcc_link.h
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

#ifndef DCC_LINK_H_
#define DCC_LINK_H_
#define DCC_PORT (PORTD->DR->BIT->B0)
const int SMA_AVERAGE_N = 8;
typedef struct{
	int dc_component;
	short dc_setting;
	short power_level;
	union {
		unsigned char VAL;
		struct{
			unsigned int ESTOP:1;
			unsigned int :7;
		};
	};
}dccdata_td;
dccdata_td dccData;
/**
 * initializes the DCC subsystem.
 */

void dccInit(void);
/**
 * Transmits a 0 with the specified duty cycle
 * 0 is 50%
 */
void dccTransmit0(void);
/**
 * Transmits a 1
 */
void dccTransmit1(void);
void dccIdle(void);
void ema( int new);

#endif /* DCC_LINK_H_ */

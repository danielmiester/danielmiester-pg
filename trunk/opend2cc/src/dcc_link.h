/*
 * dcc_link.h
 *
 *  Created on: Dec 31, 2010
 *      Author: Administrator
 */

#ifndef DCC_LINK_H_
#define DCC_LINK_H_

typedef struct{
	unsigned char dc;
}dccdata_td;
dccdata_td dccData;
void dccInit(void);


#endif /* DCC_LINK_H_ */

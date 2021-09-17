#ifndef _seven_seg
#define _seven_seg


#include "headers.h"

#define INIT_Seven_PORT 	DDRC |= 0x3f;
#define SEG_A(x)    if (x == 0) CLRBIT(PORTC,0); else SETBIT(PORTC,0);
#define SEG_B(x)    if (x == 0) CLRBIT(PORTC,1); else SETBIT(PORTC,1);
#define SEG_C(x)    if (x == 0) CLRBIT(PORTC,2); else SETBIT(PORTC,2);
#define SEG_D(x)    if (x == 0) CLRBIT(PORTC,3); else SETBIT(PORTC,3);
#define SEG_E1(x)   if (x == 0) CLRBIT(PORTC,4); else SETBIT(PORTC,4);
#define SEG_E2(x)   if (x == 0) CLRBIT(PORTC,5); else SETBIT(PORTC,5);

void seven_seg_init();
void seven_seg_update(uint8_t counter);

#endif
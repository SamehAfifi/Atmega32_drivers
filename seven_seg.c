#include "seven_seg.h"

#define INIT_Seven_PORT 	DDRB = 0xff; PORTB = 0x00;
#define SEG_A(x)    if (x == 0) CLRBIT(PORTB,0); else SETBIT(PORTB,0);
#define SEG_B(x)    if (x == 0) CLRBIT(PORTB,1); else SETBIT(PORTB,1);
#define SEG_C(x)    if (x == 0) CLRBIT(PORTB,6); else SETBIT(PORTB,6);
#define SEG_D(x)    if (x == 0) CLRBIT(PORTB,7); else SETBIT(PORTB,7);
#define SEG_E1(x)   if (x == 0) CLRBIT(PORTB,4); else SETBIT(PORTB,4);
#define SEG_E2(x)   if (x == 0) CLRBIT(PORTB,5); else SETBIT(PORTB,5);

void seven_seg_init(){
	INIT_Seven_PORT;
	SEG_E1(1);
	SEG_E2(1);	
}

void seven_seg_update(uint8_t counter){
	uint8_t temp;
	temp = counter % 10;
	SEG_E1(1);
	SEG_E2(0);
	SEG_A(READBIT(temp,0));
	SEG_B(READBIT(temp,1));
	SEG_C(READBIT(temp,2));
	SEG_D(READBIT(temp,3));
	
	_delay_ms(1);
	temp = counter / 10;
	SEG_E1(0);
	SEG_E2(1);
	SEG_A(READBIT(temp,0));
	SEG_B(READBIT(temp,1));
	SEG_C(READBIT(temp,2));
	SEG_D(READBIT(temp,3));
	
	_delay_ms(1);
}
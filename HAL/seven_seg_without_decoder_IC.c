#include "seven_seg_without_decoder_IC.h"

#define A 1
#define B 2
#define C 3
#define D 4
#define E 5
#define F 6
#define G 7

void seven_seg_init(){
	DDRA |= 0xfe;
	SETBIT(DDRC,6);
	SETBIT(DDRC,7);
}
void convert_digit(uint8_t first_digit){
	PORTA &=  0b1;
	switch(first_digit){
		case 0: PORTA |= 1<<A | 1<<B| 1<<F| 1<<E| 1<<D| 1<<C; break;
		case 1: PORTA |= 1<<F| 1<<E; break;
		case 2: PORTA |= 1<<A | 1<<B| 1<<G| 1<<E| 1<<D; break;
		case 3: PORTA |= 1<<A | 1<<B| 1<<G| 1<<D| 1<<C; break;
		case 4: PORTA |= 1<<G | 1<<B| 1<<F| 1<<C; break;
		case 5: PORTA |= 1<<A | 1<<F| 1<<G| 1<<D| 1<<C; break;
		case 6: PORTA |= 1<<A | 1<<G| 1<<F| 1<<E| 1<<D| 1<<C; break;
		case 7: PORTA |= 1<<A | 1<<B| 1<<C; break;
		case 8: PORTA |= 1<<A | 1<<B| 1<<F| 1<<E| 1<<D| 1<<C| 1<<G; break;
		case 9: PORTA |= 1<<A | 1<<B| 1<<F| 1<<G| 1<<D| 1<<C; break;
	}
}
void seven_seg_update(uint8_t counter){ // 19
		SETBIT(PORTC,6);
		CLRBIT(PORTC,7);
		uint8_t first_digit = counter/10;
		convert_digit(first_digit);
		
		_delay_ms(1);
		
		SETBIT(PORTC,7);
		CLRBIT(PORTC,6);
		uint8_t second_digit = counter%10;
		convert_digit(second_digit);
	
		_delay_ms(1);
		
}
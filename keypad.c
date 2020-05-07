/*
 * keypad.c
 *
 * Created: 3/30/2020 4:36:31 PM
 *  Author: safifi
 */ 


#include "keypad.h"

const uint8_t keypad_matrix[] = {
	'0','1','2','3',
	'4','5','6','7',
	'8','9','-','+',
	'A','B','/','*'
};

void keypad_init(){

	CLRBIT(DDRD,2);
	CLRBIT(DDRD,3);
	CLRBIT(DDRD,4);
	CLRBIT(DDRD,5);
	PORTD |= 0b00111100; // internal pull up in case of protues
	SETBIT(DDRB,4);
	SETBIT(DDRB,5);
	SETBIT(DDRB,6);
	SETBIT(DDRB,7);
}
int8_t keypad_read(){

	for(uint8_t i = 0; i < 4 ; i++){
		PORTB = PORTB & 0b00001111;
		if (i == 0) PORTB |= 0b11100000;
		if (i == 1) PORTB |= 0b11010000;
		if (i == 2) PORTB |= 0b10110000;
		if (i == 3) PORTB |= 0b01110000;
		
		if (GETBIT(PIND,2) == 0) return keypad_matrix[0+4*i];
		if (GETBIT(PIND,3) == 0) return keypad_matrix[1+4*i];
		if (GETBIT(PIND,4) == 0) return keypad_matrix[2+4*i];
		if (GETBIT(PIND,5) == 0) return keypad_matrix[3+4*i];
		_delay_ms(1);
	
	}	
	return -1;

}
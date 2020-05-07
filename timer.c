/*
 * timer.c
 *
 * Created: 4/15/2020 5:42:57 PM
 *  Author: safifi
 */ 


#include "timer.h"

void timer0_normal_init(){
	TCCR0 = (1<<FOC0) | (1<<CS00) | (1<<CS02); // enable normal mode
	TIMSK |= 1<<TOIE0;// enable interrupt for OV
	sei();
}


void timer0_compare_init(){
	TCCR0 = (1<<FOC0) | (1<<CS00) | (1<<CS02) | (1<<WGM01);
	OCR0 = 200;
	TIMSK |= 1<<OCIE0;
	sei();
}

void timer0_freq_gen_init(uint8_t value){
	SETBIT(DDRB,3);
	TCCR0 = (1<<FOC0) | (1<<CS00) | (1<<WGM01)| 1<<COM00;
	OCR0 = value;
}

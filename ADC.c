/*
 * ADC.c
 *
 * Created: 9/17/2021 12:49:05 PM
 *  Author: safifi
 */ 

#include "ADC.h"

void ADC_init(void){
	ADMUX = 1<<REFS0;
	ADCSRA = 1<<ADEN | 1<<ADPS0 | 1<<ADPS1 | 1<<ADPS2;	 
}


uint16_t ADC_read(uint8_t ch){
	ADMUX = ch | 1<<REFS0;
	SETBIT(ADCSRA,ADSC); // start conversion
	while(READBIT(ADCSRA,ADSC) == 1){}
//	while(READBIT(ADCSRA,ADIF) == 0){}
	
	return ADC;
}
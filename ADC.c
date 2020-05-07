/*
 * ADC.c
 *
 * Created: 4/12/2020 4:02:43 PM
 *  Author: safifi
 */ 

#include "ADC.h"

void ADC_Init()
	SETBIT(ADMUX,REFS0);
	SETBIT(ADCSRA,ADEN);
	SETBIT(ADCSRA,ADPS0);
	SETBIT(ADCSRA,ADPS1);
	SETBIT(ADCSRA,ADPS2);	
}

uint16_t ADC_Read(uint8_t channel){

	ADMUX= (ADMUX & 0xf0)| (channel & 0x0f);	/* Set input channel to read */
	SETBIT(ADCSRA,ADSC); // start conversion
	while(GETBIT(ADCSRA,ADSC) == 1){}
	return ADC;
}
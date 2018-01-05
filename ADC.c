/*
 * ADC.c
 *
 * Created: 11/26/2014 5:46:08 PM
 *  Author: safifi
 */ 
#include "ADC.h"

void ADC_init(){
	ADCSRA = 0b10000111;
	ADMUX = 0x40;
}
uint16_t ADC_Read(uint8_t channel){
	ADCSRA |= 1<<6;
	ADMUX = (ADMUX & (0xe0)) | channel;
	while((ADCSRA & 1<<6));
	return (ADCL+ (ADCH << 8));
}

	
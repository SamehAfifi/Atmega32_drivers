/*
 * PWM.c
 *
 * Created: 4/22/2017 3:02:41 AM
 *  Author: safifi
 */ 
#include "PWM.h"
void PWM1_OCR1A_init(){
	DDRD |= (1<<PIND5);
	TCCR1A |= (1<<WGM11)|(1<<WGM10)|(1<<COM1A1); // phase correct PWM at OC1A
	TCCR1B |= (1<<CS10);  // enable PWM with period 1.024/8 = 0.128 usec
}
void PWM1_OCR1A_SET_DUTY(uint8_t duty){
	OCR1A = (duty*10.23);	
}
/////////////////
void PWM1_OCR1B_init(){
	DDRD |= (1<<PIND4);
	TCCR1A |= (1<<WGM11)|(1<<WGM10)|(1<<COM1B1); // phase correct PWM at OC1B
	TCCR1B |= (1<<CS10);  // enable PWM with period 1.024/8 = 0.128 usec
}
void PWM1_OCR1B_SET_DUTY(uint8_t duty){
	OCR1B = (duty*10.23);
}
////////////////////
void PWM0_OCR0_init(){
	DDRB |= (1<<PINB3);
	TCCR0 |= (1<<WGM00)|(1<<WGM01)|(1<<COM01)|(1<<CS00); // phase correct PWM at OC1A
}
void PWM0_OCR0_SET_DUTY(uint8_t duty){
	OCR0 = (duty*2.55);
}
///////////////////
void PWM2_OCR2_init(){
	DDRD |= (1<<PIND7);
	TCCR2 |= (1<<WGM20)|(1<<WGM21)|(1<<COM21)|(1<<CS20); // phase correct PWM at OC1A
}
void PWM2_OCR2_SET_DUTY(uint8_t duty){
	OCR2 = (duty*2.55);
}

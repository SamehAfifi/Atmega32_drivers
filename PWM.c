/*
 * PWM.c
 *
 * Created: 9/17/2021 11:07:53 AM
 *  Author: safifi
 */ 

#include "headers.h"

void PWM_OC1A_init(void){
	SETBIT(DDRD,5); // OC1A output
	TCCR1A |= 1<<COM1A1 | 1<<WGM11 | 1<<WGM10;
	TCCR1B |= 1<<WGM12 | 1<<CS10;
}
/*
duty = OCR1A / 1023 * 100
OCR1A = duty * 10.23

*/

void PWM_OC1A_set_duty(uint8_t duty){
OCR1A = duty * 10.23;	
}

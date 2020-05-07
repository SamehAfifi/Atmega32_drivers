/*
 * PWM.c
 *
 * Created: 4/16/2020 3:49:09 PM
 *  Author: safifi
 */ 
#include "PWM.h"
/*
non inverting
10 bit fast PWM
oc1a
*/



void PWM_init_timer1_oc1a(){
	SETBIT(DDRD,5);
	TCCR1A |= ((1<<WGM11)|(1<<WGM10)|(1<<COM1A1)); // phase correct PWM at OC1A
	TCCR1B = 1<<WGM12 | 1<<CS10;
}

/*
duty = (ocr1a / 1023) * 100
OCR1A = duty* 10.23;
*/
void set_duty_oc1a(uint8_t duty){
	OCR1A = duty* 10.23;
}



void PWM_init_timer1_oc1b(){
	SETBIT(DDRD,4);
	TCCR1A |= 1<<COM1B1 | 1<<WGM10 | 1<<WGM11;
	TCCR1B = 1<<WGM12 | 1<<CS10;
}

/*
duty = (ocr1b / 1023) * 100
OCR1b = duty* 10.23;
*/
void set_duty_oc1b(uint8_t duty){
	OCR1B = duty* 10.23;
}


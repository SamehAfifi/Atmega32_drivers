/*
 * PWM.h
 *
 * Created: 4/22/2017 3:03:13 AM
 *  Author: safifi
 */ 


#ifndef PWM_H_
#define PWM_H_
#include "std_macros.h"

//phase correct 8bit
void PWM1_OCR1A_init();
void PWM1_OCR1A_SET_DUTY(uint8_t duty);

//phase correct 10bit
void PWM1_OCR1B_init();
void PWM1_OCR1B_SET_DUTY(uint8_t duty);

//fast pwm 8bit
void PWM0_OCR0_init();
void PWM0_OCR0_SET_DUTY(uint8_t duty);

//fast pwm 8bit
void PWM2_OCR2_init();
void PWM2_OCR2_SET_DUTY(uint8_t duty);





#endif /* PWM_H_ */
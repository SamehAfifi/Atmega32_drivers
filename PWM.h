/*
 * PWM.h
 *
 * Created: 9/17/2021 11:08:02 AM
 *  Author: safifi
 */ 


#ifndef PWM_H_
#define PWM_H_
#include "headers.h"


/*****************************************************************************
* Function Name: PWM_OC1A_init
* Purpose      : Initialize OC1A as FAST-PWM in timer1 with no prescaler -
*                10 bit - non inverting mode
* Parameters   : void
* Return value : void
*****************************************************************************/
void PWM_OC1A_init(void);

/*****************************************************************************
* Function Name: PWM_set_duty_oc1a
* Purpose      : Set OCR1A register to generate PWM with a specific duty cycle
* Parameters   : duty: value range from 0 to 100
* Return value : void
*****************************************************************************/
void PWM_OC1A_set_duty(uint8_t duty);




#endif /* PWM_H_ */
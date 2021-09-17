/*
 * ADC.h
 *
 * Created: 9/17/2021 12:49:17 PM
 *  Author: safifi
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "headers.h"

/*****************************************************************************
* Function Name: ADC_Init
* Purpose      : Initialize ADC with AVCC, single conversion mode and ADC_freq = 125 Khz
* Parameters   : void
* Return value : void
*****************************************************************************/
void ADC_init(void);

/*****************************************************************************
* Function Name: ADC_Read
* Purpose      : Trigger the ADC to start conversion (sync func)
* Parameters   : uint8_t channel to get analog value from
* Return value : void
*****************************************************************************/
uint16_t ADC_read(uint8_t ch);



#endif /* ADC_H_ */
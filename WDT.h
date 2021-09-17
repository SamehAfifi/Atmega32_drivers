/*
 * ATmega16_watchdog_timer.h
 *
 * Created: 1/1/2020 5:45:32 PM
 *  Author: safifi
 */ 


#ifndef WDT_H_
#define WDT_H_
#include "headers.h"


/*****************************************************************************
* Function Name: WDT_on
* Purpose      : Set watchdog timer to 1 second and start
* Parameters   : void
* Return value : void
*****************************************************************************/
void WDT_on(void);


/*****************************************************************************
* Function Name: ADC_Init
* Purpose      : Turn off watchdog timer 
* Parameters   : void
* Return value : void
*****************************************************************************/
void WDT_off(void);

#endif /* WDT_H_ */
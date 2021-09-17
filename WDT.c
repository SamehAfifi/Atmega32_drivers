/*
 * ATmega16_watchdog_timer.c
 *
 * Created: 1/1/2020 5:45:32 PM
 *  Author: safifi
 */ 
#include "WDT.h"

void WDT_on(void)
{
	/*
	Watchdog timer enables with typical timeout period 1
	second.
	*/
	WDTCR = (1<<WDE)|(1<<WDP2)|(1<<WDP1);
}

void WDT_off(void)
{
	/*
	This function use for disable the watchdog timer.
	*/
	WDTCR = 1<<WDTOE | 1<< WDE;
	WDTCR = 0;

}

	
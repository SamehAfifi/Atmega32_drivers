/*
 * ATmega16_watchdog_timer.c
 *
 * Created: 1/1/2020 5:45:32 PM
 *  Author: safifi
 */ 
#include "WDT.h"

void WDT_ON()
{
	/*
	Watchdog timer enables with typical timeout period 2.1 
	second.
	*/
	WDTCR = (1<<WDE)|(1<<WDP2)|(1<<WDP1)|(1<<WDP0);
}

void WDT_OFF()
{
	/*
	This function use for disable the watchdog timer.
	*/
	WDTCR = 1<<WDTOE | 1<< WDE;
	WDTCR = 0;

}

	
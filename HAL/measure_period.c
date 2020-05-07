

#include "LCD.h"
int main ( )
{
	uint16_t t;
	TCCR1A = 0;
	TIFR = (1<<ICF1);		/* clear input capture flag */
	TCCR1B = 0x41;			/* capture on rising edge */ 

	while ((TIFR&(1<<ICF1)) == 0);  /* monitor for capture*/
	t = ICR1;			
	TIFR = (1<<ICF1);		/* clear capture flag */

	while ((TIFR&(1<<ICF1)) == 0);  /* monitor for next rising edge capture */

	t = ICR1 - t;  			/* period= recent capture - previous capture */
	/* use lcd to print the period */
	while (1);
	return 0;
}


#include "std_macros.h"
#include "LCD.h"

int main ( )
{
	uint16_t t1,t2,t3,high,period;
	while(1)
	{
		TCCR1A = 0;
		TCNT1=0;
		TIFR = (1<<ICF1);  	/* Clear ICF (Input Capture flag) flag */

		TCCR1B = 0x41;  	/* Rising edge, no prescaler */
		while ((TIFR&(1<<ICF1)) == 0);
		t1 = ICR1;  		/* Take value of capture register */
		TIFR = (1<<ICF1);  	/* Clear ICF flag */
		
		TCCR1B = 0x01;  	/* Falling edge, no prescaler */
		while ((TIFR&(1<<ICF1)) == 0);
		t2 = ICR1;  		/* Take value of capture register */
		TIFR = (1<<ICF1);  	/* Clear ICF flag */
		
		TCCR1B = 0x41;  	/* Rising edge, no prescaler */
		while ((TIFR&(1<<ICF1)) == 0);
		t3 = ICR1;  		/* Take value of capture register */
		TIFR = (1<<ICF1);  	/* Clear ICF flag */

		TCCR1B = 0;  		/* Stop the timer */
		
		if(t1<t2 && t2<t3)  	/* Check for valid condition, 
					to avoid timer overflow reading */
		{
			high=t2-t1;
			period=t3-t1;			
			/* Calculate duty cycle */
            uint8_t duty_cycle =((float) high /(float)period)*100;			
			/* print values on LCD	*/
		}
		else
		{
		/* clear LCD */
		}
		_delay_ms(50);
	}

}
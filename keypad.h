/*
 * keypad.h
 *
 * Created: 9/10/2021 10:31:52 AM
 *  Author: safifi
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_
/*


------------------------- 
|     |     |     |     | ---------- KP0
-------------------------  
|     |     |     |     | ---------- KP1
-------------------------  
|     |     |     |     | ---------- KP2
-------------------------  
|     |     |     |     | ---------- KP3
-------------------------
|     |     |     | PULL UP
|     |     |     |
KP4   KP5   KP6   KP7

KP (0 TO 3) INPUT   ==> PD0,1,2,3  OUTPUT
KP (4 TO 7) OUTPUT  ==> PD4,5,6,7  INPUT PULL UPD

*/


#include "headers.h"

#define INIT_KEYPAD() DDRD = 0x0f; PORTD = 0xff;  // pull up PD4,5,6,7

#define KP0(val) if(val == 0)  CLRBIT(PORTD,0); else  SETBIT(PORTD,0);
#define KP1(val) if(val == 0)  CLRBIT(PORTD,1); else  SETBIT(PORTD,1);
#define KP2(val) if(val == 0)  CLRBIT(PORTD,2); else  SETBIT(PORTD,2);
#define KP3(val) if(val == 0)  CLRBIT(PORTD,3); else  SETBIT(PORTD,3);

#define KP4()  READBIT(PIND,4)
#define KP5()  READBIT(PIND,5)
#define KP6()  READBIT(PIND,6)
#define KP7()  READBIT(PIND,7)


#define DELAY_MS(x) _delay_ms(x);

/*****************************************************************************
* Function Name: keypad_init
* Purpose      : initialize keypad pins
* Parameters   : void
* Return value : void
*****************************************************************************/
void keypad_init(void);


/*****************************************************************************
* Function Name: keypad_init
* Purpose      : check if one of keypad button is pressed
* Parameters   : void
* Return value : return the button value in case a button is pressed
*                return -1 in case no button pressed
*****************************************************************************/
int8_t keypad_read(void);


#endif /* KEYPAD_H_ */
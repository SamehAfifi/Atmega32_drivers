

#ifndef  key
#define key

#include "std_macros.h"

#define mykeypadport  DDRD = 0b00001111;  
#define pullup  PORTD = 0b11110000;  
// Keypad configurations
#define k1(x)   if (x == 0) CLRBIT(PORTD,0); else SETBIT(PORTD,0);
#define k2(x)   if (x == 0) CLRBIT(PORTD,1); else SETBIT(PORTD,1);
#define k3(x)   if (x == 0) CLRBIT(PORTD,2); else SETBIT(PORTD,2);
#define k4(x)   if (x == 0) CLRBIT(PORTD,3); else SETBIT(PORTD,3);

#define k5  READBIT(PIND,4)
#define k6  READBIT(PIND,5)
#define k7  READBIT(PIND,6)
#define k8  READBIT(PIND,7)

// initialize keypad
void keypad_init();

// Get new click
int8_t keypad_click();

#endif


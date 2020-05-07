/*
 * std_macros.h
 *
 * Created: 4/25/2017 4:00:26 PM
 *  Author: safifi
 */ 


#ifndef STD_MACROS_H_
#define STD_MACROS_H_

#include <avr/io.h>   // this file include all register addresses macros like DDRA 
#define F_CPU 8000000UL // set the frequency of microcontroller
#include <util/delay.h> // this header include all delay function like _delay_ms
#include <avr/interrupt.h> // this header is necessary when you deal with interrupt


#define SETBIT(REG,BIT)  (REG |= 1 << BIT)
#define CLRBIT(REG,BIT)  (REG &= ~(1 << BIT))
#define TOGBIT(REG,BIT)  (REG ^= 1 << BIT)
#define READBIT(REG,BIT)  ((REG >> BIT) & 1)

#endif /* STD_MACROS_H_ */
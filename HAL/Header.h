/*
 * Header.h
 *
 * Created: 3/7/2020 11:51:11 AM
 *  Author: safifi
 */ 


#ifndef HEADER_H_
#define HEADER_H_

#include <avr/io.h>   // this file include all register addresses macros like DDRA 
#define F_CPU 16000000UL // set the frequency of microcontroller
#include <util/delay.h> // this header include all delay function like _delay_ms
#include <avr/interrupt.h> // this header is necessary when you deal with interrupt

#define SETBIT(REG,BIT) (REG |= 1<<BIT)
#define CLRBIT(REG,BIT) (REG &= ~(1<<BIT))
#define TOGBIT(REG,BIT) (REG ^= 1<<BIT)
#define GETBIT(REG,BIT) ((REG>>BIT) &1)
#define READBIT(REG,BIT)  ((REG >> BIT) & 1)


#endif /* HEADER_H_ */
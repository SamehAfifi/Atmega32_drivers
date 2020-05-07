#include "type.h"
#include <avr/io.h>

#define INPUT  0
#define OUTPUT 1
#define SETBIT(reg,bit)  (reg |=  (1<<bit))
#define CLRBIT(reg,bit)  (reg &= ~(1<<bit))
#define TOGBIT(reg,bit)  (reg ^=  (1<<bit))
#define rd_bit(reg,bit)  (reg &  (1<<bit))

void Dio_init_port (u8_t port_name, u8_t status){
	if (status == INPUT)
	{
		status = 0x00;
	}
	else if (status == OUTPUT)
	{
		status = 0xff;
	}

	switch (port_name)
	{
		case 'A': 
		case 'a': DDRA = status;	break;

		case 'B': 
		case 'b': DDRB = status;	break;

		case 'C': 
		case 'c': DDRC = status;	break;

		case 'D': 
		case 'd': DDRC = status;	break;
	}
}
void Dio_init_pin (u8_t port_name, u8_t pin_number, u8_t status){
	switch (port_name)
	{
		case 'A': 
		case 'a': (status == OUTPUT)? SETBIT(DDRA,pin_number):CLRBIT(DDRA,pin_number);	break;

		case 'B': 
		case 'b': (status == OUTPUT)? SETBIT(DDRB,pin_number):CLRBIT(DDRB,pin_number);	break;

		case 'C': 
		case 'c': (status == OUTPUT)? SETBIT(DDRC,pin_number):CLRBIT(DDRC,pin_number);	break;

		case 'D': 
		case 'd': (status == OUTPUT)? SETBIT(DDRD,pin_number):CLRBIT(DDRD,pin_number);	break;
	}
}

void Dio_write_port(u8_t port_name,u8_t write){

	switch (port_name)
	{
		case 'A': 
		case 'a': PORTA = write;	break;

		case 'B': 
		case 'b': PORTB = write;	break;

		case 'C': 
		case 'c': PORTC = write;	break;

		case 'D': 
		case 'd': PORTD = write;	break;
	}
}
S8_t Dio_Read_port (u8_t port_name){
	switch (port_name)
	{
		case 'A': 
		case 'a': return PINA;	break;

		case 'B': 
		case 'b': return PINB;	break;

		case 'C': 
		case 'c': return PINC;	break;

		case 'D': 
		case 'd': return PIND;	break;
	}
	return -1;
}

S8_t Dio_Read_pin (u8_t port_name, u8_t pin_num){
	switch (port_name)
	{
		case 'A': 
		case 'a': return rd_bit(PINA,pin_num);	break;

		case 'B': 
		case 'b': return rd_bit(PINB,pin_num);	break;

		case 'C': 
		case 'c': return rd_bit(PINC,pin_num);	break;

		case 'D': 
		case 'd': return rd_bit(PIND,pin_num);	break;
	}
	return -1;
}

void Dio_set_pin (u8_t port_name,u8_t pin_number){
	switch (port_name)
	{
		case 'A': 
		case 'a': SETBIT(PORTA,pin_number);	break;

		case 'B': 
		case 'b': SETBIT(PORTB,pin_number);	break;

		case 'C': 
		case 'c': SETBIT(PORTC,pin_number);	break;

		case 'D': 
		case 'd': SETBIT(PORTD,pin_number);	break;
	}
}
void Dio_clr_pin (u8_t port_name,u8_t pin_number){
	switch (port_name)
	{
		case 'A': 
		case 'a': CLRBIT(PORTA,pin_number);	break;

		case 'B': 
		case 'b': CLRBIT(PORTB,pin_number);	break;

		case 'C': 
		case 'c': CLRBIT(PORTC,pin_number);	break;

		case 'D': 
		case 'd': CLRBIT(PORTD,pin_number);	break;
	}
}
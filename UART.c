/*
 * usart.c
 *
 * Created: 12/7/2014 5:10:39 PM
 *  Author: Administrator
 */ 



#include "UART.h"
void Uart_init(uint16_t baud_rate){
	// baud rate
	uint16_t ubr = ((F_CPU)/(baud_rate*16UL)-1);
	UBRRL = (uint8_t)ubr;
	UBRRH = (uint8_t)(ubr >> 8);

	/* Enable receiver and transmitter */
	UCSRB = (1<<RXEN)|(1<<TXEN);
	UCSRC=(1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);
}

void Uart_Write(uint8_t data){
	/* Wait for empty transmit buffer */
	while ( !( UCSRA & (1<<UDRE)) );  // check trans
	UDR = data;
}

void Uart_Write_string(uint8_t *data){
	for(uint8_t i = 0; data[i] != '\0'; i++)
		Uart_Write(data[i]);
}

uint8_t Uart_Read(){
	while ( !(UCSRA & (1<<RXC)) );
	return UDR;
}

uint8_t Uart_available(){
    if( (UCSRA & (1<<RXC)) ){
		return 1;
	}
	return 0;
}
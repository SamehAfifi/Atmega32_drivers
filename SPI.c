/*
 * SPI.c
 *
 * Created: 9/28/2018 7:28:43 PM
 *  Author: safifi
 */ 

#include "SPI.h"
#define MOSI PB7
#define MISO PB6
#define CS	PB4
#define CLK PB5

void SPI_master_init(){
	DDRB |= (1<<MOSI)|(1<<CS)|(1<<CLK);
	SPCR = 1<<MSTR | 1<<SPE;
}
void SPI_slave_init(){	
	SETBIT(DDRB,MISO);	// MISO
	SETBIT(SPCR,SPE);	// enable SPI
}
void SPI_send_char(uint8_t data){
	SPDR = data;
	while(GETBIT(SPSR,SPIF) == 0);
}
uint8_t SPI_receive_char(){
	while(GETBIT(SPSR,SPIF) == 0);
	return SPDR;
}

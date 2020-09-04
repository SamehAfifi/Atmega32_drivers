#include "I2C.h"
#define F_SCL 400000UL // SCL frequency
#define Prescaler 1
#define TWBR_val ((((F_CPU / F_SCL) / Prescaler) - 16 ) / 2)


void I2C_master_init(void)
{
	TWBR = 12; // for 400K scl and 16Mhz freq uc
}

void I2C_master_start()
{
	// transmit START condition
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
	// wait for end of transmission
	while( GETBIT(TWCR,TWINT) == 0);
}
	
	
	
	
void I2C_master_addr(uint8_t addr)
{ // for write op you should put 0 on LSB 
	// load slave address into data register
	TWDR = addr<<1; // write operation
	// start transmission of address
	TWCR = (1<<TWINT) | (1<<TWEN);
	// wait for end of transmission
	while( GETBIT(TWCR,TWINT) == 0);
}


void I2C_master_write(uint8_t data)
{
	// load data into data register
	TWDR = data;
	// start transmission of data
	TWCR = (1<<TWINT) | (1<<TWEN);
	// wait for end of transmission
	while( !(TWCR & (1<<TWINT)) ); 
//	while( GETBIT(TWCR,TWINT) == 0);
}



void I2C_master_stop(void)
{
	// transmit STOP condition
	TWCR = (1<<TWINT) | (1<<TWSTO) | 1<<TWEN;
}


void I2C_slave_Init(uint8_t My_Add){
	TWAR = My_Add<<1;
}

uint8_t I2C_slave_avialable(){
	TWCR  = (1<<TWEN) | (1<<TWINT) |(1<<TWEA);
	while( GETBIT(TWCR,TWINT) == 0);
    if(TWSR == 0x60) return 1;
	else return 0;
}

uint8_t I2C_slave_read(void)
{
	// start TWI module and acknowledge data after reception
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA);
	// wait for end of transmission
	while( GETBIT(TWCR,TWINT) == 0);
	// return received data from TWDR
	return TWDR;
}




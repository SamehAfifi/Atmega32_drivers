/*
 * CFile1.c
 *
 * Created: 4/11/2020 6:35:44 PM
 *  Author: safifi
 */ 
#include "EEPROM.h"

uint8_t EEPROM_read(uint16_t add){ // 0 to 1023
	while(GETBIT(EECR,EEWE) == 1){};
	EEAR = add;
	SETBIT(EECR,EERE);
	return EEDR;

}	
void EEPROM_write(uint16_t add, uint8_t data){
	while(GETBIT(EECR,EEWE) == 1);
	EEAR = add;
	EEDR = data;
	SETBIT(EECR,EEMWE);
	SETBIT(EECR,EEWE);

}
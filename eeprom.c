/*
 * EEPROM.c
 *
 * Created: 9/4/2021 1:34:58 PM
 *  Author: safifi
 */ 

#include "EEPROM.h"


uint8_t EEPROM_read(uint16_t addr){
	while(READBIT(EECR,EEWE) == 1){}
	EEAR = addr;
	SETBIT(EECR,EERE);
	return EEDR;
}

void EEPROM_write(uint16_t addr, uint8_t data){
	while(READBIT(EECR,EEWE) == 1){}
	EEAR = addr;
	EEDR = data;
	SETBIT(EECR, EEMWE);
	SETBIT(EECR, EEWE);
}
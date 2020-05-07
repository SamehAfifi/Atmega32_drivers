/*
 * EEPROM.h
 *
 * Created: 4/11/2020 6:36:07 PM
 *  Author: safifi
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_
#include "Header.h"

uint8_t EEPROM_read(uint16_t add); // 0 to 1023
void EEPROM_write(uint16_t add, uint8_t data);



#endif /* EEPROM_H_ */
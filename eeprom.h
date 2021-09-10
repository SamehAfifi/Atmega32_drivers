/*
 * EEPROM.h
 *
 * Created: 9/4/2021 1:35:09 PM
 *  Author: safifi
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

#include "headers.h"

/*****************************************************************************
* Function Name: EEPROM_read
* Purpose      : read from location (addr) and return value in this location
* Parameters   : addr: address of EEPROM location range from 0 to 1023
* Return value : uint8_t: 1 byte which refer to value in location (addr) in EEPROM
*****************************************************************************/
uint8_t EEPROM_read(uint16_t addr);


/*****************************************************************************
* Function Name: EEPROM_write
* Purpose      : write (data) on location (addr)
* Parameters   : addr: address of EEPROM location
*                data: data to be write 
* Return value : void
*****************************************************************************/
void EEPROM_write(uint16_t addr, uint8_t data);


#endif /* EEPROM_H_ */
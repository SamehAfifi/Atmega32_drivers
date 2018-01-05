#ifndef  SPI_AVR_H_
#define  SPI_AVR_H_

#include "std_macros.h"
void SPI_Master_Init();
void SPI_Slave_Init();
uint8_t SPI_Tx_Rx(uint8_t data);

#endif
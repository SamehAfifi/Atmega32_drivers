/*
 * SPI.h
 *
 * Created: 9/28/2018 7:28:55 PM
 *  Author: safifi
 */ 


#ifndef SPI_H_
#define SPI_H_

#include "header.h"
void SPI_master_init();
void SPI_slave_init();
void SPI_send_char(uint8_t data);
uint8_t SPI_receive_char();


#endif /* SPI_H_ */
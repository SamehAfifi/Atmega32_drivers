#ifndef I2C_MASTER_H
#define I2C_MASTER_H

#define I2C_READ 0x01
#define I2C_WRITE 0x00

#include "std_macros.h"

#include <util/twi.h>

void I2C_init(void);
uint8_t I2C_start(uint8_t address);
uint8_t I2C_write(uint8_t data);
uint8_t I2C_read_ack(void);
void I2C_stop(void);
unsigned char I2C_Slave_avialable();
void I2C_Slave_Init(unsigned char My_Add);
#endif // I2C_MASTER_H
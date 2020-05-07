/*
 * IMU.h
 *
 * Created: 12/23/2014 1:10:10 PM
 *  Author: Administrator
 */ 


#ifndef IMU_H_
#define IMU_H_

#include "type.h"

void IMU_Serial_Init(u16_t baud);

void IMU_I2C_Init(u8_t address);

u8_t IMU_I2C_Data(u16_t *dat);

u8_t IMU_Serial_Data(u16_t *dat);

#endif /* IMU_H_ */
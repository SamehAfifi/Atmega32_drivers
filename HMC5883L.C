/*
 * HMC5883L.C
 *
 * Created: 12/19/2014 4:51:52 PM
 *  Author: Administrator
 */ 
#include "I2C.h"
#include <math.h>
#include "std_fcpu.h"
#include "lcd.h"
#include "itoa.h"
#define HMCRead 0x3d
#define HMCWrite 0x3c

void HMC_Init_void(){
	I2C_Master_Init(100000);

	I2C_Start(HMCWrite);
	I2C_Write(0x00);
	I2C_Write(0x70);
	I2C_Stop();

	I2C_Start(HMCWrite);
	I2C_Write(0x01);
	I2C_Write(0xA0);
	I2C_Stop();

	I2C_Start(HMCWrite);
	I2C_Write(0x02);
	I2C_Write(0x00);
	I2C_Stop();
}

u16_t HMC_read(u16_t *x, u16_t *y, u16_t *z){

	I2C_Start(HMCWrite);
	I2C_Write(0x03);
	I2C_Stop();
	
	/*Read data from Compass*/
	I2C_Start(HMCRead);

	*x = (I2C_Read_ACK())<<8;
	*x |= (u8_t)(I2C_Read_ACK());

	*z = (I2C_Read_ACK())<<8;
	*z |= (u8_t)(I2C_Read_ACK());
	
	*y = (I2C_Read_ACK())<<8;
	*y |= (u8_t)(I2C_Read_NACK());

	I2C_Stop();

    // convert the raw data into a heading in degrees
	float headingDegrees = atan2((double)(*y),(double)(*x))* 180 / 3.14159265 + 180;
	
	return (u16_t)headingDegrees;
}
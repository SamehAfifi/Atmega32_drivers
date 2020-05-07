/*
 * IMU.c
 *
 * Created: 12/23/2014 1:09:58 PM
 *  Author: Administrator
 */ 
//A: most significant number
#include "type.h"
#include "usart.h"
#include "StrTo_Int_ToStr.h"
#include "std_fcpu.h"
#include "I2C.h"
#include "IMU.h"
#define true 1
#define false 0
static int power(u8_t num, u8_t index){
	u8_t i;
	u32_t por = 1;

	for(i = 0; index > i;i++)
	por *= num;

	return por;
}

static u16_t to_number(	u8_t *buffer,u8_t index)
{
	u16_t sum = 0;
	u8_t i;
	
	for(i = 0; index >= i; i++)
	{
		sum += ((buffer[i]-48)*power(10,index-i));
	}
	return sum;
}

static u16_t to_deg(u8_t A, u8_t B)
{
	u16_t angel = 0;
	if (B < 128){
		angel = (B * 256 + A) / 100.00;
	}
	else
	{
		angel = -((256-B) * 256 - A) / 100.00;
		angel += 360;
	}
	return angel;
}

void IMU_Serial_Init(u16_t baud){
	Uart_Baudrate(baud);
}

void IMU_I2C_Init(u8_t address){
	I2C_Slave_Init(address);
}

u8_t IMU_Serial_Data(u16_t *dat)
{
	if(Uart_available())
	{
		if(Uart_Read() != 'D') return false;

    	u8_t check = 0;
		while (check != 9)
		{
			/*Get angel*/
			u8_t LSB = 0;
			u8_t MSB = 0;
			u8_t i = 0;
			for (; i++ < 2;)
			{
				u8_t buffer[3];
				u8_t index = 0;
				do
				{
					while(!Uart_available());
					buffer[index++] = Uart_Read();
				}
				while (buffer[index-1] != 's');
				index -= 2;
				
				if (i == 1)
				LSB = to_number(buffer,index);
				else
				MSB = to_number(buffer,index);
			}
			dat[check++] = to_deg(LSB,MSB);
		}
		return true;
	}
	return false;
}

u8_t IMU_I2C_Data(u16_t *Data_){
	u8_t buffer[2];
	u8_t i;
	if(!I2C_Slave_avialable()) return 0;
	for (i = 0; i < 9; i++){
		buffer[0] = I2C_Read_NACK();
		buffer[1] = I2C_Read_NACK();
		Data_[i] = to_deg(buffer[0], buffer[1]);
	}
	return 1;
}

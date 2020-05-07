#ifndef _DIO
#define _DIO


#include "../service_layer/type.h"

extern void Dio_init_port (u8_t port_name, u8_t status);
extern void Dio_init_pin (u8_t port_name, u8_t pin_number, u8_t);

extern void Dio_write_port(u8_t port_name,u8_t write);
extern S8_t Dio_Read_port (u8_t port_name);

extern S8_t Dio_Read_pin (u8_t port_name, u8_t pin_number);

extern void Dio_set_pin (u8_t port_name,u8_t pin_number);
extern void Dio_clr_pin (u8_t port_name,u8_t pin_number);
extern void Dio_tog_pin (u8_t port_name,u8_t pin_number);

#endif
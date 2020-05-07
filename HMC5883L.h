/*
 * HMC5883L.h
 *
 * Created: 12/19/2014 4:50:28 PM
 *  Author: Administrator
 */ 


#ifndef HMC5883L_H_
#define HMC5883L_H_

#include "type.h"
extern void HMC_Init_void();
extern u16_t HMC_read(u16_t *x, u16_t *y, u16_t *z);

#endif /* HMC5883L_H_ */
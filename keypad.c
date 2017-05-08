#include "keypad.h"
uint8_t keypad_matrix[]={
	'1','2','3','4',
	'5','6','7','8',
	'9','A','B','C',
	'D','E','F','G',
};
void keypad_init(){
	mykeypadport
	pullup
}
int8_t press(int8_t i){
	if(!k5 )return keypad_matrix[0+i*4];
	if(!k6 )return keypad_matrix[1+i*4];
	if(!k7 )return keypad_matrix[2+i*4];
	if(!k8 )return keypad_matrix[3+i*4];
	_delay_ms(10);
	return -1;
}
int8_t keypad_click(){
	int8_t k;
	k1(0);k2(1);k3(1);k4(1);	k = press(0); if(k != -1)	return k;
	k1(1);k2(0);k3(1);k4(1);	k = press(1); if(k != -1)	return k;
	k1(1);k2(1);k3(0);k4(1);	k = press(2); if(k != -1)	return k;
	k1(1);k2(1);k3(1);k4(0);	k = press(3); if(k != -1)	return k;
	return -1;
}
/*
 * lcd.c
 *
 * Created: 9/4/2021 11:16:13 AM
 *  Author: safifi
 */ 
#include "lcd.h"


void LCD_init(){
	INIT_LCD_PINS();
	LCD_write_command(0x3);
	DELAY_MS(4);
	LCD_write_command(0x3);
	DELAY_MS(4);
	LCD_write_command(0x3);
	DELAY_MS(4);
	LCD_write_command(0x2);
	LCD_write_command(0x28);
	LCD_write_command(0x08);
	LCD_write_command(0x01);
	LCD_write_command(0x06);
	LCD_write_command(0x01);
	LCD_write_command(0x0C);
	DELAY_MS(20);
}
// 0x28 ---- 2= 0010 (D7,D6,D5,D4) EN(1) delay_ms(1) EN(0) delay_ms(1)
void LCD_write_command(uint8_t cmd){
	RS(0);
	D7(READBIT(cmd,7));
	D6(READBIT(cmd,6));
	D5(READBIT(cmd,5));
	D4(READBIT(cmd,4));
	
	TRIGGER_LCD();
	
	D7(READBIT(cmd,3));
	D6(READBIT(cmd,2));
	D5(READBIT(cmd,1));
	D4(READBIT(cmd,0));
	
	TRIGGER_LCD();
}

void LCD_write_char(uint8_t data){
	RS(1);
	D7(READBIT(data,7));
	D6(READBIT(data,6));
	D5(READBIT(data,5));
	D4(READBIT(data,4));
	
	TRIGGER_LCD();
	
	D7(READBIT(data,3));
	D6(READBIT(data,2));
	D5(READBIT(data,1));
	D4(READBIT(data,0));
	
	TRIGGER_LCD();

}
void LCD_write_string(uint8_t* txt){
	uint8_t i = 0;
	while(txt[i] != '\0'){
		LCD_write_char(txt[i]);
		i++;
	}
}
/* 1234 % 10 --- 4
   123 %  10 ----3
   12  %  10 ----2
   1   %  10 ----1
   0
*/
void LCD_write_num(uint32_t num){
	int8_t i = 0;
	uint8_t num_arr[10];
	
	if(num == 0) LCD_write_char('0');
	
	for(i = 0; num != 0 ;i++){
		num_arr[i] = num % 10 + 48;
		num /= 10;
	}
	i--;
	while (i >= 0){
		LCD_write_char(num_arr[i]);
		i--;
	}
}
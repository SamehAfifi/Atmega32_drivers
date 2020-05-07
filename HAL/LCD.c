/*
CMD :
1  // clr screen
2  // return to 0,0 line

4  // DEC  cursor shift cursor left
6  // INC  cursor shift cursor right

5  // shift display left
7  // shift display right

8  // display and cursor off
A  // display off cursor on
C  // display on cursor off
E  // display on cursor on

10 // shift cursor pos to left
14 // shift cursor pos to right

18 // shift display left
1C // shift display right

80 //force cursor to beginning of 1st line
C0 //force cursor to beginning of 2nd line

*/

#include "LCD.h"
#define CLEAR 0x01
#define HOME 0x02
#define SHIFT_CUR_L 0x10
#define SHIFT_CUR_R 0x14
#define SHIFT_DIS_L 0x18
#define SHIFT_DIS_R 0x1C
#define LINE_TWO 0xC0
#define LINE_ONE 0x80

void LCD_init(){
	INIT_LCD();
	LCD_write_command(0x3);
	_delay_ms(4);
	LCD_write_command(0x3);
	_delay_ms(4);
	LCD_write_command(0x3);
	_delay_ms(4);
	LCD_write_command(0x2);
	LCD_write_command(0x28);
	LCD_write_command(0x8);
	LCD_write_command(0x1);
	LCD_write_command(0x6);
	LCD_write_command(0xc);
	_delay_ms(20);
}

void LCD_write_command(uint8_t cmd){ // 0x20 // 0b0010 0000
	 RS(0);
	 // send most byte
	 D4(GETBIT(cmd,4));
	 D5(GETBIT(cmd,5));
	 D6(GETBIT(cmd,6));
	 D7(GETBIT(cmd,7));
	 EN(1);
	 _delay_ms(1);
	 EN(0);
	 _delay_ms(1);
	 
	 // send least byte
	 
	 D4(GETBIT(cmd,0));
	 D5(GETBIT(cmd,1));
	 D6(GETBIT(cmd,2));
	 D7(GETBIT(cmd,3));
	 EN(1);
	 _delay_ms(1);
	 EN(0);
	 _delay_ms(1);
}

void LCD_write_char(uint8_t data){
	 RS(1);
	 // send most byte
	 D4(GETBIT(data,4));
	 D5(GETBIT(data,5));
	 D6(GETBIT(data,6));
	 D7(GETBIT(data,7));
	 EN(1);
	 _delay_ms(1);
	 EN(0);
	 _delay_ms(1);
	 
	 // send least byte
	 
	 D4(GETBIT(data,0));
	 D5(GETBIT(data,1));
	 D6(GETBIT(data,2));
	 D7(GETBIT(data,3));
	 EN(1);
	 _delay_ms(1);
	 EN(0);
	 _delay_ms(1);	 
}


void LCD_write_string(uint8_t txt[]){
	for(uint8_t i = 0; txt[i] != '\0'; i++){
		LCD_write_char(txt[i]);
	}
}


/*
1234 %10 --> 4
1234 / 10 = 123

123%10 --> 3
123/10 = 12

12%10 --> 2
12/10 = 1

1%10 --> 1
1/10 = 0




1 2 3 4
1+48
2+48
3+48
4+48

*/
void LCD_write_num(uint32_t num){
	uint8_t txt[10] = {0};
	int8_t i = 0;
	if(num == 0) {
		LCD_write_char('0');
		return;
	}		
	for (i = 0; num != 0; i++ )
	{
		txt[i] = num%10 + 48;
		num = num  / 10 ;
	}
	i--;
	while(i >= 0){
		LCD_write_char(txt[i]);
		i--;
	}
}
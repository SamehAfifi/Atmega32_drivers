/*
 * lcd.h
 *
 * Created: 9/4/2021 11:16:23 AM
 *  Author: safifi
 */ 


#ifndef LCD_H_
#define LCD_H_

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

D7: PORTA 7
D6: PORTA 6
D5: PORTA 5
D4: PORTA 4
RS: PORTA 3 
EN: PORTA 2
*/



#include "headers.h"

#define CLEAR 0x01
#define HOME 0x02
#define SHIFT_CUR_L 0x10
#define SHIFT_CUR_R 0x14
#define SHIFT_DIS_L 0x18
#define SHIFT_DIS_R 0x1C
#define LINE_TWO 0xC0
#define LINE_ONE 0x80

#define INIT_LCD_PINS() DDRA |= 0b11111100; \
                        PORTA &= 0b00000011;
						
#define D7(val) if(val == 0)  CLRBIT(PORTA,7); else  SETBIT(PORTA,7);
#define D6(val) if(val == 0)  CLRBIT(PORTA,6); else  SETBIT(PORTA,6);
#define D5(val) if(val == 0)  CLRBIT(PORTA,5); else  SETBIT(PORTA,5);
#define D4(val) if(val == 0)  CLRBIT(PORTA,4); else  SETBIT(PORTA,4);
#define RS(val) if(val == 0)  CLRBIT(PORTA,3); else  SETBIT(PORTA,3);
#define EN(val) if(val == 0)  CLRBIT(PORTA,2); else  SETBIT(PORTA,2);
 
#define TRIGGER_LCD() EN(1); _delay_ms(1); EN(0); _delay_ms(1);  

#define DELAY_MS(x) _delay_ms(x);

#include "headers.h"

/*****************************************************************************
* Function Name: LCD_init
* Purpose      : initialize LCD to work in 4-bit mode - 
* Parameters   : void
* Return value : void
*****************************************************************************/
void LCD_init(void);

/*****************************************************************************
* Function Name: LCD_write_command
* Purpose      : Send a specific command (cmd) to lcd (valid only with 4-bit mode)
* Parameters   : cmd  (command to be done by lcd)
* Return value : void
*****************************************************************************/
void LCD_write_command(uint8_t cmd);

/*****************************************************************************
* Function Name: LCD_write_char
* Purpose      : Write a specific ascii char (data) to lcd (valid only with 4-bit mode)
* Parameters   : data  (data to be written on lcd)
* Return value : void
*****************************************************************************/
void LCD_write_char(uint8_t data);

/*****************************************************************************
* Function Name: LCD_write_string
* Purpose      : Write a string (*txt) to lcd (valid only with 4-bit mode) 
*                (assume the end char of string is NULL (Ascii:'\0' - decimal:0 ))
* Parameters   : *txt  (array of char to be written on lcd)
* Return value : void
*****************************************************************************/
void LCD_write_string(uint8_t* txt);

/*****************************************************************************
* Function Name: LCD_write_num
* Purpose      : Write a specific number (num) on lcd (valid only with 4-bit mode)
* Parameters   : num  (num to be written on lcd)
* Return value : void
*****************************************************************************/
void LCD_write_num(uint32_t num);


#endif /* LCD_H_ */
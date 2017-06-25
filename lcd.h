/*
 * lcd.h
 *
 * Created: 13/26/2014 7:40:00 PM
 *  Author: safifi
 */
#include "std_macros.h"
#define clear 0x01
#define home  0x02
#define inc_cur_left 0x04
#define inc_cur_right 0x06

#define shift_cur_left 0x10
#define shift_cur_right 0x14
#define shift_display_left 0x18
#define shift_display_right 0x1c

#define nd_line 0xc0
#define st_line 0x80
#define INIT_PORT DDRA |= 0xf0; DDRB |= 0x0e;


#define EN(x)   if (x == 0) CLRBIT(PORTB,3); else SETBIT(PORTB,3);;
#define Rw(x)   if (x == 0) CLRBIT(PORTB,2); else SETBIT(PORTB,2);;
#define RS(x)   if (x == 0) CLRBIT(PORTB,1); else SETBIT(PORTB,1);;
#define D7(x)   if (x == 0) CLRBIT(PORTA,7); else SETBIT(PORTA,7);;
#define D6(x)   if (x == 0) CLRBIT(PORTA,6); else SETBIT(PORTA,6);;
#define D5(x)   if (x == 0) CLRBIT(PORTA,5); else SETBIT(PORTA,5);;
#define D4(x)   if (x == 0) CLRBIT(PORTA,4); else SETBIT(PORTA,4);;

// configure LCD port
void lcd_init();

// to  send command to LCD
void lcd_write_cmd(uint8_t);

// to  send data to LCD
void lcd_write_char(uint8_t);

// write complete txt
void lcd_write_txt(uint8_t *);

// write number 
void lcd_write_number(uint16_t data);

// to update data
void lcd_send_pulse_for_update_data_or_cmd();

//Convert from int to ascii string
void IntToString(uint16_t number, uint8_t *txt);

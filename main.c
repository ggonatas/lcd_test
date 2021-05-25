/*
 * Hello_LCD.c
 *
 * Created: 5/25/2021 11:08:15 AM
 * Author : George Gonatas
 */ 

#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "lcd_lib.h"

void init_mcu()
{
	PORTA_OUT |= 0x00; //Set all PortA outputs to low
	PORTA_DIR |= 0xFF; //Set PortA pins as output
	PORTB_OUT |= 0x00; //Set all PortB outputs to low
	PORTB_DIR |= 0x07; //Set PortB pins 0-2 as output
}

void init_lcd()
{
	//Clear the display
	send_command(0x01, 1);
	//Set cursor to home
	send_command(0x02, 1);
	//Set entry mode to increment and no shift
	send_command(0x06, 0);
	//Turn on display and don't show/blink cursor
	send_command(0x0C, 0);
	//Set to 8-bit bus mode, 1-line display, small font
	send_command(0x30, 0);
}




int main(void)
{
	init_mcu();
	init_lcd();
	uint8_t write_char;
    
    //Write 'Hello World' to the LCD
	write_char = 0x48; //H
	send_character(write_char);
	write_char = 0x65; //e
	send_character(write_char);
	write_char = 0x6C; //l
	send_character(write_char);
	write_char = 0x6C; //l
	send_character(write_char);
	write_char = 0x6F; //o
	send_character(write_char);
	write_char = 0x20; // space
	send_character(write_char);
	write_char = 0x57; //W
	send_character(write_char);
	write_char = 0x6F; //o
	send_character(write_char);
	write_char = 0x72; //r
	send_character(write_char);
	write_char = 0x6C; //l
	send_character(write_char);
	write_char = 0x64; //d
	send_character(write_char);
	write_char = 0x21;
	send_character(write_char);
}




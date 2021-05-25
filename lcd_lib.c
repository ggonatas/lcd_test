
#include <avr/io.h>
#include <util/delay.h>
#include "lcd_lib.h"

#define delay_long 1.52
#define delay_short 37.0

//Checks if LCD is busy.  Returns 0 if not, non-zero otherwise
int check_busy()
{
	PORTA_DIR &= ~(1<<7);	//Set Pin B7 as input
	PORTB_OUT |= (1<<1);	//Set LCD to read
	PORTB_OUT &= ~(1<<2);	//Set LCD to command
	int busy = PORTA_OUT & (1<<7);	//Get if busy
	PORTA_DIR |= (1<<7);	//Set Pin B7 as output
	return busy;
}

void send_command(uint8_t command, int milli)
{
	//Wait for LCD to not be busy
	while (check_busy());
	
	PORTA_DIR |= 0xFF; //Set Port A as output
	PORTB_OUT &= ~(1<<1);	//Set LCD to write
	PORTB_OUT &= ~(1<<2);	//Set LCD to command
	PORTA_OUT = command;	//Write command for LCD
	PORTB_OUT |= (1<<0);	//Enable LCD
	if (milli > 0)
		_delay_ms(delay_long);
	else
		_delay_us(delay_short);
	PORTB_OUT &= ~(1<<0);	//Disable LCD
}

void send_character(uint8_t character)
{
	//Wait for LCD to not be busy
	while (check_busy());
	
	PORTA_DIR |= 0xFF; //Set Port A as output
	PORTB_OUT &= ~(1<<1);	//Set LCD to write
	PORTB_OUT |= (1<<2);	//Set LCD to command
	PORTA_OUT = character;	//Write command for LCD
	PORTB_OUT |= (1<<0);	//Enable LCD
	_delay_us(37); //Delay for 37 us
	PORTB_OUT &= ~(1<<0);	//Disable LCD
}
#ifndef LCDLIB_H
#define LCDLIB_H

int check_busy();

void send_command(uint8_t command, int milli);

void send_character(uint8_t character);

#endif
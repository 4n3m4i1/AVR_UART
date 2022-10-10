


#ifndef ATMEGA328P_UART_H
#define ATMEGA328P_UART_H

#include <avr/io.h>

#ifndef F_CPU
#warning "F_CPU Required!\n"
#define F_CPU   16000000UL
#endif

#ifndef BAUD
#warning "BAUD Required!\n"
#define BAUD    9600
#endif

#ifndef USARTARG
#define USARTARG    F_CPU/16/BAUD-1
#endif

#define NEWLINE 10

void init_serial(unsigned int someVal);
void serialWrite(unsigned char data);
uint8_t serialGet();
void serialWriteStr(char *inpu);
void serialWriteNl(unsigned char data);
void printStr(uint8_t data);
void printBin8(uint8_t data);








#endif


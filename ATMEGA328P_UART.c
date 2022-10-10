#include "ATMEGA328P_UART.h"


void init_serial(unsigned int someVal){         // Debug for use with development boards

	// Set Baud rate
	UBRR0H = (unsigned char)(someVal >> 8);
	UBRR0L = (unsigned char)(someVal);

	// Enable Tx and Rx
	UCSR0B = (1 << RXEN0) | (1 << TXEN0);

	// Setup 8N2 format // Change to 8N1 later
	//UCSR0C = (1 << USBS0) | (3 << UCSZ00);

    // 8N1 Format
    UCSR0C = (3 << UCSZ00);
}


void serialWrite(unsigned char data){
	while(!(UCSR0A & (1 << UDRE0)));			// Wait for empty transmit buffer
	UDR0 = data;
}

uint8_t serialGet(){
  while(!(UCSR0A) & (1 << RXC0));
  return UDR0;
}

void serialWriteStr(char *inpu){
  uint8_t n = 0;
  while(inpu[n]){
    serialWrite(inpu[n]);
    n = n + 1;
  }
}


void serialWriteNl(unsigned char data){
	serialWrite(data);
	serialWrite(NEWLINE);
}

void printStr(uint8_t data){
	if(!data){
		serialWrite('0');
		return;
	}
	uint8_t zero_rejection = 0, tctr__ = 0;

	for(uint16_t n = 1000; n > 0; n/= 10){
		switch(data / n){
			case 0:
			if(zero_rejection){
				serialWrite('0');
			}
				break;
			case 1:
				serialWrite('1');
				zero_rejection = 0x01;
				break;
			case 2:
				serialWrite('2');
				zero_rejection = 0x01;
				break;
			case 3:
				serialWrite('3');
				zero_rejection = 0x01;
				break;
			case 4:
				serialWrite('4');
				zero_rejection = 0x01;
				break;
			case 5:
				serialWrite('5');
				zero_rejection = 0x01;
				break;
			case 6:
				serialWrite('6');
				zero_rejection = 0x01;
				break;
			case 7:
				serialWrite('7');
				zero_rejection = 0x01;
				break;
			case 8:
				serialWrite('8');
				zero_rejection = 0x01;
				break;
			case 9:
				serialWrite('9');
				zero_rejection = 0x01;
				break;
			default:
				break;
		}
		tctr__ += 1;
		
		data = data % n;
	}
}

void printBin8(uint8_t data){
	for(uint8_t n = 0; n < 8; n++){
		uint8_t tm_ = (data >> (7 - n)) & (0x01);
		if(tm_){
			serialWrite('1');
		} else {
			serialWrite('0');
		}
	}
}
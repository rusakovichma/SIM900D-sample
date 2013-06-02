#include <string.h>
//#include <avr/pgmspace.h>
#include "template.h"
#include "uart.h"
#include "sim900.h"

const char successResp[] = "OK";
const char failResp[] = "ERROR";
const char inNetResp[] = "+CREG: 0,1";
const char outNetResp[] = "+CREG: 0,2";
const char messageSendResp[] = "+CMGS: ";

char buffer[];

unsigned char getCommByte(unsigned int data);
void sendCRLF();

char *getAnswer(){
	char cmd_buff[20];
    unsigned int c = UART_NO_DATA;
	int j=0;
	while(1){
		c = uart_getc();
		if (c != UART_NO_DATA){
			unsigned char answerChar = getCommByte(c);
			if (answerChar == CR && j!=0){
				break;
			} else if (answerChar != LF && answerChar!= CR){
			  cmd_buff[j] = answerChar;
			  j++;
			}
		}
	}
	return cmd_buff;	
}

void simPowerOn(){
	delay(startDelay);
	SetBit(pwrDDR, pwrPin);
	ClrBit(pwrPORT, pwrPin);
	delay(initDelay);
	ClrBit(pwrDDR, pwrPin);
}

void simCommInit(){
	uart_init( UART_BAUD_SELECT(UART_BAUD_RATE,F_CPU) );
	delay(commDelay);
	uart_puts("AT+IPR=9600");
	sendCRLF();
	delay(commDelay);
	if (strncmp( getAnswer(), successResp, 2 ) != 0){
	 //sendError
	}
}

void waitForReg(){
	while(1){
		uart_puts("AT+CREG?");
		sendCRLF();
		delay(regDelay);
		if (strncmp( getAnswer(), inNetResp, 10 ) == 0){
			break;
		}	
	}
}

void simSetTextInput(){
	uart_puts("AT+CMGF=1");
	sendCRLF();
	delay(commDelay);
	if (strncmp( getAnswer(), successResp, 2 ) != 0){
	 //sendError
	}
}

void simSetPhone(){
	uart_puts("AT+CMGS=\"+375447747024\"");
	sendCRLF();
	delay(commDelay);
}

void *searchContact(char * contact, size_t len){
	buffer[30] = "AT+CPBF=\"";
	buffer[30] = strncat(buffer, contact, len);
	buffer[30] = strncat(buffer, "\"", 1);
	uart_puts(buffer);
	sendCRLF();
	delay(commDelay);
	return getAnswer();
}

void simSendMessage(){
	uart_puts("sim900 test");
	sendCRLF();
	delay(commDelay);
	uart_putc(inputEnd);
	if (strncasecmp( getAnswer(), messageSendResp, 7) != 0){
	 //sendError
	}	
}

unsigned char getCommByte(unsigned int data){
	return (data & 0x00FF);
}

void sendCRLF(){
	uart_putc(CR);
	uart_putc(LF);
}

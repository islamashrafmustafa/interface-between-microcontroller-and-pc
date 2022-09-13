/*
 * UsART.c
 *
 * Created: 9/3/2022 7:42:11 AM
 *  Author: hp
 */ 
#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "std_macros.h"
#include "USART.h"

void UART_vInit(unsigned long baud)
{
	// baud rate
	unsigned long UBRR;
	UBRR=(F_CPU/(16*baud))-1;
	UBRRH=(unsigned char)(UBRR>>8);
	UBRRL=(unsigned char)UBRR;
	// enable receiver and transmiter
	SET_BIT(UCSRB,RXEN);
	SET_BIT(UCSRB,TXEN);
	//	8 bit data , 1 stop bit , no parity bit
	UCSRC=(1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);
}

void UART_vsendData(char data)
{
	while(READ_BIT(UCSRA,UDRE)==0);
	UDR=data;
}

char UART_8uReceiveData(void)
{
	while(READ_BIT(UCSRA,RXC)==0);
	return UDR;
}

void UART_vsendstring(char *ptr)
{
	while(*ptr!=0)
	{
		UART_vsendData(*ptr);
		ptr++;
		_delay_ms(100);
	}
}
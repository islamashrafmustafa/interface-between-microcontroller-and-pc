/*
 * 44-USART_EX_2.c
 *
 * Created: 9/3/2022 7:33:47 AM
 * Author : hp
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "std_macros.h"
#include "USART.h"

char x;
int main(void)
{
	LCD_vInit();
    UART_vInit(9600);
    while (1) 
    {
		x=UART_8uReceiveData();
		LCD_vSend_char(x);
    }
}


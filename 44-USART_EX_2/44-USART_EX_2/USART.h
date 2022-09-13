/*
 * USART.h
 *
 * Created: 9/3/2022 7:35:04 AM
 *  Author: hp
 */ 

void UART_vInit(unsigned long baud);
void UART_vsendData(char data);
char UART_8uReceiveData(void);
void UART_vsendstring(char *ptr);
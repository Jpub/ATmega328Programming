/*
 *  아트멜 스튜디오와 아두이노로 배우는 ATmega328 프로그래밍
 *
 * 		Gyeongyong Heo (hgycap@deu.ac.kr)
 *			Department of Electronic Engineering
 *			Dong-eui University
 *  	2015. 07. 14
 */ 

#include <avr/io.h>
#include <avr/eeprom.h>
#include "UART.h"
int main(void)
{
	UART_INIT(); // UART 통신 초기화
	uint8_t *p1, *p2;
	p1 = 0;
	p2 = p1 + 1; // p1 번지에 uint8_t 데이터 형의 바이트 수를 더한 값 = 1
	UART_printString("P1 : ");
	UART_print16bitNumber((uint16_t)p1);
	UART_printString("\n");
	UART_printString("P2 : ");
	UART_print16bitNumber((uint16_t)p2);
	UART_printString("\n");
	uint16_t *p3, *p4;
	p3 = 0;
	p4 = p3 + 1; // p3 번지에 uint16_t 데이터 형의 바이트 수를 더한 값 = 2
	UART_printString("P3 : ");
	UART_print16bitNumber((uint16_t)p3);
	UART_printString("\n");
	UART_printString("P4 : ");
	UART_print16bitNumber((uint16_t)p4);
	UART_printString("\n");
	while(1);
	return 0;
}
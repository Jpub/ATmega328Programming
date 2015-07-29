/*
 *  아트멜 스튜디오와 아두이노로 배우는 ATmega328 프로그래밍
 *
 * 		Gyeongyong Heo (hgycap@deu.ac.kr)
 *			Department of Electronic Engineering
 *			Dong-eui University
 *  	2015. 07. 14
 */ 

#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>
#include "UART.h"

int main(int argc, char *argv[])
{
	char data = '0';

	UART_INIT();				// UART 통신 초기화
	while (1) {
		UART_transmit(data++);		// 카운터 값을 컴퓨터로 전달
		UART_transmit('\n');			// 줄바꿈
		
		if(data > '9') data = '0';
		
		_delay_ms(1000);
	}
	
	return 0;
}
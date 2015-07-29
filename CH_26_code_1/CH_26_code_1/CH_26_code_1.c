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
	unsigned char data;
	UART_INIT(); // UART 통신 초기화
	while (1) {
		data = UART_receive(); // 데이터 수신
		UART_transmit(data); // 수신된 문자 재전송
	}
	return 0;
}
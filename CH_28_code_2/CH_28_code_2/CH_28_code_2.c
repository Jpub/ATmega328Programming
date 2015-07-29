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
#include <avr/wdt.h>
#include <util/delay.h>
#include "UART.h"
int main(void)
{
	wdt_enable(WDTO_8S); // 워치독 타이머 만료 시간을 8초로 설정
	UART_INIT(); // UART 통신 초기화
	UART_printString("** Initialization **\n");
	uint16_t count = 0;
	while(1)
	{
		_delay_ms(1000); // 1초에 한 번 카운트 출력
		count++;
		UART_printString("Count : ");
		UART_print16bitNumber(count);
		UART_transmit('\n');
		wdt_reset(); // 워치독 타이머 리셋
	}
}
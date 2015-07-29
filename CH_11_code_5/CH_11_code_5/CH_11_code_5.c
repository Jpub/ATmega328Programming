/*
 *  아트멜 스튜디오와 아두이노로 배우는 ATmega328 프로그래밍
 *
 * 		Gyeongyong Heo (hgycap@deu.ac.kr)
 *			Department of Electronic Engineering
 *			Dong-eui University
 *  	2015. 07. 14
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "UART.h"			// UART 라이브러리 사용

void INIT_PORT(void)
{
	DDRB = 0x20;				// PB5 (디지털 13번 핀) 출력으로 설정
	PORTB = 0x00;				// LED는 꺼진 상태에서 시작
	
	DDRD = 0x00;				// 버튼 입력
	PORTD = 0x04;			// PD2 (디지털 2번 핀) 풀업 저항 사용
}

int main(void)
{
	UART_INIT();				// UART 통신 초기화
	INIT_PORT();				// 포트 설정
	int state = 0;				// 현재 버튼의 상태

	while(1){
		if(PIND & 0x04){
			state = 0;				// 버튼이 눌러지지 않은 상태로 표시
			PORTB = 0x00;			// LED 끄기
		}
		else{
			// 눌러지지 않은 상태에서 눌러진 상태로 바뀔 때마다 ‘*’ 문자 전송
			if(state == 0) UART_transmit('*');
			state = 1;				// 버튼이 눌러진 상태로 표시
			PORTB = 0x20;			// LED 켜기
			_delay_ms(100);			// 디바운싱
		}
	}
}
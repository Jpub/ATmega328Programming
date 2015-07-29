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
#define PRESCALER 1024 // 분주비
void Timer_init(void){
	TCCR0B |= (1 << CS02) | (1 << CS00); // 분주비 1024로 설정
}
uint8_t measure_distance(void)
{
	// 트리거 핀으로 펄스 출력
	PORTC |= (1 << PC0); // HIGH 값 출력
	_delay_us(10); // 10마이크로초 대기 
	PORTC &= ~(1 << PC0); // LOW 값 출력
	// 에코 핀이 HIGH가 될 때까지 대기
	TCNT0 = 0;
	while(!(PINC & 0x02))
	if(TCNT0 > 250) return 255; // 장애물이 없는 경우
	// 에코 핀이 LOW가 될 때까지의 시간 측정
	TCNT0 = 0; // 카운터를 0으로 초기화
	while(PINC & 0x02){
		if (TCNT0 > 250){ // 측정 불가능
			TCNT0 = 0;
			break;
		}
	}
	// 에코 핀의 펄스폭을 마이크로초 단위로 계산
	double pulse_width = TCNT0 * PRESCALER * 1000000.0 / F_CPU;
	return pulse_width / 58; // 센티미터 단위 거리 반환
}
int main(void)
{
	uint8_t distance;
	DDRC |= 0x01; // 트리거 핀 출력으로 설정
	DDRC &= ~0xFD; // 에코 핀 입력으로 설정
	UART_INIT(); // UART 통신 초기화
	Timer_init(); // 타이머 초기화
	while(1)
	{
		distance = measure_distance(); // 거리 측정
		UART_printString("Distance(cm) = ");
		UART_print8bitNumber(distance);
		UART_transmit('\n');
		_delay_ms(1000);
	}
}
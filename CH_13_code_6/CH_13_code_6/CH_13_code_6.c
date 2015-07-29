/*
 *  아트멜 스튜디오와 아두이노로 배우는 ATmega328 프로그래밍
 *
 * 		Gyeongyong Heo (hgycap@deu.ac.kr)
 *			Department of Electronic Engineering
 *			Dong-eui University
 *  	2015. 07. 14
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
ISR(INT0_vect)
{
	if(PIND & 0x04) PORTB = 0x00; // LED 끄기
	else PORTB = 0x20; // LED 켜기
}
void INIT_PORT(void)
{
	DDRB = 0x20; // PB5(디지털 13번 핀) 출력으로 설정
	PORTB = 0x00; // LED는 꺼진 상태에서 시작
	DDRD = 0x00; // 버튼 입력
	PORTD = 0x04; // PD2(디지털 2번 핀) 풀업 저항 사용
}
void INIT_INT0(void)
{
	EICRA |= (1 << INT0); // INT0 인터럽트 활성화
	EIMSK |= (1 << ISC00); // 버튼 상태 변화 감지
	sei(); // 전역적으로 인터럽트 허용
}
int main(void)
{
	INIT_PORT(); // 포트 설정
	INIT_INT0(); // INT0 인터럽트 설정
	while(1){ } // 이벤트 루프는 아무 일도 하지 않는다.
}
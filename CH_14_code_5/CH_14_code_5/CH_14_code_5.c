/*
 *  아트멜 스튜디오와 아두이노로 배우는 ATmega328 프로그래밍
 *
 * 		Gyeongyong Heo (hgycap@deu.ac.kr)
 *			Department of Electronic Engineering
 *			Dong-eui University
 *  	2015. 07. 14
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
ISR(TIMER1_COMPA_vect)
{
	TCNT1 = 0; // 자동으로 0으로 변하지 않는다.
}
int main(void)
{
	TCCR1B |= (1 << CS12) | (1 << CS10); // 분주비를 1024로 설정
	OCR1A = 0x2000; // 비교일치 기준값
	// 비교일치 인터럽트 발생 시 OC1A 핀의 출력을 반전
	TCCR1A |= (1 << COM1A0);
	DDRB |= (1 << PB1); // OC1A 핀(PB1 핀)을 출력으로 설정
	TIMSK1 |= (1 << OCIE1A); // 비교일치 인터럽트 허용
	sei(); // 전역적으로 인터럽트 허용
	while(1){ }
}
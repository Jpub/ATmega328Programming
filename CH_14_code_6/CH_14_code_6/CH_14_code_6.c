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

int main(void)
{
	TCCR1B |= (1 << CS12) | (1 << CS10);	// 분주비를 1024로 설정

	OCR1A = 0x2000;			// 비교일치 기준값
	
	// 비교일치 인터럽트 발생 시 OC1A 핀의 출력을 반전
	TCCR1A |= (1 << COM1A0);
	TCCR1B |= (1 << WGM12);		// CTC 모드 선택
	
	DDRB |= (1 << PB1);			// OC1A 핀(PB1 핀)을 출력으로 설정
	
	while(1){ }
}
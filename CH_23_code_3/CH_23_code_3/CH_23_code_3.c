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

#define ROTATION_DELAY 	1500	// 1초 대기
#define PULSE_MIN		(40000*0.0325)	// 최소 펄스 길이
#define PULSE_MID		3000
#define PULSE_MAX		(40000*0.1175)	// 최대 펄스 길이

void INIT_TIMER1(void)
{
	// Fast PWM 모드, TOP = ICR1
	TCCR1A |= (1 << WGM11);
	TCCR1B |= (1 << WGM12) | (1 << WGM13);
	
	TCCR1B |= (1 << CS11);		// 분주율 8, 2MHz
	
	ICR1 = 40000;				// 20ms 주기
	
	TCCR1A |= (1 << COM1A1);		// 비반전 모드
	
	//  OC1A (PB1, 아두이노 9번) 핀을 출력으로 설정
	DDRB |= (1 << PB1);
}

int main(void)
{
	INIT_TIMER1();
	
	while(1)
	{
		OCR1A = PULSE_MIN;		// 0도
		_delay_ms(ROTATION_DELAY);
		
		OCR1A = PULSE_MID;		// 90도
		_delay_ms(ROTATION_DELAY);
		
		OCR1A = PULSE_MAX;		// 180도
		_delay_ms(ROTATION_DELAY);
	}
}
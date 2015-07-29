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

void ADC_INIT(unsigned char channel)
{
	ADMUX |= 0x40; 			// AVCC를 기준 전압으로 선택
	
	ADCSRA |= 0x07;			// 분주비 설정
	ADCSRA |= (1 << ADEN);		// ADC 활성화
	ADCSRA |= (1 << ADATE);		// 자동 트리거 모드

	ADMUX |= ((ADMUX & 0xE0) | channel);	// 채널 선택
	ADCSRA |= (1 << ADSC);		// 변환 시작
}

int read_ADC(void)
{
	while(!(ADCSRA & (1 << ADIF)));	// 변환 종료 대기
	
	return ADC;				// 10비트 값을 반환
}

void PORT_INIT(void)
{
	DDRD = 0xFF;
}

int main(void)
{
	int value;
	uint8_t on_off;
	
	ADC_INIT(0);
	PORT_INIT();
	
	while(1)
	{
		value = read_ADC() >> 7;
		
		on_off = 0;
		for(int i = 0; i <= value; i++){
			on_off |= (0x01 << i);
		}
		PORTD = on_off;
	}
}
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

int main(void)
{
	int read;
	float input_voltage, temperature;
	
	UART_INIT();					// UART 통신 초기화
	ADC_INIT(1);					// AD 변환기 초기화
	
	while(1)
	{
		// 온도 센서의 출력 전압을 ADC를 거쳐 읽는다.
		read = read_ADC();
		
		// 0에서 1023 사이의 값을 0V에서 5V 사이 값으로 변환한다.
		input_voltage = read * 5.0 / 1023.0;
		
		// 10mV에 1℃이므로 100을 곱해서 현재 온도를 얻는다.
		temperature = input_voltage * 100.0;
		
		UART_print16bitNumber((int)temperature);	// 정수값으로 출력
		UART_transmit('\n');				// 줄바꿈

		_delay_ms(1000);				// 1초에 한 번 출력
	}
}
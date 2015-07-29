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

int main(void)
{
	uint8_t numbers[]
	= {0xFC, 0x60, 0xDA, 0xF2, 0x66, 0xB6, 0xBE, 0xE4, 0xFE, 0xE6};
	int count = 0;				// 현재 표시할 숫자
	DDRD = 0xFF;				// 제어핀 8개를 출력으로 설정
	
	while(1)
	{
		PORTD = numbers[count];		// 숫자 데이터 출력
		count = (count + 1) % 10;		// 다음에 표시할 숫자
		
		_delay_ms(100);			// 1초 대기
	}
	
	return 1;
}
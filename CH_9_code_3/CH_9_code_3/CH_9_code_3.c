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
	DDRD = 0xFF; // PORT D의 8개 핀을 출력으로 설정
	while(1)
	{
		PORTD = 0x80; // 1번 패턴
		_delay_ms(1000);
		PORTD = 0x40; // 2번 패턴
		_delay_ms(1000);
		PORTD = 0x20; // 3번 패턴
		_delay_ms(1000);
		PORTD = 0x10; // 4번 패턴
		_delay_ms(1000);
		PORTD = 0x08; // 5번 패턴
		_delay_ms(1000);
		PORTD = 0x04; // 6번 패턴
		_delay_ms(1000);
		PORTD = 0x02; // 7번 패턴
		_delay_ms(1000);
		PORTD = 0x01; // 8번 패턴
		_delay_ms(1000);
	}
	return 1;
}
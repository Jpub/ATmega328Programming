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
	DDRB = 0x20;

	while(1)
	{
		PORTB = 0x00;	// 끄기
		_delay_ms(500);
		PORTB = 0x20;	// 켜기
		_delay_ms(500);
	}

	return 1;
}

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
		for(int i = 0; i < 8; i++){
			char p1 = 0x01 << i; // 왼쪽에서 오른쪽으로 움직이는 LED
			char p2 = 0x01 << (7 - i); // 오른쪽에서 왼쪽으로 움직이는 LED
			PORTD = p1 | p2; // 2개의 LED 결합
			_delay_ms(1000);
		}
	}
	return 1;
}
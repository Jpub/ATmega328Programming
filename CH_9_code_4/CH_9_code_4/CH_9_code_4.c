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
	char patterns[] = {0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01};
	while(1)
	{
		for(int i = 0; i < 8; i++){
			PORTD = patterns[i]; // i번 패턴
			_delay_ms(1000);
		}
	}
	return 1;
}
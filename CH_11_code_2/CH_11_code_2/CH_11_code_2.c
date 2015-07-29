/*
 *  아트멜 스튜디오와 아두이노로 배우는 ATmega328 프로그래밍
 *
 * 		Gyeongyong Heo (hgycap@deu.ac.kr)
 *			Department of Electronic Engineering
 *			Dong-eui University
 *  	2015. 07. 14
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
void INIT_PORT(void)
{
	DDRB = 0x20; // PB5(디지털 13번 핀) 출력으로 설정
	PORTB = 0x00; // LED는 꺼진 상태에서 시작
	DDRD = 0x00; // 버튼 입력
	PORTD = 0x04; // PD2(디지털 2번 핀) 풀업 저항 사용
}
int main(void)
{
	INIT_PORT(); // 포트 설정
	while(1){
		if(PIND & 0x04) PORTB = 0x00; // LED 끄기
		else PORTB = 0x20; // LED 켜기
	}
}

/*
 *  아트멜 스튜디오와 아두이노로 배우는 ATmega328 프로그래밍
 *
 * 		Gyeongyong Heo (hgycap@deu.ac.kr)
 *			Department of Electronic Engineering
 *			Dong-eui University
 *  	2015. 07. 14
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
void Init_74595(void)
{
	// data pin   : 아두이노 11, PB3
	// latch clock pin   : 아두이노 12, PB4
	// shift clock pin   : 아두이노 13, PB5
	DDRB |= 0b00111000; // 제어 핀 3개를 출력으로 설정
}
void ShiftClock(void)
{
	PORTB |= 0b00100000; // 이동 클록을 HIGH로
	PORTB &= 0b11011111; // 이동 클록을 LOW로
}
void LatchClock(void)
{
	PORTB |= 0b00010000; // 래치 클록을 HIGH로
	PORTB &= 0b11101111; // 래치 클록을 LOW로
}
void WordDataWrite(uint16_t data) // 2바이트 데이터 출력
{
	for(uint8_t i = 0; i < 16; i++){
		if(data & 0x8000) // MSB부터 1비트 출력
		PORTB |= 0b00001000;
		else
		PORTB &= 0b11110111;
		ShiftClock(); // 1비트 출력 후 비트 이동
		data = data << 1; // 다음 출력할 비트를 MSB로 이동
	}
	LatchClock(); // 2바이트 전달 후 실제 출력 발생
}
int main(void)
{
	uint8_t index = 0;
	Init_74595(); // 74595 초기화
	while(1)
	{
		uint16_t pattern = 0x0001 << index; // 출력 패턴 결정
		index = (index + 1) % 16; // 출력 패턴에서의 위치 결정
		WordDataWrite(pattern); // 워드 데이터 출력
		_delay_ms(200);
	}
}
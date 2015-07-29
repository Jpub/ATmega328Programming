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
#define SEGMENT_DELAY 5 // LED가 완전히 켜지기 위한 시간

int main(void)
{
	uint8_t numbers[]
	= {0xFC, 0x60, 0xDA, 0xF2, 0x66, 0xB6, 0xBE, 0xE4, 0xFE, 0xE6};
	int count = 1000; // 현재 표시할 숫자(0~9)
	int thousands, hundreds, tens, ones;
	DDRD = 0xFF; // 세그먼트 제어 핀 8개를 출력으로 설정
	DDRB = 0x0F; // 자릿수 선택 핀 4개를 출력으로 설정
	while(1)
	{
		thousands = count / 1000; // 천의 자리
		hundreds = count / 100 % 10; // 백의 자리
		tens = count / 10 % 10; // 십의 자리
		ones = count % 10; // 일의 자리
		PORTB = 0x0E; // 천의 자리 출력
		PORTD = numbers[thousands];
		_delay_ms(SEGMENT_DELAY);
		PORTB = 0x0D; // 백의 자리 출력
		PORTD = numbers[hundreds];
		_delay_ms(SEGMENT_DELAY);
		PORTB = 0x0B; // 십의 자리 출력
		PORTD = numbers[tens];
		_delay_ms(SEGMENT_DELAY);
		PORTB = 0x07; // 일의 자리 출력
		PORTD = numbers[ones];
		_delay_ms(SEGMENT_DELAY);
		_delay_ms(100); // 0.1초 대기
		count++;
		if(count == 10000) count = 1000; // 1000~9999까지 반복
	}
	return 1;
}
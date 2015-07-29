/*
 *  아트멜 스튜디오와 아두이노로 배우는 ATmega328 프로그래밍
 *
 * 		Gyeongyong Heo (hgycap@deu.ac.kr)
 *			Department of Electronic Engineering
 *			Dong-eui University
 *  	2015. 07. 14
 */ 

#define F_CPU 16000000

#include <avr/io.h>
#include <util/delay.h>
#include "TEXT_LCD.h"

// 모드 설정을 위해 전역 변수로 선언해주어야 한다.
// 4 : 4비트 모드, 8 : 8비트 모드
uint8_t MODE = 8;

int main(void)
{
	LCD_init();					// 텍스트 LCD 초기화
	
	LCD_write_string("Hello World!");	// 문자열 출력
	
	_delay_ms(1000);			// 1초 대기
	
	LCD_clear();				// 화면 지움
	
	// 화면에 보이는 영역은 기본값으로 0~1행, 0~15열로 설정되어 있다.
	LCD_goto_XY(0, 0);			// 0행 0열로 이동
	LCD_write_data('1');			// 문자 단위 출력
	LCD_goto_XY(0, 5);
	LCD_write_data('2');
	LCD_goto_XY(1, 0);
	LCD_write_data('3');
	LCD_goto_XY(1, 5);
	LCD_write_data('4');
	
	while(1);
}
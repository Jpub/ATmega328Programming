/*
 *  아트멜 스튜디오와 아두이노로 배우는 ATmega328 프로그래밍
 *
 * 		Gyeongyong Heo (hgycap@deu.ac.kr)
 *			Department of Electronic Engineering
 *			Dong-eui University
 *  	2015. 07. 14
 */ 

#include <LiquidCrystal.h>
// 핀 번호(RS, E, DB4, DB5, DB6, DB7)
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
void setup(){
	lcd.begin(16, 2); // LCD 초기화
	lcd.print("Hello World!"); // 문자열 출력
	delay(1000); // 1초 대기
	lcd.clear(); // 화면 지움
	lcd.setCursor(0, 0); // 0행 0열로 이동
	lcd.write('1'); // 문자 단위 출력
	lcd.setCursor(5, 0);
	lcd.write('2');
	lcd.setCursor(0, 1);
	lcd.write('3');
	lcd.setCursor(5, 1);
	lcd.write('3');
}
void loop(){
}
/*
 *  아트멜 스튜디오와 아두이노로 배우는 ATmega328 프로그래밍
 *
 * 		Gyeongyong Heo (hgycap@deu.ac.kr)
 *			Department of Electronic Engineering
 *			Dong-eui University
 *  	2015. 07. 14
 */ 

#include <avr/wdt.h>
int count = 0;
void setup(){
	wdt_enable(WDTO_8S); // 워치독 타이머 만료 시간을 8초로 설정
	Serial.begin(9600); // 시리얼 통신 초기화
	Serial.println("** setup function **");
}
void loop(){
	delay(1000);
	count++;
	Serial.println(String("Count : ") + count); // 1초에 한 번 카운트 출력
	wdt_reset(); // 워치독 타이머 리셋
}
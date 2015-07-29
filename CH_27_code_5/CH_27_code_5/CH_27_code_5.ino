/*
 *  아트멜 스튜디오와 아두이노로 배우는 ATmega328 프로그래밍
 *
 * 		Gyeongyong Heo (hgycap@deu.ac.kr)
 *			Department of Electronic Engineering
 *			Dong-eui University
 *  	2015. 07. 14
 */ 

#include <EEPROM.h>
void setup(){
	Serial.begin(9600); // 시리얼 통신 초기화
}
void loop(){
	for(int i = 0; i <= 10; i++){ // EEPROM에 값 쓰기
		EEPROM.write(i, i); // write(주소, 값)
	}
	for(int i = 0; i <= 10; i++){ // EEPROM에서 값 읽기
		int value = EEPROM.read(i); // read(주소)
		Serial.println("Address : " + String(i) + "\t Value : " + value);
		delay(500);
	}
	while(true);
}

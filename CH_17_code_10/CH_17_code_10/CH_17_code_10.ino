/*
 *  아트멜 스튜디오와 아두이노로 배우는 ATmega328 프로그래밍
 *
 * 		Gyeongyong Heo (hgycap@deu.ac.kr)
 *			Department of Electronic Engineering
 *			Dong-eui University
 *  	2015. 07. 14
 */ 

#include <Wire.h> // I2C 라이브러리
#include "RTClib.h" // RTClib 라이브러리
RTC_DS1307 RTC; // RTC 객체
void setup () {
	Serial.begin(9600); // 시리얼 통신 초기화
	Wire.begin(); // Wire 라이브러리 초기화
	RTC.begin(); // RTC 초기화
}
void loop () {
	RTC.adjust(DateTime(2014, 9, 1, 12, 34, 56)); // 시작 시간 설정
	delay(2000);
	DateTime now = RTC.now(); // 현재 시간 얻기
	Serial.println("* Time/Date Retrieval...");
	Serial.println(String(now.second()) + " second");
	Serial.println(String(now.minute()) + " minute");
	Serial.println(String(now.hour()) + " hour");
	Serial.println(String(now.day()) + " day");
	Serial.println(String(now.month()) + " month");
	Serial.println(String(now.year()) + " year");
	while(true);
}
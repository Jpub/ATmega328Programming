/*
 *  아트멜 스튜디오와 아두이노로 배우는 ATmega328 프로그래밍
 *
 * 		Gyeongyong Heo (hgycap@deu.ac.kr)
 *			Department of Electronic Engineering
 *			Dong-eui University
 *  	2015. 07. 14
 */ 

#include <Wire.h>
#define RTC_ADDRESS 0x68 // RTC 모듈의 I2C 주소
uint8_t bcd_to_decimal(uint8_t bcd){ // BCD 형식 -> 이진수 형식
	return (bcd >> 4) * 10 + (bcd & 0x0F);
}
uint8_t decimal_to_bcd(uint8_t decimal){ // 이진수 형식 -> BCD 형식
	return ( ((decimal / 10) << 4) | (decimal % 10) );
}
void setup(){
	Serial.begin(9600); // UART 통신 초기화
	Wire.begin(); // I2C 초기화
}
void loop(){
	// 2014년 9월 1일 12시 34분 56초 월요일로 초기화
	timeSetting(14, 9, 1, 12, 34, 56, 2);
	delay(2000); // 시간 설정 후 2초 대기
	timePrint(); // 현재 시간 출력
	while(true);
}
void timeSetting(int _year, int _month, int _day,
int _hour, int _min, int _sec, int _day_of_week){
	Wire.beginTransmission(RTC_ADDRESS); // I2C 시작
	Wire.write(0); // RTC에 데이터를 기록할 메모리 시작 주소 전송
	Wire.write(decimal_to_bcd(_sec)); // 초 설정
	Wire.write(decimal_to_bcd(_min)); // 분 설정
	Wire.write(decimal_to_bcd(_hour)); // 시 설정
	Wire.write(decimal_to_bcd(_day_of_week)); // 요일 설정
	Wire.write(decimal_to_bcd(_day)); // 일 설정
	Wire.write(decimal_to_bcd(_month)); // 월 설정
	Wire.write(decimal_to_bcd(_year)); // 년 설정
	Wire.endTransmission(); // I2C 종료
}
void timePrint(void){
	Wire.beginTransmission(RTC_ADDRESS);
	Wire.write(0); // RTC에서 데이터를 읽어 올 메모리 시작 주소 전송
	Wire.endTransmission();
	Wire.requestFrom(RTC_ADDRESS, 7); // 7 바이트 시간 정보 요청
	uint8_t _second = bcd_to_decimal(Wire.read()); // 초
	uint8_t _minute = bcd_to_decimal(Wire.read()); // 분
	uint8_t _hour = bcd_to_decimal(Wire.read()); // 시
	uint8_t _day_of_week = bcd_to_decimal(Wire.read()); // 요일
	uint8_t _day = bcd_to_decimal(Wire.read()); // 일
	uint8_t _month = bcd_to_decimal(Wire.read()); // 월
	uint8_t _year = bcd_to_decimal(Wire.read()); // 년
	Serial.println("* Time/Date Retrieval...");
	Serial.println(String(_second) + " second");
	Serial.println(String(_minute) + " minute");
	Serial.println(String(_hour) + " hour");
	Serial.println(String(_day_of_week) + " day of week");
	Serial.println(String(_day) + " day");
	Serial.println(String(_month) + " month");
	Serial.println(String(_year) + " year");
}
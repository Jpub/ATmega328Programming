/*
 *  아트멜 스튜디오와 아두이노로 배우는 ATmega328 프로그래밍
 *
 * 		Gyeongyong Heo (hgycap@deu.ac.kr)
 *			Department of Electronic Engineering
 *			Dong-eui University
 *  	2015. 07. 14
 */ 

#include <SPI.h>
#include <SPIEEP.h>

// 주소 비트 수, 페이지 크기, 전체 메모리 바이트 수
SPIEEP eeprom(8, 16, 128);		// 객체 생성

void setup(){
	Serial.begin(9600);			// 직렬 통신 초기화
	eeprom.begin_spi(10);			// SPI 통신 객체 초기화. SS 핀 번호 지정
}

void loop(){
	for(int i = 0; i < 128; i++)		// 바이트 단위 데이터 쓰기
	eeprom.write((uint32_t)i, (char)i);
	for(int i = 0; i < 128; i++)		// 바이트 단위 데이터 읽기
	Serial.println(eeprom.read((uint32_t)i));

	while(true);
}
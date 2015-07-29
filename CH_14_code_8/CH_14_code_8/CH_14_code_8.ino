/*
 *  아트멜 스튜디오와 아두이노로 배우는 ATmega328 프로그래밍
 *
 * 		Gyeongyong Heo (hgycap@deu.ac.kr)
 *			Department of Electronic Engineering
 *			Dong-eui University
 *  	2015. 07. 14
 */ 

#include <MsTimer2.h>

int count = 0;

void countingFunction(){ // 인터럽트 처리 함수
	Serial.println(count++);
}

void setup(){
	Serial.begin(9600);
	// 1초마다 countingFunction 함수가 호출되도록 설정
	MsTimer2::set(1000, countingFunction);
	MsTimer2::start(); // 인터럽트 활성화
}

void loop(){ }
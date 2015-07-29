/*
 *  아트멜 스튜디오와 아두이노로 배우는 ATmega328 프로그래밍
 *
 * 		Gyeongyong Heo (hgycap@deu.ac.kr)
 *			Department of Electronic Engineering
 *			Dong-eui University
 *  	2015. 07. 14
 */ 

#include <Servo.h>			// 서보 라이브러리
#define ROTATION_DELAY 	1000	// 1초 대기

Servo microServo;			// 서보 모터를 위한 객체
int servoPin = 9;				// 서보 연결 핀

void setup(){
	microServo.attach(servoPin); 		// 서보 모터 연결
}

void loop(){
	microServo.write(0);			// 모터 위치 제어. 0도
	delay(ROTATION_DELAY);
	microServo.write(90);			// 모터 위치 제어. 90도
	delay(ROTATION_DELAY);
	microServo.write(180);			// 모터 위치 제어. 180도
	delay(ROTATION_DELAY);
}
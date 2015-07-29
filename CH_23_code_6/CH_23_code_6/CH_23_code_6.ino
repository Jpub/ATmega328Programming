/*
 *  아트멜 스튜디오와 아두이노로 배우는 ATmega328 프로그래밍
 *
 * 		Gyeongyong Heo (hgycap@deu.ac.kr)
 *			Department of Electronic Engineering
 *			Dong-eui University
 *  	2015. 07. 14
 */ 

#include <Servo.h> // Servo 라이브러리
#define ROTATION_DELAY 10 // 10밀리초 대기
Servo microServo; // 서보 모터를 위한 객체
int servoPin = 9; // 서보 연결 핀
void setup(){
	microServo.attach(servoPin); // 서보 모터 연결
}
void loop(){
	int analogValue = analogRead(A0); // 가변저항 읽기
	// 가변저항 값을 각도로 변환
	int angle = map(analogValue, 0, 1023, 0, 180);
	microServo.write(angle); // 모터 위치 제어
	delay(ROTATION_DELAY);
}
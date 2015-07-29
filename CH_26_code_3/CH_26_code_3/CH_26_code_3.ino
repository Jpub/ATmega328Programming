/*
 *  아트멜 스튜디오와 아두이노로 배우는 ATmega328 프로그래밍
 *
 * 		Gyeongyong Heo (hgycap@deu.ac.kr)
 *			Department of Electronic Engineering
 *			Dong-eui University
 *  	2015. 07. 14
 */ 

#include <SoftwareSerial.h>
// SoftwareSerial(RX, TX) 형식으로 블루투스 모듈과 교차하여 연결된다.
// 2 -> TX of Bluetooth Module
// 3 -> RX of Bluetooth Module
SoftwareSerial BTSerial(2, 3);
void setup()
{
	Serial.begin(9600); // 컴퓨터와의 시리얼 통신 초기화
	BTSerial.begin(9600); // 블루투스 모듈 초기화
}
void loop()
{
	// 블루투스 모듈 --> 아두이노 --> 컴퓨터
	if (BTSerial.available())
	Serial.write(BTSerial.read());
	// 컴퓨터 --> 아두이노 --> 블루투스 모듈
	if (Serial.available())
	BTSerial.write(Serial.read());
}
/*
 *  아트멜 스튜디오와 아두이노로 배우는 ATmega328 프로그래밍
 *
 * 		Gyeongyong Heo (hgycap@deu.ac.kr)
 *			Department of Electronic Engineering
 *			Dong-eui University
 *  	2015. 07. 14
 */ 

void setup()
{
	pinMode(13, OUTPUT);		// 13번 핀을 출력 모드로 설정
}

void loop()
{
	digitalWrite(13, HIGH);		// LED 켜기
	delay(500);
	digitalWrite(13, LOW);		// LED 끄기
	delay(500);
}
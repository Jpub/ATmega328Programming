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
	Serial.begin(9600);
}

void loop()
{
	// 정수
	Serial.println(78, BIN);
	Serial.println(78, OCT);
	Serial.println(78, DEC);
	Serial.println(78, HEX);
	
	// 실수
	Serial.println(1.23456, 0);
	Serial.println(1.23456, 2);
	Serial.println(1.23456, 4);
	
	// 문자
	Serial.print('C');
	Serial.print('\n');
	
	// 문자열
	Serial.println("Serial Class Test...");
	
	while(true);
}
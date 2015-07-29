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
	Serial.begin(9600);			// UART 통신 초기화
}

void loop()
{
	int read = analogRead(A0);		// 아날로그 값 읽기
	Serial.println(read);			// 아날로그 값을 시리얼 모니터로 출력

	delay(1000);				// 1초 대기
}
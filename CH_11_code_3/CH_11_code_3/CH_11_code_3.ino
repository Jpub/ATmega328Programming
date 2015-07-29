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
	pinMode(2, INPUT_PULLUP);		// 내부 풀업 저항을 사용하는 버튼 입력

	pinMode(13, OUTPUT);			// 13번 핀을 출력으로 설정
	digitalWrite(13, LOW);			// LED는 꺼진 상태로 시작
}

void loop()
{
	if(digitalRead(2)) digitalWrite(13, LOW);	// LED 끄기
	else digitalWrite(13, HIGH);		// LED 켜기
}
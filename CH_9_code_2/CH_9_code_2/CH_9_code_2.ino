/*
 *  아트멜 스튜디오와 아두이노로 배우는 ATmega328 프로그래밍
 *
 * 		Gyeongyong Heo (hgycap@deu.ac.kr)
 *			Department of Electronic Engineering
 *			Dong-eui University
 *  	2015. 07. 14
 */ 

int pins[] = {0, 1, 2, 3, 4, 5, 6, 7}; // 포트 D의 아두이노 핀 번호
void setup()
{
	for(int i = 0; i < 8; i++){ // 포트 D의 핀들을 출력으로 설정
		pinMode(pins[i], OUTPUT);
	}
}
void loop()
{
	for(int i = 0; i < 8; i++){ // 홀수 번째 LED 켜기
		if(i % 2 == 0) digitalWrite(pins[i], HIGH);
		else digitalWrite(pins[i], LOW);
	}
	delay(1000);
	for(int i = 0; i < 8; i++){ // 짝수 번째 LED 켜기
		if(i % 2 == 0) digitalWrite(pins[i], LOW);
		else digitalWrite(pins[i], HIGH);
	}
	delay(1000);
}
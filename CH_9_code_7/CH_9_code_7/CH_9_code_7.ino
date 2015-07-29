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
	for(int i = 0; i < 8; i++){ // 8개 패턴
		for(int j = 0; j < 8; j++){ // 패턴별 8개 LED
			if(j == i || j == (7 - i)) // 패턴당 2개의 LED만 켜고
			digitalWrite(pins[j], HIGH);
			else // 나머지 6개는 끔
			digitalWrite(pins[j], LOW);
		}
		delay(1000);
	}
}
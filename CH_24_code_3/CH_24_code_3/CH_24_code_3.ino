/*
 *  아트멜 스튜디오와 아두이노로 배우는 ATmega328 프로그래밍
 *
 * 		Gyeongyong Heo (hgycap@deu.ac.kr)
 *			Department of Electronic Engineering
 *			Dong-eui University
 *  	2015. 07. 14
 */ 

int dataPin = 11;
int latchClockPin = 12;
int shiftClockPin = 13;
int index = 0;
void setup() {
	pinMode(dataPin, OUTPUT);
	pinMode(shiftClockPin, OUTPUT);
	pinMode(latchClockPin, OUTPUT);
}
void loop() {
	byte pattern = 1 << index;
	index = (index + 1) % 8;
	shiftOut(dataPin, shiftClockPin, MSBFIRST, pattern); // 데이터 출력
	digitalWrite(latchClockPin, HIGH); // 래치 출력
	digitalWrite(latchClockPin, LOW);
	delay(200);
}
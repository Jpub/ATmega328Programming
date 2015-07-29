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
	int pattern = 1 << index;
	index = (index + 1) % 16;
	// 상위 8비트 데이터 출력
	shiftOut(dataPin, shiftClockPin, MSBFIRST, (byte)(pattern >> 8));
	// 하위 8비트 데이터 출력
	shiftOut(dataPin, shiftClockPin, MSBFIRST, (byte)(pattern & 0xFF));
	digitalWrite(latchClockPin, HIGH); // 래치 출력
	digitalWrite(latchClockPin, LOW);
	delay(200);
}
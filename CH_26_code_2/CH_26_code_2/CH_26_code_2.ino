/*
 *  아트멜 스튜디오와 아두이노로 배우는 ATmega328 프로그래밍
 *
 * 		Gyeongyong Heo (hgycap@deu.ac.kr)
 *			Department of Electronic Engineering
 *			Dong-eui University
 *  	2015. 07. 14
 */ 

void setup() {
	Serial.begin(9600); // UART 시리얼 통신 초기화
}
void loop() {
	if(Serial.available()){ // 수신 데이터 확인
		byte data = Serial.read(); // 데이터 수신
		Serial.write(data); // 수신된 문자 재전송
	}
}
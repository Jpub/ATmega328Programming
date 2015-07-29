/*
 *  아트멜 스튜디오와 아두이노로 배우는 ATmega328 프로그래밍
 *
 * 		Gyeongyong Heo (hgycap@deu.ac.kr)
 *			Department of Electronic Engineering
 *			Dong-eui University
 *  	2015. 07. 14
 */ 

int LED_pin = 11; // LED 연결 핀
void setup()
{
	pinMode(LED_pin, OUTPUT); // LED 연결 핀을 출력으로 설정
	analogWrite(LED_pin, 0); // LED는 끈 상태에서 시작
}
void loop()
{
	for(int i = 0; i < 256; i++){ // 점차 밝아짐
		analogWrite(LED_pin, i);
		delay(10);
	}
	for(int i = 255; i >= 0; i--){ // 점차 어두워짐
		analogWrite(LED_pin, i);
		delay(10);
	}
}
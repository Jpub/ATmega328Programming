/*
 *  아트멜 스튜디오와 아두이노로 배우는 ATmega328 프로그래밍
 *
 * 		Gyeongyong Heo (hgycap@deu.ac.kr)
 *			Department of Electronic Engineering
 *			Dong-eui University
 *  	2015. 07. 14
 */ 

int temp_pin = A1;
int input_value;
float input_voltage;
float temperature;
void setup() {
	Serial.begin(9600); // 시리얼 통신 초기화
}
void loop() {
	input_value = analogRead(temp_pin);
	// 0에서 1023 사이의 값을 0V에서 5V 사이 값으로 변환한다.
	input_voltage = 5.0 * input_value / 1023.0;
	// 10mV에 1℃이므로 100을 곱해서 현재 온도를 얻는다.
	temperature = input_voltage * 100.0;
	Serial.println(temperature);
	delay(1000);
}
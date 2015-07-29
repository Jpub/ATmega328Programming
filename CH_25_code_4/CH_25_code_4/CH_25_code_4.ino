/*
 *  아트멜 스튜디오와 아두이노로 배우는 ATmega328 프로그래밍
 *
 * 		Gyeongyong Heo (hgycap@deu.ac.kr)
 *			Department of Electronic Engineering
 *			Dong-eui University
 *  	2015. 07. 14
 */ 

int distance;
int triggerPin = A0;
int echoPin = A1;
void setup() {
	Serial.begin(9600); // UART 통신 초기화
	pinMode(triggerPin, OUTPUT); // 트리거 핀 출력으로 설정
	pinMode(echoPin, INPUT); // 에코 핀 입력으로 설정
}
void loop()
{
	// 트리거 핀으로 펄스 출력
	digitalWrite(triggerPin, HIGH);
	delayMicroseconds(10); // 10마이크로초 대기
	digitalWrite(triggerPin, LOW);
	// 에코 핀 입력 펄스의 길이로 센티미터 단위 거리 계산
	distance = pulseIn(echoPin, HIGH) / 58;
	Serial.println("Distance(cm) = " + String(distance));
	delay(1000);
}
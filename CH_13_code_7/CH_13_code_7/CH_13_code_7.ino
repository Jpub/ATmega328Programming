/*
 *  아트멜 스튜디오와 아두이노로 배우는 ATmega328 프로그래밍
 *
 * 		Gyeongyong Heo (hgycap@deu.ac.kr)
 *			Department of Electronic Engineering
 *			Dong-eui University
 *  	2015. 07. 14
 */ 

void blinkLED() // INT0 인터럽트 처리 함수
{
	// 풀업 저항을 사용하였으므로 버튼 상태와 반전된 값을 출력한다.
	digitalWrite(13, !digitalRead(2));
}
void setup()
{
	pinMode(13, OUTPUT); // 13번 핀을 출력으로 설정
	digitalWrite(13, LOW); // 꺼진 상태에서 시작
	// INT0 인터럽트 처리 함수와 인터럽트 발생 시점 설정
	// 버튼을 누르거나 떼는 경우에 인터럽트 발생
	attachInterrupt(0, blinkLED, CHANGE);
	pinMode(2, INPUT); // 버튼 연결 핀을 입력으로 설정
	digitalWrite(2, HIGH); // 풀업 저항 사용
}
void loop()
{
	// 이벤트 루프에서는 아무런 작업도 하지 않는다.
}
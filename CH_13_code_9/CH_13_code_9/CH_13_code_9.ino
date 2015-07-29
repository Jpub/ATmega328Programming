/*
 *  아트멜 스튜디오와 아두이노로 배우는 ATmega328 프로그래밍
 *
 * 		Gyeongyong Heo (hgycap@deu.ac.kr)
 *			Department of Electronic Engineering
 *			Dong-eui University
 *  	2015. 07. 14
 */ 

ISR(PCINT2_vect)
{
	if(PIND & 0x04) PORTB = 0x00; // LED 끄기
	else PORTB = 0x20; // LED 켜기
}
void setup()
{
	pinMode(13, OUTPUT); // 13번 핀을 출력으로 설정
	digitalWrite(13, LOW); // 꺼진 상태에서 시작
	pinMode(2, INPUT); // 버튼 연결 핀을 입력으로 설정
	digitalWrite(2, HIGH); // 풀업 저항 사용
	PCICR |= (1 << PCIE2); // PCINT2 인터럽트 활성화
	PCMSK2 |= (1 << PCINT18); // PD2 핀의 핀 변화 인터럽트 허용
}
void loop()
{
	// 이벤트 루프에서는 아무런 작업도 하지 않는다.
}
/*
 *  아트멜 스튜디오와 아두이노로 배우는 ATmega328 프로그래밍
 *
 * 		Gyeongyong Heo (hgycap@deu.ac.kr)
 *			Department of Electronic Engineering
 *			Dong-eui University
 *  	2015. 07. 14
 */ 

int state = 0; // 현재 버튼의 상태
void setup()
{
	pinMode(2, INPUT_PULLUP); // 내부 풀업 저항을 사용하는 버튼 입력
	pinMode(13, OUTPUT); // 13번 핀을 출력으로 설정
	Serial.begin(9600); // UART 통신 초기화
}
unsigned char button_pressed()
{
	if(!digitalRead(2)){ // 첫 번째 검사
		delay(10);
		if(!digitalRead(2)) return 1; // 두 번째 검사
	}
	return 0;
}
void loop()
{
	if(button_pressed()) { // 버튼이 눌러진 경우
		if(state == 0) Serial.write('*');
		state = 1;
		digitalWrite(13, HIGH);
	}
	else{ // 버튼이 눌러지지 않은 경우
		state = 0;
		digitalWrite(13, LOW);
	}
}
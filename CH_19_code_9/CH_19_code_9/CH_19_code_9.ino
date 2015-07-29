/*
 *  아트멜 스튜디오와 아두이노로 배우는 ATmega328 프로그래밍
 *
 * 		Gyeongyong Heo (hgycap@deu.ac.kr)
 *			Department of Electronic Engineering
 *			Dong-eui University
 *  	2015. 07. 14
 */ 

#define SEGMENT_DELAY 5
// 세그먼트 연결 핀 ‘dp → g → f → e → d → c → b → a’ 순서
int segment_pins[] = {0, 1, 2, 3, 4, 5, 6, 7};
int digit_pins[] = {8, 9, 10, 11}; // 자릿수 선택 핀
uint8_t numbers[]
= {0xFC, 0x60, 0xDA, 0xF2, 0x66, 0xB6, 0xBE, 0xE4, 0xFE, 0xE6};
unsigned long time_previous, time_current;
int count = 1000;
void setup(){
	for(int i = 0; i < 8; i++) // 세그먼트 제어 핀을 출력으로 설정
	pinMode(segment_pins[i], OUTPUT);
	for(int i = 0; i < 4; i++) // 자릿수 선택 핀을 출력으로 설정
	pinMode(digit_pins[i], OUTPUT);
	time_previous = millis(); // 시작 시간
}
void loop(){
	int thousands, hundreds, tens, ones;
	thousands = count / 1000; // 천의 자리
	hundreds = count / 100 % 10; // 백의 자리
	tens = count / 10 % 10; // 십의 자리
	ones = count % 10; // 일의 자리
	show_digit(1, thousands);
	show_digit(2, hundreds);
	show_digit(3, tens);
	show_digit(4, ones);
	time_current = millis(); // 현재 시간
	if(time_current - time_previous > 100){
		time_previous = time_current;
		count++;
		if(count == 10000) count = 1000; // 1000 ~ 9999까지 반복
	}
}
// 지정한 위치 position(1~4)에 지정한 숫자 number(0~9) 출력
void show_digit(int position, int number){
	for(int i = 0; i < 4; i++){
		if(i + 1 == position) digitalWrite(digit_pins[i], LOW);
		else digitalWrite(digit_pins[i], HIGH);
	}
	for(int i = 0; i < 8; i++){
		boolean on_off = bitRead(numbers[number], i); // 비트 값 읽기
		digitalWrite(segment_pins[i], on_off); // 세그먼트 제어
	}
	delay(SEGMENT_DELAY);
}
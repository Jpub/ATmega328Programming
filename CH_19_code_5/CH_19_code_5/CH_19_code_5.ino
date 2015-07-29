/*
 *  아트멜 스튜디오와 아두이노로 배우는 ATmega328 프로그래밍
 *
 * 		Gyeongyong Heo (hgycap@deu.ac.kr)
 *			Department of Electronic Engineering
 *			Dong-eui University
 *  	2015. 07. 14
 */ 

// 세그먼트 연결 핀 ‘dp → g → f → e → d → c → b → a’ 순서
int segment_pins[] = {0, 1, 2, 3, 4, 5, 6, 7};
uint8_t numbers[]
= {0xFC, 0x60, 0xDA, 0xF2, 0x66, 0xB6, 0xBE, 0xE4, 0xFE, 0xE6};
unsigned long time_previous, time_current;
int count = 0;
void setup() {
	for(int i = 0; i < 8; i++) // 세그먼트 제어 핀을 출력으로 설정
	pinMode(segment_pins[i], OUTPUT);
	time_previous = millis(); // 시작 시간
}
void loop() {
	time_current = millis(); // 현재 시간
	if(time_current - time_previous > 1000){
		time_previous = time_current;
		for(int i = 0; i < 8; i++){
			boolean on_off = bitRead(numbers[count], i); // 비트 값 읽기
			digitalWrite(segment_pins[i], on_off); // 세그먼트 제어
		}
		count = (count + 1) % 10; // 표시할 숫자
	}
}
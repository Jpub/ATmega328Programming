/*
 *  아트멜 스튜디오와 아두이노로 배우는 ATmega328 프로그래밍
 *
 * 		Gyeongyong Heo (hgycap@deu.ac.kr)
 *			Department of Electronic Engineering
 *			Dong-eui University
 *  	2015. 07. 14
 */ 

int rows[] = {2, 3, 4, 5, 6, 7, 8, 9}; // 행 연결 핀
int cols[] = {10, 11, 12, 13, A0, A1, A2, A3}; // 열 연결 핀
byte smile[] = {
	0b00111100,
	0b01000010,
	0b10101001,
	0b10000101,
	0b10000101,
	0b10101001,
	0b01000010,
0b00111100 };
void setup(){
	for(int i = 0; i < 8; i++){ // 해당 핀을 출력으로 설정
		pinMode(rows[i], OUTPUT);
		pinMode(cols[i], OUTPUT);
	}
}
void loop(){
	for(int i = 0; i < 8; i++){
		// 이웃한 열로의 번짐 방지
		for(int j = 0; j < 8; j++)
		digitalWrite(rows[j], LOW);
		// 열 단위 스캔이므로 하나의 열에만 LOW를 가하고 나머지는 HIGH를 가함
		byte col_data = ~(1 << i);
		for(int j = 0; j < 8; j++)
		digitalWrite(cols[j], (col_data >> j) & 0x01);
		// 각 열에 대응하는 스마일 문자 데이터를 출력
		for(int j = 0; j < 8; j++)
		digitalWrite(rows[j], (smile[i] >> (7 - j)) & 0x01);
		delay(2);
	}
}
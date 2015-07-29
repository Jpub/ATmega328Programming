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
void setup(){
	for(int i = 0; i < 8; i++){ // 해당 핀을 출력으로 설정
		pinMode(rows[i], OUTPUT);
		pinMode(cols[i], OUTPUT);
	}
}
void loop(){
	for(int i = 0; i < 8; i++){
		// 열 단위 스캔이므로 하나의 열에만 LOW를 가하고 나머지는 HIGH를 가함
		byte col_data = ~(1 << i);
		for(int k = 0; k < 8; k++)
		digitalWrite(cols[k], (col_data >> k) & 0x01);
		for(int j = 0; j < 8; j++){
			// 하나의 열에서 켜고 싶은 위치의 LED에 HIGH를
			// 끄고 싶은 위치의 LED에 LOW를 가함
			byte row_data = 1 << (7 - j);
			for(int k = 0; k < 8; k++)
			digitalWrite(rows[k], (row_data >> (7 - k)) & 0x01);
			delay(100);
		}
	}
}
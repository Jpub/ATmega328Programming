/*
 *  아트멜 스튜디오와 아두이노로 배우는 ATmega328 프로그래밍
 *
 * 		Gyeongyong Heo (hgycap@deu.ac.kr)
 *			Department of Electronic Engineering
 *			Dong-eui University
 *  	2015. 07. 14
 */ 

const byte ROWS = 2;
const byte COLS = 2;
char keys[ROWS][COLS] = { // 키 값 정의
	{'1', '2'},
	{'3', '4'}
};
byte rowPins[ROWS] = {2, 3}; // 행 연결 핀
byte colPins[COLS] = {6, 7}; // 열 연결 핀
byte pattern[ROWS][COLS]; // 키 상태 저장
void setup(){
	// 행 연결 핀을 입력으로 설정
	for(int i = 0; i < ROWS; i++)
	pinMode(rowPins[i], INPUT);
	// 열 연결 핀을 출력으로 설정
	for(int i = 0; i < COLS; i++){
		pinMode(colPins[i], OUTPUT);
		digitalWrite(colPins[i], HIGH);
	}
	Serial.begin(9600); // 시리얼 통신 초기화
}
void loop(){
	int row, col, count = 0;
	for(col = 0; col < COLS; col++){
		digitalWrite(colPins[col], LOW); // 해당 COL에 LOW 출력
		for(row = 0; row < ROWS; row++){ // LOW의 입력 읽기
			pattern[row][col] = !digitalRead(rowPins[row]);
			count += pattern[row][col];
		}
		digitalWrite(colPins[col], HIGH); // 해당 COL에 HIGH 출력
	}
	if(count > 0){ // 버튼이 눌러진 경우만 시리얼로 출력
		for(row = 0; row < ROWS; row++){
			for(col = 0; col < COLS; col++){
				if(pattern[row][col])
				Serial.write(keys[row][col]);
				else
				Serial.write('.');
				Serial.write(" ");
			}
			Serial.write('\n');
		}
		Serial.write('\n');
	}
	delay(1000);
}
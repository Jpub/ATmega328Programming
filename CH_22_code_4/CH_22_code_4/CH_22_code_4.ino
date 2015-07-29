/*
 *  아트멜 스튜디오와 아두이노로 배우는 ATmega328 프로그래밍
 *
 * 		Gyeongyong Heo (hgycap@deu.ac.kr)
 *			Department of Electronic Engineering
 *			Dong-eui University
 *  	2015. 07. 14
 */ 

#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
	{'1', '2', '3', 'A'},
	{'4', '5', '6', 'B'},
	{'7', '8', '9', 'C'},
	{'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

// 키패드 객체 생성 및 초기화
// 키패드의 크기, 연결 핀 그리고 키 값을 지정
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup(){
	Serial.begin(9600);			// 직렬 통신 초기화
}

void loop(){
	if(keypad.getKeys()){			// 키패드의 상태가 변한 경우
		for(int i = 0; i < LIST_MAX; i++){
			if(keypad.key[i].stateChanged){	// 개별 키의 상태가 변한 경우
				Serial.print(keypad.key[i].kchar + String(" : "));	// 키 값 출력
				switch(keypad.key[i].kstate){	// 4가지 상태 변화
					case PRESSED:
					Serial.println("Pressed...");
					break;
					case HOLD:
					Serial.println("Hold...");
					break;
					case RELEASED:
					Serial.println("Released...");
					break;
					case IDLE:
					Serial.println("Idle...");
					break;
				}
			}
		}
	}
	delay(1000);
}

/*
 *  아트멜 스튜디오와 아두이노로 배우는 ATmega328 프로그래밍
 *
 * 		Gyeongyong Heo (hgycap@deu.ac.kr)
 *			Department of Electronic Engineering
 *			Dong-eui University
 *  	2015. 07. 14
 */ 

int LED_pins[] = {0, 1, 2, 3, 4, 5, 6, 7};
	
void setup()
{
	for(int i = 0; i < 8; i++){
		pinMode(LED_pins[i], OUTPUT);
		digitalWrite(LED_pins[i], LOW);
	}
}

void loop()
{
	int value = analogRead(A0) >> 7;
	
	for(int i = 0; i <= value; i++){
		digitalWrite(LED_pins[i], HIGH);
	}
	
	for(int i = value + 1; i < 8; i++){
		digitalWrite(LED_pins[i], LOW);
	}
}


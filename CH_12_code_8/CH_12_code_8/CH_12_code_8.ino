/*
 *  아트멜 스튜디오와 아두이노로 배우는 ATmega328 프로그래밍
 *
 * 		Gyeongyong Heo (hgycap@deu.ac.kr)
 *			Department of Electronic Engineering
 *			Dong-eui University
 *  	2015. 07. 14
 */ 

void setup()
{
	Serial.begin(9600);
	//randomSeed(analogRead(A0));
	randomSeed(100);
	Serial.println("** Start generating random number...");
}

void loop()
{
	Serial.println(random(1, 101));
	delay(1000);
}

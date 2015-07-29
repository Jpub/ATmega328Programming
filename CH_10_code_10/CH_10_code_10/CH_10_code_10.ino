/*
 *  아트멜 스튜디오와 아두이노로 배우는 ATmega328 프로그래밍
 *
 * 		Gyeongyong Heo (hgycap@deu.ac.kr)
 *			Department of Electronic Engineering
 *			Dong-eui University
 *  	2015. 07. 14
 */ 

#define TERMINATOR '$'

boolean process_data = false;
int counter = 100;
String buffer = "";

void setup()
{
	Serial.begin(9600);
	
	Serial.print("Current Counter Value : ");
	Serial.println(counter);
}

void loop()
{
	if(Serial.available()){
		char data = Serial.read();
		if(data == TERMINATOR){
			process_data = true;
		}
		else{
			buffer = buffer + data;
		}
	}
	
	if(process_data){
		if(buffer.equals("DOWN")){
			counter--;
			Serial.print("Current Counter Value : ");
			Serial.println(counter);
		}
		else if(buffer.equals("UP")){
			counter++;
			Serial.print("Current Counter Value : ");
			Serial.println(counter);
		}
		else{
			Serial.println("** Unknown Command **");
		}
		process_data = false;
		buffer = "";
	}
}

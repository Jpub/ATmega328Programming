/*
 *  아트멜 스튜디오와 아두이노로 배우는 ATmega328 프로그래밍
 *
 * 		Gyeongyong Heo (hgycap@deu.ac.kr)
 *			Department of Electronic Engineering
 *			Dong-eui University
 *  	2015. 07. 14
 */ 

#include <avr/io.h>
#include <stdio.h>
#include "UART.h" // UART 라이브러리 사용

FILE OUTPUT = FDEV_SETUP_STREAM(UART_transmit, NULL, _FDEV_SETUP_WRITE);
FILE INPUT = FDEV_SETUP_STREAM(NULL, UART_receive, _FDEV_SETUP_READ);

int main(int argc, char *argv[])
{
	unsigned char data;
	stdout = &OUTPUT;
	stdin = &INPUT;
	UART_INIT(); // UART 통신 초기화
	while (1) {
		scanf("%c", &data); // 데이터 수신
		printf("You typed %c", data); // 수신된 문자를 에코 백
	}
	return 0;
}
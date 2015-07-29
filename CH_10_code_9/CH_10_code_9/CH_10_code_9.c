/*
 *  아트멜 스튜디오와 아두이노로 배우는 ATmega328 프로그래밍
 *
 * 		Gyeongyong Heo (hgycap@deu.ac.kr)
 *			Department of Electronic Engineering
 *			Dong-eui University
 *  	2015. 07. 14
 */ 

#define F_CPU 16000000L
#define TERMINATOR '$'

#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include "UART.h"

int main(void)
{
	int counter = 100; 		// 카운터
	int index = 0;			// 수신 버퍼에 저장할 위치
	int process_data = 0;		// 문자열 처리
	char buffer[20] = "";		// 수신 데이터 버퍼
	char data;				// 수신 데이터
	
	UART_INIT();			// UART 통신 초기화
	
	UART_printString("Current Counter Value : ");
	UART_print16bitNumber(counter);
	UART_printString("\n");
	
	while(1)
	{
		data = UART_receive();	// 데이터 수신
		if(data == TERMINATOR){	// 종료 문자를 수신한 경우
			buffer[index] = '\0';
			process_data = 1;		// 수신 문자열 처리 지시
		}
		else{
			buffer[index] = data;	// 수신 버퍼에 저장
			index++;
		}
		
		if(process_data == 1){		// 문자열 처리
			if(strcmp(buffer, "DOWN") == 0){	// 카운터 감소
				counter--;
				UART_printString("Current Counter Value : ");
				UART_print16bitNumber(counter);
				UART_printString("\n");
			}
			else if(strcmp(buffer, "UP") == 0){	// 카운터 증가
				counter++;
				UART_printString("Current Counter Value : ");
				UART_print16bitNumber(counter);
				UART_printString("\n");
			}
			else{					// 잘못된 명령어
				UART_printString("** Unknown Command **");
				UART_printString("\n");
			}
			index = 0;
			process_data = 0;
		}
	}
}
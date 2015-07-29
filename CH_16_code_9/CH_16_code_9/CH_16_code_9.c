/*
 *  아트멜 스튜디오와 아두이노로 배우는 ATmega328 프로그래밍
 *
 * 		Gyeongyong Heo (hgycap@deu.ac.kr)
 *			Department of Electronic Engineering
 *			Dong-eui University
 *  	2015. 07. 14
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <string.h>
#include "UART.h"
#include "25LC010.h"

int main(void) {
	uint8_t i;
	
	SPI_Init();					// SPI 초기화
	UART_INIT();				// UART 초기화

	for(i = 0; i < 128; i++)			// EEPROM에 쓰기
	EEPROM_writeByte(i, i);
	
	for(i = 0; i < 128; i++){			// EEPROM에서 읽기
		UART_print8bitNumber(EEPROM_readByte(i));
		UART_transmit('\n');
	}
	while(1);

	return 0;
}
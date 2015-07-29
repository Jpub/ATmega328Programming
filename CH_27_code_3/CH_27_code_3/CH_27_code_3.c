/*
 *  아트멜 스튜디오와 아두이노로 배우는 ATmega328 프로그래밍
 *
 * 		Gyeongyong Heo (hgycap@deu.ac.kr)
 *			Department of Electronic Engineering
 *			Dong-eui University
 *  	2015. 07. 14
 */ 

#include <avr/io.h>
#include <avr/eeprom.h>
#include "UART.h"
int main(void)
{
	// EEPROM에 쓸 데이터
	uint8_t dataByte = 1;
	uint16_t dataWord = 2;
	uint32_t dataDWord = 3;
	char dataString[] = "ABCDE";
	// EEPROM의 주소
	int addressByte = 0, addressWord = 10, addressDWord = 20, addressString = 30;
	UART_INIT(); // UART 통신 초기화
	// 데이터 쓰기
	eeprom_update_byte ( (uint8_t *)addressByte, dataByte * 10);
	eeprom_update_word ( (uint16_t *)addressWord, dataWord * 10);
	eeprom_update_dword ( (uint32_t *)addressDWord, dataDWord * 10);
	eeprom_update_block ( (void *)dataString, (void *)addressString, 5);
	// 데이터 읽기
	dataByte = eeprom_read_byte ( (uint8_t *)addressByte );
	dataWord = eeprom_read_word ( (uint16_t *)addressWord );
	dataDWord = eeprom_read_dword ( (uint32_t *)addressDWord );
	eeprom_read_block ( (void *)dataString, (void *)addressString, 5);
	// UART 통신으로 데이터 전송
	UART_printString("Byte : "); // 1바이트 데이터
	UART_print8bitNumber(dataByte);
	UART_printString("\n");
	UART_printString("Word : "); // 2바이트 데이터
	UART_print16bitNumber(dataWord);
	UART_printString("\n");
	UART_printString("Double Word : "); // 4바이트 데이터
	UART_print32bitNumber(dataDWord);
	UART_printString("\n");
	UART_printString("String : "); // 문자열 데이터
	UART_printString(dataString);
	UART_printString("\n");
	while(1);
	return 0;
}
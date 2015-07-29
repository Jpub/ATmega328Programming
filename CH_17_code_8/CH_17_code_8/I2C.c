/*
 *  아트멜 스튜디오와 아두이노로 배우는 ATmega328 프로그래밍
 *
 * 		Gyeongyong Heo (hgycap@deu.ac.kr)
 *			Department of Electronic Engineering
 *			Dong-eui University
 *  	2015. 07. 14
 */ 

#include "I2C.h"
void I2C_init(void) {
	DDRC |= (1 << I2C_SCL); // SCL 핀을 출력으로 설정
	DDRC |= (1 << I2C_SDA); // SDA 핀을 출력으로 설정
	TWBR = 32; // I2C 클록 주파수 설정 200KHz
	TWCR = (1 << TWEN) | (1 << TWEA); // I2C 활성화, ACK 허용
}
void I2C_start(void) {
	TWCR = _BV(TWINT) | _BV(TWSTA) | _BV(TWEN) | _BV(TWEA);
	while( !(TWCR & (1 << TWINT)) ); // 시작 완료 대기
}
void I2C_transmit(uint8_t data) {
	TWDR = data;
	TWCR = _BV(TWINT) | _BV(TWEN) | _BV(TWEA);
	while( !(TWCR & (1 << TWINT)) ); // 전송 완료 대기
}
uint8_t I2C_receive(void) {
	TWCR = _BV(TWINT) | _BV(TWEN) | _BV(TWEA);
	while( !(TWCR & (1 << TWINT)) ); // 수신 완료 대기
	return TWDR;
}
void I2C_stop(void) {
	TWCR = _BV(TWINT) | _BV(TWSTO) | _BV(TWEN) | _BV(TWEA);
}
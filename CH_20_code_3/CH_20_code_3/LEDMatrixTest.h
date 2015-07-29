/*
 *  아트멜 스튜디오와 아두이노로 배우는 ATmega328 프로그래밍
 *
 * 		Gyeongyong Heo (hgycap@deu.ac.kr)
 *			Department of Electronic Engineering
 *			Dong-eui University
 *  	2015. 07. 14
 */ 

#ifndef LEDMATRIXTEST_H_
#define LEDMATRIXTEST_H_

// DDR register for row
#define MATRIX_ROW1_DDR		DDRD
#define MATRIX_ROW2_DDR		DDRD
#define MATRIX_ROW3_DDR		DDRD
#define MATRIX_ROW4_DDR		DDRD
#define MATRIX_ROW5_DDR		DDRD
#define MATRIX_ROW6_DDR		DDRD
#define MATRIX_ROW7_DDR		DDRB
#define MATRIX_ROW8_DDR		DDRB

// PORT register for row
#define MATRIX_ROW1_PORT	PORTD
#define MATRIX_ROW2_PORT	PORTD
#define MATRIX_ROW3_PORT	PORTD
#define MATRIX_ROW4_PORT	PORTD
#define MATRIX_ROW5_PORT	PORTD
#define MATRIX_ROW6_PORT	PORTD
#define MATRIX_ROW7_PORT	PORTB
#define MATRIX_ROW8_PORT	PORTB

// pin number for row
#define MATRIX_ROW1_PIN		PD2
#define MATRIX_ROW2_PIN		PD3
#define MATRIX_ROW3_PIN		PD4
#define MATRIX_ROW4_PIN		PD5
#define MATRIX_ROW5_PIN		PD6
#define MATRIX_ROW6_PIN		PD7
#define MATRIX_ROW7_PIN		PB0
#define MATRIX_ROW8_PIN		PB1

// DDR register for column
#define MATRIX_COL1_DDR		DDRB
#define MATRIX_COL2_DDR		DDRB
#define MATRIX_COL3_DDR		DDRB
#define MATRIX_COL4_DDR		DDRB
#define MATRIX_COL5_DDR		DDRC
#define MATRIX_COL6_DDR		DDRC
#define MATRIX_COL7_DDR		DDRC
#define MATRIX_COL8_DDR		DDRC

// PORT register for column
#define MATRIX_COL1_PORT	PORTB
#define MATRIX_COL2_PORT	PORTB
#define MATRIX_COL3_PORT	PORTB
#define MATRIX_COL4_PORT	PORTB
#define MATRIX_COL5_PORT	PORTC
#define MATRIX_COL6_PORT	PORTC
#define MATRIX_COL7_PORT	PORTC
#define MATRIX_COL8_PORT	PORTC

// bit number for column
#define MATRIX_COL1_PIN		PB2
#define MATRIX_COL2_PIN		PB3
#define MATRIX_COL3_PIN		PB4
#define MATRIX_COL4_PIN		PB5
#define MATRIX_COL5_PIN		PC0
#define MATRIX_COL6_PIN		PC1
#define MATRIX_COL7_PIN		PC2
#define MATRIX_COL8_PIN		PC3




#endif /* LEDMATRIXTEST_H_ */
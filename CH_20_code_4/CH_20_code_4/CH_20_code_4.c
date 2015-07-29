/*
 *  아트멜 스튜디오와 아두이노로 배우는 ATmega328 프로그래밍
 *
 * 		Gyeongyong Heo (hgycap@deu.ac.kr)
 *			Department of Electronic Engineering
 *			Dong-eui University
 *  	2015. 07. 14
 */ 

#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>
#include "LEDMatrixTest.h"

void LEDMatrix_init(void)
{
	// 해당 column 핀을 출력으로 설정
	MATRIX_COL1_DDR |= (1 << MATRIX_COL1_PIN);
	MATRIX_COL2_DDR |= (1 << MATRIX_COL2_PIN);
	MATRIX_COL3_DDR |= (1 << MATRIX_COL3_PIN);
	MATRIX_COL4_DDR |= (1 << MATRIX_COL4_PIN);
	MATRIX_COL5_DDR |= (1 << MATRIX_COL5_PIN);
	MATRIX_COL6_DDR |= (1 << MATRIX_COL6_PIN);
	MATRIX_COL7_DDR |= (1 << MATRIX_COL7_PIN);
	MATRIX_COL8_DDR |= (1 << MATRIX_COL8_PIN);
	
	// 해당 row 핀을 출력으로 설정
	MATRIX_ROW1_DDR |= (1 << MATRIX_ROW1_PIN);
	MATRIX_ROW2_DDR |= (1 << MATRIX_ROW2_PIN);
	MATRIX_ROW3_DDR |= (1 << MATRIX_ROW3_PIN);
	MATRIX_ROW4_DDR |= (1 << MATRIX_ROW4_PIN);
	MATRIX_ROW5_DDR |= (1 << MATRIX_ROW5_PIN);
	MATRIX_ROW6_DDR |= (1 << MATRIX_ROW6_PIN);
	MATRIX_ROW7_DDR |= (1 << MATRIX_ROW7_PIN);
	MATRIX_ROW8_DDR |= (1 << MATRIX_ROW8_PIN);
}

void LEDMatrix_writeColumn(uint8_t col_data)	// column 데이터 출력
{
	if(col_data & (1 << 0))	MATRIX_COL1_PORT |= (1 << MATRIX_COL1_PIN); // ON
	else MATRIX_COL1_PORT &= ~(1 << MATRIX_COL1_PIN);	// OFF
	if(col_data & (1 << 1))	MATRIX_COL2_PORT |= (1 << MATRIX_COL2_PIN);
	else MATRIX_COL2_PORT &= ~(1 << MATRIX_COL2_PIN);
	if(col_data & (1 << 2))	MATRIX_COL3_PORT |= (1 << MATRIX_COL3_PIN);
	else MATRIX_COL3_PORT &= ~(1 << MATRIX_COL3_PIN);
	if(col_data & (1 << 3))	MATRIX_COL4_PORT |= (1 << MATRIX_COL4_PIN);
	else MATRIX_COL4_PORT &= ~(1 << MATRIX_COL4_PIN);
	if(col_data & (1 << 4))	MATRIX_COL5_PORT |= (1 << MATRIX_COL5_PIN);
	else MATRIX_COL5_PORT &= ~(1 << MATRIX_COL5_PIN);
	if(col_data & (1 << 5))	MATRIX_COL6_PORT |= (1 << MATRIX_COL6_PIN);
	else MATRIX_COL6_PORT &= ~(1 << MATRIX_COL6_PIN);
	if(col_data & (1 << 6))	MATRIX_COL7_PORT |= (1 << MATRIX_COL7_PIN);
	else MATRIX_COL7_PORT &= ~(1 << MATRIX_COL7_PIN);
	if(col_data & (1 << 7))	MATRIX_COL8_PORT |= (1 << MATRIX_COL8_PIN);
	else MATRIX_COL8_PORT &= ~(1 << MATRIX_COL8_PIN);
}

void LEDMatrix_writeRow(uint8_t row_data)	// row 데이터 출력
{
	if(row_data & (1 << 7))	MATRIX_ROW1_PORT |= (1 << MATRIX_ROW1_PIN);
	else MATRIX_ROW1_PORT &= ~(1 << MATRIX_ROW1_PIN);
	if(row_data & (1 << 6))	MATRIX_ROW2_PORT |= (1 << MATRIX_ROW2_PIN);
	else MATRIX_ROW2_PORT &= ~(1 << MATRIX_ROW2_PIN);
	if(row_data & (1 << 5))	MATRIX_ROW3_PORT |= (1 << MATRIX_ROW3_PIN);
	else MATRIX_ROW3_PORT &= ~(1 << MATRIX_ROW3_PIN);
	if(row_data & (1 << 4))	MATRIX_ROW4_PORT |= (1 << MATRIX_ROW4_PIN);
	else MATRIX_ROW4_PORT &= ~(1 << MATRIX_ROW4_PIN);
	if(row_data & (1 << 3))	MATRIX_ROW5_PORT |= (1 << MATRIX_ROW5_PIN);
	else MATRIX_ROW5_PORT &= ~(1 << MATRIX_ROW5_PIN);
	if(row_data & (1 << 2))	MATRIX_ROW6_PORT |= (1 << MATRIX_ROW6_PIN);
	else MATRIX_ROW6_PORT &= ~(1 << MATRIX_ROW6_PIN);
	if(row_data & (1 << 1))	MATRIX_ROW7_PORT |= (1 << MATRIX_ROW7_PIN);
	else MATRIX_ROW7_PORT &= ~(1 << MATRIX_ROW7_PIN);
	if(row_data & (1 << 0))	MATRIX_ROW8_PORT |= (1 << MATRIX_ROW8_PIN);
	else MATRIX_ROW8_PORT &= ~(1 << MATRIX_ROW8_PIN);
}

int main(void)
{
	LEDMatrix_init();
	
	uint8_t smile[] = {
		0b00111100,
		0b01000010,
		0b10101001,
		0b10000101,
		0b10000101,
		0b10101001,
		0b01000010,
	0b00111100 };

	while(1)
	{
		for(int i = 0; i < 8; i++){
			// 이웃한 열로의 번짐 방지
			LEDMatrix_writeRow(0);

			// 열 단위 스캔이므로 하나의 열에만 LOW를 가하고 나머지는 HIGH를 가함
			uint8_t col_data = ~(1 << i);
			LEDMatrix_writeColumn(col_data);
			// 각 열에 대응하는 스마일 문자 데이터를 출력
			LEDMatrix_writeRow(smile[i]);
			
			_delay_ms(2);
		}
	}
}
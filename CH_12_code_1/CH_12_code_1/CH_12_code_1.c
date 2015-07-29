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
#include <stdio.h>
#include "UART.h"

void ADC_INIT(unsigned char channel)
{
	ADMUX |= 0x40;
	
	ADCSRA |= 0x07;
	ADCSRA |= (1 << ADEN);
	ADCSRA |= (1 << ADATE);

	ADMUX |= ((ADMUX & 0xE0) | channel);
	ADCSRA |= (1 << ADSC);
}

int read_ADC(void)
{
	while(!(ADCSRA & (1 << ADIF)));
	
	return ADC;
}

void int_to_string(int n, char *buffer)
{
	sprintf(buffer, "%04d", n);
	buffer[4] = '\0';
}

int main(void)
{
	int read;
	char buffer[5];
	
	UART_INIT();
	ADC_INIT(0);
	
	while(1)
	{
		read = read_ADC();
		int_to_string(read, buffer);
		UART_printString(buffer);
		UART_printString("\n");
		
		_delay_ms(1000);
	}
}
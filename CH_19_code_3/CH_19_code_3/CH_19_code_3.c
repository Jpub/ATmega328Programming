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
#include <avr/interrupt.h>
// 1마이크로초당 클록의 수
#define CLOCKS_PER_MICRO ( F_CPU / 1000000L )
// 클록 수를 마이크로초로 변환
#define CLOCKS_TO_MICROSECONDS(a) ( (a) / CLOCKS_PER_MICRO )
// 타이머0의 분주비를 64로 설정한 경우 
// 오버플로 인터럽트가 발생하기까지의 마이크로초 단위 경과 시간
#define MICROSECONDS_PER_TIMER0_OVERFLOW ( CLOCKS_TO_MICROSECONDS (64 * 256) )
// 오버플로 인터럽트가 발생한 경우 밀리초 단위 증가 시간
#define MILLIS_INCREMENT_PER_OVERFLOW ( MICROSECONDS_PER_TIMER0_OVERFLOW / 1000 )
// 오버플로 인터럽트가 발생한 경우 
// 밀리초 단위 증가를 제외하고 남는 마이크로초 단위 증가 시간
#define MICROS_INCREMENT_PER_OVERFLOW ( MICROSECONDS_PER_TIMER0_OVERFLOW % 1000 )
// 프로그램 시작 이후의 경과 시간
volatile unsigned long timer0_millis = 0;
volatile int timer0_micros = 0;
ISR(TIMER0_OVF_vect)
{
	unsigned long m = timer0_millis;
	int f = timer0_micros;
	m += MILLIS_INCREMENT_PER_OVERFLOW; // 밀리초 단위 시간 증가
	f += MICROS_INCREMENT_PER_OVERFLOW; // 마이크로초 단위 시간 증가
	// 마이크로초가 1000을 넘어가면 밀리초를 증가시킴
	int micro_to_millis = f / 1000;
	m += micro_to_millis;
	f = f % 1000;
	timer0_millis = m;
	timer0_micros = f;
}
unsigned long millis()
{
	unsigned long m;
	uint8_t oldSREG = SREG; // 상태 레지스터 값 저장
	// timer0_millis 값을 읽는 동안
	// timer0_millis 값이 변하지 않도록 인터럽트를 비활성화
	cli();
	m = timer0_millis;
	SREG = oldSREG; // 이전 상태 레지스터 값 복원
	return m; // 프로그램 시작 후 경과 시간
}
int main(void)
{
	uint8_t numbers[]
	= {0xFC, 0x60, 0xDA, 0xF2, 0x66, 0xB6, 0xBE, 0xE4, 0xFE, 0xE6};
	int count = 0;
	DDRD = 0xFF;
	PORTD = numbers[0];
	TCCR0B |= (1 << CS01) | (1 << CS00); // 분주비를 64로 설정
	TIMSK0 |= (1 << TOIE0); // 오버플로 인터럽트 허용
	sei(); // 전역적으로 인터럽트 허용
	unsigned long time_previous, time_current;
	time_previous = millis(); // 시작 시간
	while(1)
	{
		time_current = millis(); // 현재 시간
		if((time_current - time_previous) > 1000){ // 1초 경과
			time_previous = time_current;
			count = (count + 1) % 10;
			PORTD = numbers[count];
		}
	}
	return 1;
}
/*
 *  아트멜 스튜디오와 아두이노로 배우는 ATmega328 프로그래밍
 *
 * 		Gyeongyong Heo (hgycap@deu.ac.kr)
 *			Department of Electronic Engineering
 *			Dong-eui University
 *  	2015. 07. 14
 */ 

void ADC_INIT(unsigned char channel)
{
	ADMUX |= 0x40; // AVCC를 기준 전압으로 선택
	ADCSRA |= 0x07; // 분주비 설정
	ADCSRA |= (1 << ADEN); // ADC 활성화
	ADCSRA |= (1 << ADATE); // 자동 트리거 모드
	ADMUX |= ((ADMUX & 0xE0) | channel); // 채널 선택
	ADCSRA |= (1 << ADSC); // 변환 시작
}

int read_ADC(void)
{
	while(!(ADCSRA & (1 << ADIF))); // 변환 종료 대기
	return ADC; // 10비트 값을 반환
}

void setup()
{
	ADC_INIT(0x0E); // 14번 채널 선택
	Serial.begin(9600); // UART 통신 초기화
}

void loop()
{
	int read, actualVCC;
	read = read_ADC(); // 14번 채널 값 읽기
	actualVCC = 1125300L / read; // mV 단위로 변환
	Serial.println(actualVCC); // AVCC 값 출력
	delay(1000);
}
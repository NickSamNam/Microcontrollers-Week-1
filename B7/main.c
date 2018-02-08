/*
 * B7.c
 *
 * Created: 7-2-2018 20:39:10
 * Author : snick
 */ 

#define F_CPU 8000000

#include <avr/io.h>
#include <util/delay.h>

void wait(int ms)
{
	int i;
	for(i = 0; i < ms; i++)
	{
		_delay_ms(1);
	}
}

/*	Control LED 1-6, or use 0 to turn all off.*/
void setCharliePlexingLed(int lednr)
{
	switch(lednr)
	{
		case 0:
			DDRA = 0x00;
			PORTA = 0x00;
			break;
		case 1:
			DDRA = 0x03;
			PORTA = 0x01;
			break;
		case 2:
			DDRA = 0x03;
			PORTA = 0x02;
			break;
		case 3:
			DDRA = 0x06;
			PORTA = 0x02;
			break;
		case 4:
			DDRA = 0x06;
			PORTA = 0x04;
			break;
		case 5:
			DDRA = 0x05;
			PORTA = 0x04;
			break;
		case 6:
			DDRA = 0x05;
			PORTA = 0x01;
			break;
	}
}

int main(void)
{
    /* Replace with your application code */
	int i;
    while (1) 
    {
		for (i = 0; i <= 6; i++)
		{
			setCharliePlexingLed(i);
			wait(500);
		}
    }
}


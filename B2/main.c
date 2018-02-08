/*
 * B.2.c
 *
 * Created: 2-2-2018 12:14:28
 * Author : snick
 */ 

#define F_CPU 8000000

#include <avr/io.h>
#include <util/delay.h>

void wait(int ms);

int main(void)
{
	DDRD = 0xC0;
    /* Replace with your application code */
    while (1) 
    {
		PORTD = 0x80;
		wait(500);
		PORTD = 0x40;
		wait(500);
    }
}

void wait(int ms)
{
	for (int i = 0; i < ms; i++)
	{
		_delay_ms(1);
	}
}
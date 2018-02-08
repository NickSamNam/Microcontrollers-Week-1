/*
 * B4.c
 *
 * Created: 2-2-2018 13:52:07
 * Author : snick
 */

#define F_CPU 8000000

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

void wait(int ms);

int main(void)
{
    /* Replace with your application code */
    DDRD = 0xFF;
    while (1) 
    {
		for (int i = 0x01; i <= 0x80; i <<= 1)
		{
			PORTD = i;
			wait(50);
		}
    }
}

void wait(int ms) {
	for (int i = 0; i < ms; i++)
	{
		_delay_ms(1);
	}
}
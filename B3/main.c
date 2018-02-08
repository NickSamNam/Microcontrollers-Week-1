/*
 * B3.c
 *
 * Created: 2-2-2018 13:19:46
 * Author : snick
 */ 

#define F_CPU 8000000

#include <avr/io.h>
#include <util/delay.h>

int isBitChecked(int byte, int index);
void wait(int ms);

int main(void)
{
    /* Replace with your application code */
    DDRD = 0x80;
	DDRC = 0x00;
    while (1) 
    {
		if (isBitChecked(PINC, 0)) PORTD = 0x80; else PORTD = 0x00;
		wait(250);
		PORTD = 0x00;
		wait(250);
    }
}

int isBitChecked(int byte, int index) {
	int mask = 1<<index;
	return (byte & mask) != 0;
}


void wait(int ms) {
	for (int i = 0; i < ms; i++)
	{
		_delay_ms(1);
	}
}
/*
 * B5.c
 *
 * Created: 2-2-2018 14:42:36
 * Author : snick
 */ 

#define F_CPU 8000000

#include <avr/io.h>
#include <util/delay.h>

#define snek_size_x 4
#define snek_size_y 8
#define snek_size_startup 3
#define snek_blocks 4

const int snek_startup[snek_size_startup][snek_size_x] = {{0x00, 0x00, 0x00, 0x01}, {0x00, 0x00, 0x01, 0x01}, {0x00, 0x01, 0x01, 0x01}};
const int snek_pattern[snek_size_y][snek_size_x] = {{0x01,0x01,0x01,0x01},{0x03,0x01,0x01,0x00}, {0x03,0x03,0x00,0x00},{0x03,0x02,0x02,0x00},{0x02,0x02,0x02,0x02},{0x00,0x02,0x02,0x06},\
{0x00,0x00,0x06,0x06}, {0x00,0x04,0x04,0x06}};
	
void wait(int ms) {
	for (int i = 0; i < ms; i++)
	{
		_delay_ms(1);
	}
}

int main(void)
{
    /* Replace with your application code */
	DDRA = 0xFF;
	DDRB = 0xFF;
	DDRC = 0xFF;
	DDRD = 0xFF;
	
    while (1) 
    {
		int s;
		for (s = 0; s < snek_size_startup; s++)
		{
			PORTA = snek_startup[s][0];
			PORTB = snek_startup[s][1];
			PORTC = snek_startup[s][2];
			PORTD = snek_startup[s][3];
			wait(250);
		}
		int y;
		int b;
		for(b = 0; b < snek_blocks; b++)
		{
			for (y = 0; y < snek_size_y; y++)
			{
				PORTA = snek_pattern[y][0] << b*2;
				PORTB = snek_pattern[y][1] << b*2;
				PORTC = snek_pattern[y][2] << b*2;
				PORTD = snek_pattern[y][3] << b*2;
				wait(250);
			}
		}
    }
}


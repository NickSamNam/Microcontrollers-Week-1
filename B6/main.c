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

#define speed_0 500
#define speed_1 250
#define speed_2 100

#define button_wait 100

static int speed = speed_1;
static int prev_button_t = button_wait;

const int snek_startup[snek_size_startup][snek_size_x] = {{0x00, 0x00, 0x00, 0x01}, {0x00, 0x00, 0x01, 0x01}, {0x00, 0x01, 0x01, 0x01}};
const int snek_pattern[snek_size_y][snek_size_x] = {{0x01,0x01,0x01,0x01},{0x03,0x01,0x01,0x00}, {0x03,0x03,0x00,0x00},{0x03,0x02,0x02,0x00},{0x02,0x02,0x02,0x02},{0x00,0x02,0x02,0x06},\
{0x00,0x00,0x06,0x06}, {0x00,0x04,0x04,0x06}};
	
void wait(int ms) {
	for (int i = 0; i < ms; i++)
	{
		_delay_ms(1);
	}
}

int isBitChecked(int byte, int index) {
	int mask = 1<<index;
	return (byte & mask) != 0;
}

void indicateSpeed()
{
	switch (speed)
	{
		case speed_0:
		PORTE = 0x01;
		break;
		case speed_1:
		PORTE = 0x03;
		break;
		case speed_2:
		PORTE = 0x07;
		break;
	}
}

void updateKeys()
{
	if (isBitChecked(PINE, 7))
	{
		switch (speed)
		{
			case speed_0:
				speed = speed_1;
				break;
			case speed_1:
				speed = speed_2;
				break;
			case speed_2:
				speed = speed_0;
				break;
		}
		indicateSpeed();
	}
	prev_button_t = 0;
}

int main(void)
{
    /* Replace with your application code */
	DDRA = 0xFF;
	DDRB = 0xFF;
	DDRC = 0xFF;
	DDRD = 0xFF;
	
	DDRF = 0x00;

	DDRE = 0x7F;
	
	indicateSpeed();
	
    while (1) 
    {
		int s;
		for (s = 0; s < snek_size_startup; s++)
		{
			int t;
			for (t = 0; t < speed; t++)
			{
				PORTA = snek_startup[s][0];
				PORTB = snek_startup[s][1];
				PORTC = snek_startup[s][2];
				PORTD = snek_startup[s][3];
				if (prev_button_t >= button_wait)
				{
					updateKeys();
				}
				wait(1);
				prev_button_t++;
			}
		}
		int y;
		int b;
		for(b = 0; b < snek_blocks; b++)
		{
			for (y = 0; y < snek_size_y; y++)
			{
				int t;
				for (t = 0; t < speed; t++)
				{
					PORTA = snek_pattern[y][0] << b*2;
					PORTB = snek_pattern[y][1] << b*2;
					PORTC = snek_pattern[y][2] << b*2;
					PORTD = snek_pattern[y][3] << b*2;
					if (prev_button_t >= button_wait)
					{
						updateKeys();
					}
					wait(1);
					prev_button_t++;
				}
			}
		}
    }
}
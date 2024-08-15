/*
 * Exercise1.c
 *
 * Created: 11/22/2014 2:17:05 PM
 *  Author: Ahmed Abdelkader
 */ 

#ifndef F_CPU
#define F_CPU 8000000UL // or whatever may be your frequency
#endif

#include <avr/io.h>
#include <util/delay.h> // to use delay function

int main(void)
{
	DDRD = DDRD | (1<<PD6); //configure pin 3 in PORTD as output pin
	
    while(1)
    {
		PORTD = PORTD & (~(1<<PD6)); // LED ON
		_delay_ms(1000);
		PORTD = PORTD | (1<<PD6);    // LED OFF
		_delay_ms(1000);
    }
}

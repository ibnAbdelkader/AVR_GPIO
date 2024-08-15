/*
 * Exercise2.c
 *
 * Created: 11/22/2014 2:31:27 PM
 *  Author: Ahmed Abdelkader
 */
 
#ifndef F_CPU
#define F_CPU 1000000UL // or whatever may be your frequency
#endif

#include <avr/io.h>

int main(void)
{
	DDRB = DDRB & (~(1<<PB0)); // configure pin 0 of PORTB to be input pin
	DDRB = DDRB & (~(1<<PB1)); // configure pin 1 of PORTB to be input pin
	DDRC = DDRC | (1<<PC0);    // configure pin 0 of PORTC to be output pin
	DDRC = DDRC | (1<<PC1);    // configure pin 1 of PORTC to be output pin
	
	//initialize leds
	PORTC = PORTC & (~(1<<PC0));  // led1 is off at the beginning
	PORTC = PORTC & (~(1<<PC1));  // led2 is off at the beginning
	
    while(1)
    {
		//check if the first switch is pressed
        if(PINB & (1<<PB0))
		{ 
			PORTC = PORTC | (1<<PC0); // turn on led1
			PORTC = PORTC & (~(1<<PC1));   // turn off led2   
		}		
		
		//check if the second switch is pressed	
		else if(PINB & (1<<PB1))
		{
			PORTC = PORTC & (~(1<<PC0));   // turn off led1 
			PORTC = PORTC | (1<<PC1); // turn on led2
		}
		else
		{
			PORTC = PORTC & (~(1<<PC0));   // turn off led1
			PORTC = PORTC & (~(1<<PC1));   // turn off led2
		}  
	} 
}
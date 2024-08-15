/*
 * Exercise5.c
 *
 * Created: 11/23/2014 1:36:59 AM
 * Author: Ahmed Abdelkader
 */

#include <avr/io.h>

int main(void)
{ 
	DDRA &= ~((1<<PA0) | (1<<PA1) | (1<<PA2)); // configure pin PA0, PA1 and PA2 as input pins
	
	DDRC |= (1<<PC0) | (1<<PC1);    // configure pin PC0 and PC1 as output pins
	
	//Motor is stop at the beginning
	PORTC &= ~((1<<PC0) | (1<<PC1));
	 
    while(1)
    {
		// check if the first switch is pressed (Rotate clock wise)
		if(PINA & (1<<PA0))
		{
			PORTC = PORTC & (~(1<<PC0));
			PORTC = PORTC | (1<<PC1);
		}
		
		// check if the second switch is pressed (Rotate anti-clock wise)
		else if(PINA & (1<<PA1))
		{
			PORTC = PORTC | (1<<PC0);
			PORTC = PORTC & (~(1<<PC1));	
		}
				
		// check if the third switch is pressed (turn off the motor)
		else if(PINA & (1<<PA2))
		{
			PORTC = PORTC & (~(1<<PC0));
			PORTC = PORTC & (~(1<<PC1));
		}				    
    }
}
/*
 * Exercise4.c
 *
 * Created: 11/22/2014 2:43:10 PM
 *  Author: Ahmed Abdelkader
 */

/* Clock is 1Mhz by Default */
 
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRD = DDRD & (~(1<<PD4)); // configure pin 4 of PORTD to be input pin
	DDRC = 0xFF; // configure all pins of PORTC as output pins
	
	// initialize the 7-segment
	PORTC = 0;
	
    while(1)
    {
		// check if the push button is pressed or not
		if( PIND & (1<<PD4) ){
			_delay_ms(30);
			//second check due to switch bouncing
			if( PIND & (1<<PD4) ){
				if(PORTC == 9) PORTC = 0; // if overflow occurs
				else PORTC = PORTC + 1;	  // increment 7-segment every press   
			}
			while( PIND & (1<<PD4) ){} // wait until switch is released
		}									   
    }
}
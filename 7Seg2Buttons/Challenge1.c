/*
 * Challenge1.c
 *
 * Created: 11/22/2014 2:43:10 PM
 *  Author: Ahmed Abdelkader
 */ 

/* clock is 1Mhz by default */

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRA = DDRA & (~(1<<PA0)); // configure pin 0 of PORTA to be input pin
	DDRA = DDRA & (~(1<<PA1)); // configure pin 0 of PORTA to be input pin
	DDRD = 0xFF; // configure all pins of PORTD as output pins
	
	// initialize the 7-segment
	PORTD = 0;
	
    while(1)
    {
		if(PINA & (1<<PA0)){ // check if the first push button is pressed or not
			_delay_ms(30);
			//second check due to switch bouncing
			if(PINA & (1<<PA0)){
					if(PORTD != 9) PORTD++;	   
			}
			while(PINA & (1<<PA0)){}
		}
		
		else if(PINA & (1<<PA1)){ // check if the second push button is pressed or not
			_delay_ms(30);
			//second check due to switch bouncing
			if(PINA & (1<<PA1)){
					if(PORTD != 0) PORTD--;	   
			}
			while(PINA & (1<<PA1)){}
		}				       
    }
}
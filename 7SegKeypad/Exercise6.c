/*
 * Exercise6.c
 *
 * Created: 1/23/2015 9:50:20 PM
 *  Author: Ahmed Abdelkader
 */ 

#include "keypad.h"

int main(void)
{
	uint8 key;
	DDRC  = 0xFF; /* 7-segment pins as output pins */
	PORTC = 0; /* 7-segment displays Zero at the beginning */

    while(1)
    {
        key = KeyPad_getPressedKey(); /* get the pressed button from keypad */
	    if((key >= 0) && (key <= 9))
		{ 
			 PORTC = key;
		}						
    }
}
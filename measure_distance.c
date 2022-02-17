/*
 * measure_distance.c
 *
 *  Created on: Oct 25, 2021
 *      Author: as
 */

#include "lcd.h"
#include "icu.h"
#include "ultrasonic.h"
#include <avr/io.h>

extern uint8 g_edgeCount;

int main(void){
	uint16 distance=0;
	/* Enable Global Interrupt I-Bit */
		SREG |= (1<<7);
	/* Initialize both the LCD and Ultrasonic driver */
	LCD_init();
	Ultrasonic_init();

	while(1){
		if(g_edgeCount == 2)
				{
					Icu_DeInit(); /* Disable ICU Driver */
					g_edgeCount = 0;
					LCD_displayString("Distance = ");
					/* read the distance */
					distance=Ultrasonic_readDistance();
					/* display the distance on LCD screen */
					LCD_intgerToString(distance);
					LCD_displayString("cm");
				}
	}
}


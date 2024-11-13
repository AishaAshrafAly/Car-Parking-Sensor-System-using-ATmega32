/*
 * car_parking.c
 *
 *  Created on: Oct 16, 2024
 *      Author: aisha
 */



/************** Includes **************/
#include <util/delay.h>
#include <avr/io.h>
#include "std_types.h"
#include "buzzer.h"
#include "lcd.h"
#include "led.h"
#include "ultrasonic.h"

int main()
{
	/********** Initializations **********/

	/* Buzzer Initialization */
	Buzzer_init();

	/* LED Initialization */
	LEDs_init();

	/* Ultrasonic Initialization */
	Ultrasonic_init();

	/* Set I-Bit */
	SREG |= (1 << SREG_I);

	/* LCD Initialization */
	LCD_init();
	LCD_displayStringRowColumn(0, 1, "Distance=   cm");

	/* Variable to store the distance */
	uint8 distance = 0;

	/************** Program **************/
	for(;;)
	{
		/* Calculate distance and display on the LCD */
		distance = Ultrasonic_readDistance();
		LCD_moveCursor(0, 10);
		LCD_intgerToString(distance);
		LCD_displayCharacter(' ');

		/* Checking current condition */
		if(distance > 20)
		{
			/* All LEDs are turned OFF */
			LED_OFF(LEDR_ID);
			LED_OFF(LEDG_ID);
			LED_OFF(LEDB_ID);
		}
		else if(distance > 15)
		{
			/* Only the Red LED turns ON */
			LED_ON(LEDR_ID);
			LED_OFF(LEDG_ID);
			LED_OFF(LEDB_ID);
		}
		else if(distance > 10)
		{
			/* Red and Green LEDs ON, Blue LED OFF */
			LED_ON(LEDR_ID);
			LED_ON(LEDG_ID);
			LED_OFF(LEDB_ID);
		}
		else if(distance > 5)
		{
			/* All LEDs ON (Red, Green, Blue) */
			LED_ON(LEDR_ID);
			LED_ON(LEDG_ID);
			LED_ON(LEDB_ID);
		}
		else
		{
			/* LCD shows "STOP" */
			LCD_displayStringRowColumn(1, 6, "STOP");

			/* All LEDs are flashing (Red, Green, Blue), Buzzer sounds */
			while(distance <= 5)
			{
				Buzzer_on();
				LED_ON(LEDR_ID);
				LED_ON(LEDG_ID);
				LED_ON(LEDB_ID);
				_delay_ms(500);
				Buzzer_off();
				LED_OFF(LEDR_ID);
				LED_OFF(LEDG_ID);
				LED_OFF(LEDB_ID);
				_delay_ms(500);
				distance = Ultrasonic_readDistance();
				LCD_moveCursor(0, 10);
				LCD_intgerToString(distance);
				LCD_displayCharacter(' ');
			}

			/* Turn buzzer off and remove stop word */
			Buzzer_off();
			LCD_displayStringRowColumn(1, 6, "    ");
		}
	}
}

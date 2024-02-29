/*
 * LED.c
 *
 * Created: 9/18/2023 12:36:44 AM
 *  Author: Manal Nabil Donia
 */ 
#include "LED.h"


void LedInt      (uint8_t port , uint8_t pin)
{
	DIO_enumSetPinDirection(port , pin , OUTPUT_PIN);
}


void LedOn        (uint8_t port , uint8_t pin)
{
	DIO_enumWritePin(port , pin , HIGH_LOGIC);
}


void LedOff       (uint8_t port , uint8_t pin)
{
	DIO_enumWritePin(port , pin , LOW_LOGIC);
}


void LedToggle    (uint8_t port , uint8_t pin)
{
	DIO_enumTogglePin (port , pin );
}



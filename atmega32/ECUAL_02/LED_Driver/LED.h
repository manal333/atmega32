/*
 * LED.h
 *
 * Created: 9/18/2023 12:37:00 AM
 *  Author: Manal Nabil Donia
 */ 


#ifndef LED_H_
#define LED_H_

/*************INCLUDES*************/

#include "../../MCAL/DIO/DIO.h"
	
/*************FUNCTIONS*************/

void LedInt       (uint8_t port , uint8_t pin);
void LedOn        (uint8_t port , uint8_t pin);
void LedOff       (uint8_t port , uint8_t pin);
void LedToggle    (uint8_t port , uint8_t pin);


#endif /* LED_H_ */
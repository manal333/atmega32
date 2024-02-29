/*
 * Register.h
 *
 * Created: 9/17/2023 6:36:35 PM
 *  Author: Manal Nabil Donia
 */ 


#ifndef REGISTER_H_
#define REGISTER_H_

#include "TYPES.h"


/*************GROUP_A*************/

#define PORTA    *((volatile uint8_t*)0x3B)
#define DDRA     *((volatile uint8_t*)0x3A)
#define PINA     *((volatile uint8_t*)0X39)

/*************GROUP_B*************/

#define PORTB    *((volatile uint8_t*)0x38)
#define DDRB     *((volatile uint8_t*)0x37)
#define PINB     *((volatile uint8_t*)0X36)

/*************GROUP_C*************/

#define PORTC    *((volatile uint8_t*)0x35)
#define DDRC     *((volatile uint8_t*)0x34)
#define PINC     *((volatile uint8_t*)0X33)

/*************GROUP_D*************/

#define PORTD    *((volatile uint8_t*)0x32)
#define DDRD     *((volatile uint8_t*)0x31)
#define PIND     *((volatile uint8_t*)0X30)

/*************INTERRUPT*************/

#define SREG           *((volatile uint8_t*)0x5f)
#define GICR           *((volatile uint8_t*)0x5B)
#define GIFR           *((volatile uint8_t*)0x5A)
#define MCUCR          *((volatile uint8_t*)0x55)
#define MCUCSR         *((volatile uint8_t*)0x54)

/*************TIMER*************/

#define TCCR0       *((volatile uint8_t*)0x53)
#define TCNT0       *((volatile uint8_t*)0x52)
#define TIMSK       *((volatile uint8_t*)0x59)
#define OCR0        *((volatile uint8_t*)0x5C)


#endif /* REGISTER_H_ */
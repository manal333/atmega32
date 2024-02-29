/*
 * DIO.c
 *
 * Created: 9/17/2023 6:34:49 PM
 *  Author: Manal Nabil Donia
 */ 
#include "DIO.h"


Std_ReturnType_t DIO_enumSetPinDirection    (uint8_t port , uint8_t pin , uint8_t direction)
{
	if((pin <= PIN7)&&(direction==OUTPUT_PIN||direction==INPUT_PIN)&&((port>='A')&&(port<='D')))
	{
		switch(port)
		{
			case PORT_A : 
			if(direction == OUTPUT_PIN) {SET_BIT(DDRA,pin);break;} 
			else if(direction == INPUT_PIN) {CLR_BIT(DDRA,pin);break ;}
			case PORT_B :
			if(direction == OUTPUT_PIN) {SET_BIT(DDRB,pin);break;}
			else if(direction == INPUT_PIN) {CLR_BIT(DDRB,pin);break;}
			case PORT_C :
			if(direction == OUTPUT_PIN) {SET_BIT(DDRC,pin);break;}
			else if(direction == INPUT_PIN) {CLR_BIT(DDRC,pin);break;}
			case PORT_D :
			if(direction == OUTPUT_PIN) {SET_BIT(DDRD,pin);break;}
			else if(direction == INPUT_PIN) {CLR_BIT(DDRD,pin);break;}										
			
		}
		return DIO_OK;
	} 
	else
	{
		return DIO_NOT_OK;
	}
}
Std_ReturnType_t DIO_enumWritePin           (uint8_t port , uint8_t pin , uint8_t logic)
{
	if((pin <= PIN7)&&(logic==HIGH_LOGIC||logic==LOW_LOGIC)&&((port>='A')&&(port<='D')))
	{
		switch(port)
		{
			case PORT_A :
			if(logic == HIGH_LOGIC) {SET_BIT(PORTA,pin);break;}
			else if(logic == LOW_LOGIC) {CLR_BIT(PORTA,pin);break;}
			case PORT_B :
			if(logic == HIGH_LOGIC) {SET_BIT(PORTB,pin);break;}
			else if(logic == LOW_LOGIC) {CLR_BIT(PORTB,pin);break;}
			case PORT_C  :
			if(logic == HIGH_LOGIC) {SET_BIT(PORTC,pin);break;}
			else if(logic == LOW_LOGIC) {CLR_BIT(PORTC,pin);break;}
			case PORT_D :
			if(logic == HIGH_LOGIC) {SET_BIT(PORTD,pin);break;}
			else if(logic == LOW_LOGIC) {CLR_BIT(PORTD,pin);break;}
			
		}
		return DIO_OK;
	}
	else
	{
		return DIO_NOT_OK;
	}		
}
Std_ReturnType_t DIO_enumReadPin            (uint8_t port , uint8_t pin , uint8_t * logic)
{
	if((logic != ((void*)0))&&(pin <= PIN7)&&((port>='A')&&(port<='D')))
     {
		  switch(port)
		  {
			case PORT_A : *logic = GET_BIT(PINA,pin);break;
			case PORT_B : *logic = GET_BIT(PINB,pin);break;
			case PORT_C : *logic = GET_BIT(PINC,pin);break;
			case PORT_D : *logic = GET_BIT(PIND,pin);break;
		  }
		  return DIO_OK;
	   }
	   else
	  {
		return DIO_NOT_OK;
	 }
	
}
Std_ReturnType_t DIO_enumTogglePin          (uint8_t port , uint8_t pin )
{
	if ((pin <= PIN7)&&((port>='A')&&(port<='D')))
	{
		switch(port)
		{
			case PORT_A : TOG_BIT(PORTA,pin);break;
			case PORT_B : TOG_BIT(PORTB,pin);break;
			case PORT_C : TOG_BIT(PORTC,pin);break;
			case PORT_D : TOG_BIT(PORTD,pin);break;
		}
	}
	else
	{
		return DIO_NOT_OK;
	}
}
Std_ReturnType_t DIO_enumSetPortHigh        (uint8_t port)
{
	if((port>='A')&&(port<='D'))
	{
		switch(port)
	{
		case PORT_A : PORTA = PORT_HIGH;break;
		case PORT_B : PORTB = PORT_HIGH;break;
		case PORT_C : PORTC = PORT_HIGH;break;
		case PORT_D : PORTD = PORT_HIGH;break;
	}
	return DIO_OK;
	}
	else
	{
		return DIO_NOT_OK;
	}
	
}
Std_ReturnType_t DIO_enumSetPortLow         (uint8_t port)
{
	
	if((port>='A')&&(port<='D'))
	{
		switch(port)
	{
		case PORT_A : PORTA = PORT_LOW;break;
		case PORT_B : PORTB = PORT_LOW;break;
		case PORT_C : PORTC = PORT_LOW;break;
		case PORT_D : PORTD = PORT_LOW;break;
	}	
	return DIO_OK;
	}
	else
	{
		return DIO_NOT_OK;
	}	
}
Std_ReturnType_t DIO_enumSetPortOutput      (uint8_t port)
{
	if((port>='A')&&(port<='D'))
	{
		switch(port)
		{
			case PORT_A : DDRA = OUTPUT_PORT;break;
			case PORT_B : DDRB = OUTPUT_PORT;break;
			case PORT_C : DDRC = OUTPUT_PORT;break;
			case PORT_D : DDRD = OUTPUT_PORT;break;
		}
		return DIO_OK;
	}
	else
	{
		return DIO_NOT_OK;
	}	
	
}
Std_ReturnType_t DIO_enumSetPortInput       (uint8_t port)
{
		if((port>='A')&&(port<='D'))
		{
			switch(port)
			{
				case PORT_A : DDRA = INPUT_PORT;break;
				case PORT_B : DDRB = INPUT_PORT;break;
				case PORT_C : DDRC = INPUT_PORT;break;
				case PORT_D : DDRD = INPUT_PORT;break;
			}
			return DIO_OK;
		}
		else
		{
			return DIO_NOT_OK;
		}
	
}
Std_ReturnType_t DIO_enumTogglePort         (uint8_t port)
{
	if((port>='A')&&(port<='D'))
	{
		switch(port)
		{
			case PORT_A : TOG_PORT(PORTA);break;
			case PORT_B : TOG_PORT(PORTC);break;
			case PORT_C : TOG_PORT(PORTC);break;
			case PORT_D : TOG_PORT(PORTD);break;
		}
		return DIO_OK;
	}
	else
	{
		return DIO_NOT_OK;
	}	
}
Std_ReturnType_t DIO_enumSetPort            (uint8_t port , uint8_t value)
{
	if((port>='A')&&(port<='D'))
	{
		switch(port)
		{
			case PORT_A : PORTA = value;break;
			case PORT_B : PORTB = value;break;
			case PORT_C : PORTC = value;break;
			case PORT_D : PORTD = value;break;
		}
		return DIO_OK;
	}
	else
	{
		return DIO_NOT_OK;
	}
		
}
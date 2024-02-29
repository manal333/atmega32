/*
 * Butten.c
 *
 * Created: 9/18/2023 12:37:56 AM
 *  Author: Manal Nabil Donia
 */ 

#include "Button.h"

void BUTTON_INIT              (Button_Config_t Butten_CFG)
{
	DIO_enumSetPinDirection(Butten_CFG.Port , Butten_CFG.Pin , INPUT_PIN);
	if (Butten_CFG.Pullup_state==Int_PULL_UP)
	{
		DIO_enumWritePin(Butten_CFG.Port , Butten_CFG.Pin , HIGH_LOGIC);
	}
}

uint8_t GET_Button_Pressed    (Button_Config_t Butten_CFG)
{
	uint8_t PinValue = BUTTON_NOT_PRESSED;
	uint8_t Result   = BUTTON_NOT_PRESSED;
	
	
	if ((Butten_CFG.Pullup_state == Int_PULL_UP)||(Butten_CFG.Pullup_state == Ext_PULL_UP))
	{
		DIO_enumReadPin(Butten_CFG.Port , Butten_CFG.Pin , &PinValue);
			
		if (PinValue == 0)
		{
			Result = BUTTON_PRESSED;
		}
		else if(PinValue == 1)
		{
			Result = BUTTON_NOT_PRESSED;
		}
	}
	
	if (Butten_CFG.Pullup_state == Ext_PULL_DOWN)
	{
		DIO_enumReadPin(Butten_CFG.Port , Butten_CFG.Pin , &PinValue);
		
		if (PinValue == 0)
		{
			Result = BUTTON_NOT_PRESSED;
		}
		else if(PinValue == 1)
		{
			Result = BUTTON_PRESSED;
		}
	}
	return Result;
}


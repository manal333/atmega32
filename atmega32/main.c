/*
 * test_02.c
 *
 * Created: 9/17/2023 6:31:51 PM
 * Author : Manal Nabil Donia
 */ 

//#include <avr/io.h>
#include "MCAL_02/Timer/Timer.h"
#include "MCAL_02/DIO_Driver/DIO.h"
void overflowTimer()
{
	TOG_BIT(PORTC ,0);
}

int main(void)
{
	
	SET_BIT(DDRC , 0);
	Timer_Config_t timerCFG;
	timerCFG.Timerx = Timer_0;
	timerCFG.Timer_Mode = Timer_Mode_Normal;
	timerCFG.Timer_Clock_Source = Timer_Clock_Source_prescaling_8;
	timerCFG.IRQ_Enable = IRQ_Enable_TOIE0;
	timerCFG.P_IQR_CallBack= overflowTimer;
    /* Replace with your application code */
    while (1) 
    {
    }
}


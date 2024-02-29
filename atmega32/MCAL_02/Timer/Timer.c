/*
 * Timer.c
 *
 * Created: 11/8/2023 11:41:48 AM
 *  Author: Manal Nabil Donia
 */ 

/* ======================================================================= */
/* ============================= INCLUDES ================================ */
/* ======================================================================= */
#include "Timer.h"

/* ======================================================================= */
/* ========================== Globel Variable ============================ */
/* ======================================================================= */

//Timer_Config_t *timer_cfg;
Timer_Config_t G_TIMERCFG;
//G_TIMERCFG *timer_cfg;
void (*P_IQR_CallBack)(void) = 0;

//#define __INTR_ATTRS	used,externally_visible

/* ======================================================================= */
/* ================= APIs Support by "MCAL Timer Driver ================== */
/* ======================================================================= */


/*
 * ==================================
 * @FN             - MACL_Timer0_INit 
 * @brief          - initialization timer0 according to specific parameter
 * @param [in]     - timer0_cfg : a pointer to Timer_Config_t struct that contains the configuration information for the specified TIMER Module
 * @retval         - none
 * @note           - none
 * */
void MACL_Timer_INit                             (Timer_Config_t* timer_cfg)
{
	G_TIMERCFG = *timer_cfg;
	//1.select timer
	uint8_t timer = timer_cfg->Timerx;
	if (timer == Timer_0)
	{
		//2.select mode
		TCCR0 |= timer_cfg->Timer_Mode;
		if (timer_cfg->Timer_Mode == Timer_Mode_Fast_PMW_interval || timer_cfg->Timer_Mode == Timer_Mode_Fast_PMW_noninterval)
		{
			DDRB |= (1<<3);
		}
		//3.select prescaler
		TCCR0 |= timer_cfg->Timer_Clock_Source;
		if (timer_cfg->Timer_Clock_Source == Timer_Clock_Source_External_Falling_edge || timer_cfg->Timer_Clock_Source == Timer_Clock_Source_External_rising_edge)
		{
			DDRB&=(~(1<<0));
		}
		//4.select IQr
		TIMSK |= timer_cfg->IRQ_Enable;
		//Enable Global Interrupt
		SREG |= (1<<7);
	} 
	else if(timer == Timer_1)
	{
	}
	else if(timer == Timer_2)
	{
		//2.select mode
		TCCR2 |= timer_cfg->Timer_Mode;
		if (timer_cfg->Timer_Mode == Timer_Mode_Fast_PMW_interval || timer_cfg->Timer_Mode == Timer_Mode_Fast_PMW_noninterval)
		{
			DDRD |= (1<<3);
		}
		//3.select prescaler
		TCCR2 |= timer_cfg->Timer_Clock_Source;
		if (timer_cfg->Timer_Clock_Source == Timer_Clock_Source_External_Falling_edge || timer_cfg->Timer_Clock_Source == Timer_Clock_Source_External_rising_edge)
		{
			DDRD&=(~(1<<0));
		}
		//4.select IQr
		TIMSK |= timer_cfg->IRQ_Enable;
		//Enable Global Interrupt
		SREG |= (1<<7);	
	}

	
	
	 
}

/*
 * ==================================
 * @FN             - MACL_Timer0_GetCounterValue 
 * @brief          - get the number which in the TCNT register
 * @param [in]     - TicksNumber : value of number that the TCNT0 register arrived
 * @retval         - none
 * @note           - none
 * */
void MACL_Timer_GetCounterValue                  (uint8_t* TicksNumber)
{
	if (G_TIMERCFG.Timerx == Timer_0)
	{
		*TicksNumber = TCNT0;
	}
	else if (G_TIMERCFG.Timerx  == Timer_1)
	{
		
	}
	else if (G_TIMERCFG.Timerx  == Timer_2)
	{
		*TicksNumber = TCNT2;
	}
	
}

/*
 * ==================================
 * @FN             - MACL_Timer0_SetComperValue 
 * @brief          - set the value of compare matching
 * @param [in]     - TicksNumber : value of number that the timer will stop counting when arrived 
 * @retval         - none
 * @note           - none
 * */
void MACL_Timer_SetComperValue                   (uint8_t TicksNumber)
{
	if (G_TIMERCFG.Timerx  == Timer_0)
	{
		OCR0 |= TicksNumber;
	}
	else if (G_TIMERCFG.Timerx  == Timer_1)
	{
		
	}
	else if (G_TIMERCFG.Timerx  == Timer_2)
	{
		OCR2 |= TicksNumber;
	}
	
}

/*
 * ==================================
 * @FN             - MACL_Timer0_DutyCycle 
 * @brief          - initialization timer0 according to specific parameter
 * @param [in]     - DutyCycle : a pointer to Timer_Config_t struct that contains the configuration information for the specified TIMER Module
 * @retval         - none
 * @note           - none
 * */
void MACL_Timer_PMWDutyCycle                  (uint8_t DutyCycle)
{
	if(G_TIMERCFG.Timerx == Timer_0)
	{
		if (G_TIMERCFG.Timer_Mode == Timer_Mode_Fast_PMW_noninterval)
		{
			OCR0 = (0xFF*DutyCycle)/100;
		} 
		else if(G_TIMERCFG.Timer_Mode == Timer_Mode_Fast_PMW_interval)
		{
			OCR0 = (255-(0xFF*DutyCycle)/100);
		}
	}
	else if(G_TIMERCFG.Timer_Mode == Timer_1)
	{
		
	}
	else if (G_TIMERCFG.Timer_Mode == Timer_2)
	{
		if (G_TIMERCFG.Timer_Mode == Timer_Mode_Fast_PMW_noninterval)
		{
			OCR2 = (0xFF*DutyCycle)/100;
		}
		else if(G_TIMERCFG.Timer_Mode == Timer_Mode_Fast_PMW_interval)
		{
			OCR2 = (255-(0xFF*DutyCycle)/100);
		}	
	}
}
/* ======================================================================= */
/* ============================ IQR Handlers ============================= */
/* ======================================================================= */
//-------------------------------------
//     IQR_TIMER0_COMP
//-------------------------------------
void __vector_13(void)__attribute__((signal));
void __vector_13(void)
{
	P_IQR_CallBack();
}
//-------------------------------------
//     IQR_TIMER0_OVF
//-------------------------------------
void __vector_11(void)__attribute__((signal));
void __vector_11(void)
{
	P_IQR_CallBack();	
}
//-------------------------------------
//     IQR_TIMER1_CAPT
//-------------------------------------
void __vector_6(void)__attribute__((signal));
void __vector_6(void)
{
	P_IQR_CallBack();	
}
//-------------------------------------
//     IQR_TIMER1_COMPA
//-------------------------------------
void __vector_7(void)__attribute__((signal));
void __vector_7(void)
{
	P_IQR_CallBack();	
}
//-------------------------------------
//     IQR_TIMER1_COMPB
//-------------------------------------
void __vector_8(void)__attribute__((signal));
void __vector_8(void)
{
	P_IQR_CallBack();	
}
//-------------------------------------
//     IQR_TIMER1_OVF
//-------------------------------------
void __vector_9(void)__attribute__((signal));
void __vector_9(void)
{
	P_IQR_CallBack();	
}
//-------------------------------------
//     IQR_TIMER2_COMP
//-------------------------------------
void __vector_4(void)__attribute__((signal));
void __vector_4(void)
{
	P_IQR_CallBack();	
}
//-------------------------------------
//     IQR_TIMER2_OVF
//-------------------------------------
void __vector_5(void)__attribute__((signal));
void __vector_5(void)
{
	P_IQR_CallBack();	
}
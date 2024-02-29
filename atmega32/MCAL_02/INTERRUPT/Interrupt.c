/*
 * Interrupt.c
 *
 * Created: 10/6/2023 11:49:34 PM
 *  Author: Manal Nabil Donia
 */ 
#include "interrupt.h"
//#define __INTR_ATTRS	used,externally_visible

void (*EXTI_CallBack[3]) (void) = { NULL } ;  

/******* ENABLE_AND_DISABLE_GLOBAL_INTERRUPT*******/

void Enable_Global_Interrupt   (void)
{
	SET_BIT(SREG,GLOBAL_INTERRUPT_CONTROL);
}

void Disable_Global_Interrupt   (void)
{
	CLR_BIT(SREG,GLOBAL_INTERRUPT_CONTROL);
}

/******* ENABLE_AND_DISABLE_EXT_INTERRUPT*******/

void Disable_Interrupt  (uint8_t DisablePin)
{
		switch(DisablePin)
		{
			case INT0: CLR_BIT(GICR,INT0);break;
			case INT1: CLR_BIT(GICR,INT1);break;
			case INT2: CLR_BIT(GICR,INT2);break;
		}
}

void Enable_Interrupt   (uint8_t EnablePin)
{
		switch(EnablePin)
		{
			case INT0: SET_BIT(GICR,INT0);break;
			case INT1: SET_BIT(GICR,INT1);break;
			case INT2: SET_BIT(GICR,INT2);break;
		}

}

/*******SENSE_MODE*******/

/*MODE_0-->LOW_LEVEL * MODE_1-->ON_CHANGE * MODE_2-->FALLING_EDEG * MODE_3-->RISING_EDGE*/

void EXTI_void_Select_line_Mode (uint8_t LINE , uint8_t sense_mode )
{
		switch(LINE)
		{
			
		case INT0 :
		switch(sense_mode)
		{
			case LOW_LEVEL    : CLR_BIT(MCUCR,0);CLR_BIT(MCUCR,1);break;
			case ON_CHANGE    : SET_BIT(MCUCR,0);CLR_BIT(MCUCR,1);break;
			case FALLING_EDEG : CLR_BIT(MCUCR,0);SET_BIT(MCUCR,1);break;
			case RISING_EDGE  : SET_BIT(MCUCR,0);SET_BIT(MCUCR,1);break;
		}
		case INT1 :
		switch(sense_mode)
		{
			case LOW_LEVEL    : CLR_BIT(MCUCR,2);CLR_BIT(MCUCR,3);break;
			case ON_CHANGE    : SET_BIT(MCUCR,2);CLR_BIT(MCUCR,3);break;
			case FALLING_EDEG : CLR_BIT(MCUCR,2);SET_BIT(MCUCR,3);break;
			case RISING_EDGE  : SET_BIT(MCUCR,2);SET_BIT(MCUCR,3);break;
		}
		case INT2 :
		switch(sense_mode)
		{
			case INT2 :
			switch(sense_mode)
			{
			case FALLING_EDEG : CLR_BIT(MCUCSR,6);break;
			case RISING_EDGE  : SET_BIT(MCUCSR,6);break;
		}
		
		}
}
}

void Clear_flag(uint8_t LINE)
{
	return GET_BIT( GIFR , LINE );
}


void EXTI_voidSetCallBack       ( void (*P_IQR_CallBack)(void) , uint8_t LINE ){

	if( P_IQR_CallBack != NULL ){

		EXTI_CallBack[LINE] = P_IQR_CallBack ;

	}

}


/*******ISR*******/

void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{

	if( EXTI_CallBack[0] != NULL ){

		EXTI_CallBack[0](); /*  Call The Global Pointer to Func   */
		Clear_flag(INT0);

	}

}

void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{

	if( EXTI_CallBack[1] != NULL ){

		EXTI_CallBack[1]();
		Clear_flag(INT1);

	}

}


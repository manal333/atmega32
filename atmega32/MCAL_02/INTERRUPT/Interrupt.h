/*
 * Interrupt.h
 *
 * Created: 10/6/2023 11:49:52 PM
 *  Author: Manal Nabil Donia
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_

/* ======================================================================= */
/* ============================= INCLUDES ================================ */
/* ======================================================================= */

#include "../../UTILITIES/Register.h"
#include "../../UTILITIES/TYPES.h"
#include "../../UTILITIES/BitMath.h"

/* ======================================================================= */
/* =============================== Macros ================================ */
/* ======================================================================= */

#define NULL ((void*)0)

#define GLOBAL_INTERRUPT_CONTROL 7

/* ======================================================================= */
/* ============================= DATA_TYPE =============================== */
/* ======================================================================= */


typedef enum
{
	INT2 = 5,
	INT0,
	INT1
}GICR_BIT;

typedef enum
{
	LOW_LEVEL = 0,
	ON_CHANGE,
	FALLING_EDEG ,
	RISING_EDGE
	
	}SENSE_MODE;
	
/* ======================================================================= */
/* =============== APIs Support by "MCAL Interrupt Driver ================ */
/* ======================================================================= */

void Enable_Global_Interrupt    (void);
void Disable_Global_Interrupt   (void);

void Disable_Interrupt          (uint8_t DisablePin);
void Enable_Interrupt           (uint8_t EnablePin);

void EXTI_void_Select_line_Mode (uint8_t LINE  , uint8_t sense_mode);

void Clear_flag                 (uint8_t LINE);
void EXTI_voidSetCallBack       ( void (*P_IQR_CallBack)(void) , uint8_t LINE );
void (*P_IQR_CallBack)(void);



#endif /* INTERRUPT_H_ */
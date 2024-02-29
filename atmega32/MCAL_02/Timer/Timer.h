/*
 * Timer.h
 *
 * Created: 11/8/2023 11:42:09 AM
 *  Author: Manal Nabil Donia
 */ 


#ifndef TIMER_H_
#define TIMER_H_

/* ======================================================================= */
/* ============================= INCLUDES ================================ */
/* ======================================================================= */

#include "../../UTILITIES_02/TYPES.h"
#include "../../UTILITIES_02/Register.h"

/* ======================================================================= */
/* =============================== Macros ================================ */
/* ======================================================================= */
#define TCCR0          *((volatile uint8_t*)0x53)
#define CS00           0
#define CS01           1
#define CS02           2
#define WGM01          3
#define COM00          4
#define COM01          5
#define WGM00          6
#define FOC0           7

#define TCNT0         *((volatile uint8_t*)0x52)

#define OCR0          *((volatile uint8_t*)0x5C)

#define TIMSK         *((volatile uint8_t*)0x59)
#define TOIE0         0
#define OCIE0         1
#define TOIE2         6
#define OCIE2         7

#define TCCR2         *((volatile uint8_t*)0x45)
#define TCNT2         *((volatile uint8_t*)0x44)
#define OCR2          *((volatile uint8_t*)0x43)
/* ======================================================================= */
/* ================= Usre Type Definition (Structures) =================== */
/* ======================================================================= */

typedef struct
{
	/* === Timerx ===
	* specifies Timer (Timer 0 | Timer 1 | Timer 2)
	* this parameter must be set base on @ref Timerx_define
	* */
	uint8_t Timerx;
	
	/* === Timer_Mode ===
	* specifies Timer MOde (Normal | CTC | Fast PMW | Phase correct PMW)
	* this parameter must be set base on @ref Timer_Mode_define
	* */
	uint8_t Timer_Mode;
	
	/* === Timer_Clock_Source ===
	* specifies Timer Clock Source (No_clock  | No_prescalling  | prescaling 8 | 
	  prescaling 64 | prescaling 256 |prescaling 1024 | External Falling edge | External rising edge)
	* this parameter must be set base on @ref Timer_Clock_Source_define
	* */
	uint8_t Timer_Clock_Source;

	/* === IRQ_Enabel ===
	* specifies Enable or Disable IRQ
	* this parameter must be set base on @ref IRQ_Enable_define
	* */
	uint8_t IRQ_Enable;
	
	/* === (*P_IQR_CallBack)(void) ===
	* set the C function which will be called once IQR Happens 
	* */
	void (*P_IQR_CallBack)(void);	
	 
	}Timer_Config_t;
	
/* ======================================================================= */
/* ================== Macros Configuration Reference ===================== */
/* ======================================================================= */
//-------------------------------------
//     @ref Timerx_define
//-------------------------------------
#define Timer_0                                  0
#define Timer_1                                  1
#define Timer_2                                  2

//-------------------------------------
//     @ref Timer_Mode_define
//-------------------------------------
#define Timer_Mode_Normal                         (uint8_t)(0b10000<<WGM01)          
#define Timer_Mode_CTC                            (uint8_t)(0b10001<<WGM01)
#define Timer_Mode_Fast_PMW_noninterval           (uint8_t)(0b01101<<WGM01)
#define Timer_Mode_Fast_PMW_interval              (uint8_t)(0b01111<<WGM01)
#define Timer_Mode_Phase_correct_PMW_noninterval  (uint8_t)(0b01100<<WGM01)
#define Timer_Mode_Phase_correct_PMW_interval     (uint8_t)(0b01110<<WGM01)

//-------------------------------------
//     @ref Timer_Clock_Source_define
//-------------------------------------
#define Timer_Clock_Source_No_clock               (uint8_t)(0b000<<CS00)
#define Timer_Clock_Source_No_prescaling          (uint8_t)(0b001<<CS00)
#define Timer_Clock_Source_prescaling_8           (uint8_t)(0b010<<CS00)
#define Timer_Clock_Source_prescaling_64          (uint8_t)(0b011<<CS00)
#define Timer_Clock_Source_prescaling_256         (uint8_t)(0b100<<CS00)
#define Timer_Clock_Source_prescaling_1024        (uint8_t)(0b101<<CS00)
#define Timer_Clock_Source_External_Falling_edge  (uint8_t)(0b110<<CS00)
#define Timer_Clock_Source_External_rising_edge   (uint8_t)(0b111<<CS00)

//-------------------------------------
//     @ref IRQ_Enabel_define
//-------------------------------------
#define IRQ_Enable_Non                            (uint8_t)(0)
#define IRQ_Enable_OCIE0                          (uint8_t)(1<<OCIE0)
#define IRQ_Enable_TOIE0                          (uint8_t)(1<<TOIE0)
#define IRQ_Enable_OCIE2                          (uint8_t)(1<<OCIE2)
#define IRQ_Enable_TOIE2                          (uint8_t)(1<<TOIE2)

/* ======================================================================= */
/* ================= APIs Support by "MCAL Timer Driver ================== */
/* ======================================================================= */

void MACL_Timer_INit                              (Timer_Config_t* timer_cfg);
void MACL_Timer_GetCounterValue                   (uint8_t* TicksNumber);
void MACL_Timer_SetComperValue                    (uint8_t TicksNumber);
void MACL_Timer_PMWDutyCycle                      ( uint8_t DutyCycle); 


#endif /*TIMER_H_ */ 
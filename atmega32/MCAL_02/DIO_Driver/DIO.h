/*
 * DIO.h
 *
 * Created: 9/17/2023 6:35:24 PM
 *  Author: Manal Nabil Donia
 */ 


#ifndef DIO_H_
#define DIO_H_

/* ======================================================================= */
/* ============================= INCLUDES ================================ */
/* ======================================================================= */

#include "../../UTILITIES_02/TYPES.h"
#include "../../UTILITIES_02/Register.h"

/* ======================================================================= */
/* =============================== Macros ================================ */
/* ======================================================================= */

#define PORT_A  'A'
#define PORT_B  'B'
#define PORT_C  'C'
#define PORT_D  'D'

#define NULL ((void*)0

#define PORT_LOW  0x0
#define PORT_HIGH 0xff

#define OUTPUT_PORT 0xff
#define INPUT_PORT  0x0


/* ======================================================================= */
/* ========================= MACO_LIKE_FUNCTION ========================== */
/* ======================================================================= */

#define SET_BIT(reg,bit)  reg|=(1<<bit)
#define CLR_BIT(reg,bit)  reg&=(~(1<<bit))
#define TOG_BIT(reg,bit)  reg^=(1<<bit)
#define GET_BIT(reg,bit)  (reg&(1<<bit))>>bit
#define TOG_PORT(reg)     reg^=0xff

/* ======================================================================= */
/* ============================= DATA_TYPE =============================== */
/* ======================================================================= */

typedef enum{
	DIO_NOT_OK = 0,
	DIO_OK
	}Std_ReturnType_t;
	
typedef enum{
	OUTPUT_PIN = 0,
	INPUT_PIN
	}PIN_DIRECTION;
	
typedef enum{
	LOW_LOGIC = 0,
	HIGH_LOGIC
	}PIN_LOGIC;
	
typedef enum{
	PIN0 = 0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7 
	}PIN_REGISTER;
	
/* ======================================================================= */
/* ================== APIs Support by "MCAL Dio Driver =================== */
/* ======================================================================= */
	
	

Std_ReturnType_t DIO_enumSetPinDirection    (uint8_t port , uint8_t pin , uint8_t direction);
Std_ReturnType_t DIO_enumWritePin           (uint8_t port , uint8_t pin , uint8_t logic);
Std_ReturnType_t DIO_enumReadPin            (uint8_t port , uint8_t pin , uint8_t * logic);
Std_ReturnType_t DIO_enumTogglePin          (uint8_t port , uint8_t pin );
Std_ReturnType_t DIO_enumSetPortHigh        (uint8_t port);
Std_ReturnType_t DIO_enumSetPortLow         (uint8_t port);
Std_ReturnType_t DIO_enumSetPortOutput      (uint8_t port);
Std_ReturnType_t DIO_enumSetPortInput       (uint8_t port);
Std_ReturnType_t DIO_enumTogglePort         (uint8_t port);
Std_ReturnType_t DIO_enumSetPort            (uint8_t port , uint8_t value);


#endif /* DIO_H_ */
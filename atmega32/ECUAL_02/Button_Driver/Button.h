/*
 * Butten.h
 *
 * Created: 9/18/2023 12:38:13 AM
 *  Author: Manal Nabil Donia
 */ 


#ifndef BUTTEN_H_
#define BUTTEN_H_

/*************INCLUDES*************/
//#include <util/delay.h>

#include "../../MCAL/DIO/DIO.h"

/*************MACRO*************/

#define BUTTON_NOT_PRESSED  0
#define BUTTON_PRESSED      1

/*************DATA_TYPE*************/

typedef enum
{
	Int_PULL_UP = 0,
	Ext_PULL_UP,
	Ext_PULL_DOWN,
	FLOATING
	}Pull_state;
	
typedef struct
{
	uint8_t Pin;
	uint8_t Port;
	uint8_t Pullup_state;
	}Button_Config_t;

/*************FUNCTIONS*************/

void BUTTON_INIT              (Button_Config_t Butten_CFG);
uint8_t GET_Button_Pressed    (Button_Config_t Butten_CFG);

#endif /* BUTTEN_H_ */
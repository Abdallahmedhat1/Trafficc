/*
 * APP.h
 *
 * Created: 12/3/2022 12:41:20 PM
 *  Author: abdallah medhat
 */ 


#ifndef APP_H_
#define APP_H_

#include "STD_TYPES.h"
typedef enum
{
	NORMAL_MODE,
	PEDSTRAIN_MODE
	}MODE_T;

void init(void);

uint8 Start_App(void);

uint8 pedestrain_mode(void);
uint8 App_Finish(void);

void INT0_ISR(void);

#endif /* APP_H_ */
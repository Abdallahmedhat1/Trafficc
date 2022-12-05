/*
 * TIMER0_PROGRAM.c
 *
 * Created: 11/2/2022 5:07:33 PM
 *  Author: ABDALLAH MEDHAT
 */ 
/*include Lib Files*/
#include <math.h>
#include "STD_TYPES.h"
#include "Macros.h"

/*include important files*/
#include "TIMER0_INTERFACE.h"
#include "TIMER0_REGISTER.h"


void TIMER_voidTimer0Init(void)
{
	/*Normal mode to TIMER0*/
	CLEAR_BIT(*TCCR0,TCCR0_WGM00);
	CLEAR_BIT(*TCCR0,TCCR0_WGM01);
}

void TIMER_voidTimer0Delay(uint32 Copy_u32Delay_ms)
{
	CLEAR_BIT(*TCCR0, TCCR0_CS00);
	
	CLEAR_BIT(*TCCR0, TCCR0_CS01);
	SET_BIT(*TCCR0, TCCR0_CS02);

	float64 Local_f64TickTime= 256.0/10000.0;
	float64 Local_f64DelayMax= Local_f64TickTime *(1<<8);
	uint32 Local_u32TimerInitValue;
	uint32 Local_u32NumOV;
	uint32 Local_u32OverflowCounter = 0;

	if(Copy_u32Delay_ms < Local_f64DelayMax)
	{
		Local_u32TimerInitValue = (Local_f64DelayMax - Copy_u32Delay_ms)/Local_f64TickTime;
		/*Set initial timer value*/
		*TCNT0 = Local_u32TimerInitValue;
		/*Busy waiting*/
		while(READ_BIT(*TIFR,TIFR_TOV0) == 0);
		/*Clear the flag*/
		SET_BIT(*TIFR,TIFR_TOV0);

	}
	else if(Copy_u32Delay_ms == Local_f64DelayMax)
	{
		/*Set initial timer value*/
		*TCNT0 = 0x00;
		/*Busy waiting*/
		while(READ_BIT(*TIFR,TIFR_TOV0) == 0);
		/*Clear the flag*/
		SET_BIT(*TIFR,TIFR_TOV0);
	}
	else
	{
		Local_u32NumOV = ceil(Copy_u32Delay_ms/Local_f64DelayMax);
		Local_u32TimerInitValue =(1<<8) - ((Copy_u32Delay_ms/Local_f64TickTime) / Local_u32NumOV);
		/*Set initial timer value*/
		*TCNT0 = Local_u32TimerInitValue;

		while(Local_u32OverflowCounter < Local_u32NumOV)
		{
			/*Busy waiting*/
			while(READ_BIT(*TIFR,TIFR_TOV0) == 0);
			/*Clear the flag*/
			SET_BIT(*TIFR,TIFR_TOV0);

			Local_u32OverflowCounter++;
		}

	}

	/*Timer Stop*/
	*TCCR0 = 0x00;
}
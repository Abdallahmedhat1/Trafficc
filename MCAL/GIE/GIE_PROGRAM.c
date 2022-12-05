/*
 * GIE_PROGRAM.c
 *
 * Created: 11/2/2022 4:50:16 PM
 *  Author: ahmed
 */ 
#include "STD_TYPES.h"
#include "Macros.h"

#include "GIE_INTERFACE.h"
#include "GIE_REGISTER.h"
/*************************************************************************/

void GIE_voidEnable(void)
{
	SET_BIT(*SREG,SREG_I);
}

void GIE_voidDisable(void)
{
	 CLEAR_BIT(*SREG,SREG_I);
}
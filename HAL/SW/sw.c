/*
 * sw.c
 *
 * Created: 9/29/2021 5:28:26 PM
 *  Author: ahmed
 */ 


#include "sw.h"
#include "../../MCAL/DIO/atmega32a_conf.h"
#include <util/delay.h>
#include "Macros.h"
#define DEBOUNCE_PERIOD (20U)

Dio_PinStateEnum_t Sw_PrevState = SW_RELEASED;
void Sw_init(volatile uint8 *Sw_Reg, SwEnumt_t Sw_no)
{
	Dio_ChannelDirectionSet   (Sw_Reg, Sw_no, DIO_INPUT);
}
Sw_StateEnum_t Sw_StateGet(volatile uint8 *Sw_Reg, SwEnumt_t Sw_no)
{
	Sw_StateEnum_t LocalSwState = SW_RELEASED;
	
 LocalSwState=READ_BIT(*Sw_Reg,Sw_no);
if(LocalSwState==1)
{
	return 1;
}
else
{
	return 0;
}
}
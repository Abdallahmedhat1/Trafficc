/*
 * DIO.c
 *
 * Created: 9/21/2021 1:56:52 PM
 *  Author: abdallah medhat
 */ 
#include "DIO.h"

#include "Macros.h"

#include "STD_TYPES.h"

#include "atmega32a_conf.h"



void Dio_ChannelDirectionSet(volatile uint8 * Port_reg, Dio_PinEnum_t Channel,Dio_PinDirEnum_t Direction)

{



	switch(Direction)

	{

		case DIO_INPUT:

		CLEAR_BIT(*Port_reg,Channel);

		break;

		case DIO_OUTPUT:

		SET_BIT(*Port_reg,Channel);

		break;

		default:

		break;

	}

}



Dio_PinStateEnum_t Dio_ChannelRead(volatile uint8 * Port_reg, Dio_PinEnum_t Channel)

{

	Dio_PinStateEnum_t u8LocalPinValue = READ_BIT(*Port_reg,Channel);

	return (u8LocalPinValue);

}



void Dio_ChannelWrite(volatile uint8 * Port_reg, Dio_PinEnum_t Channel, Dio_PinStateEnum_t State)

{

	switch(State)

	{

		case DIO_LOW:

		CLEAR_BIT(*Port_reg,Channel);

		break;

		case DIO_HIGH:

		SET_BIT(*Port_reg,Channel);

		break;

		default:

		break;

	}

}

void Dio_ChannelToggle(volatile uint8 * Port_reg, Dio_PinEnum_t Channel)

{

	TOGGLE_BIT(*Port_reg,Channel);

}



void Dio_PortWrite(volatile uint8 * Port_reg, uint8 Value)

{

	*Port_reg = Value;

}



uint8 Dio_PortRead(volatile uint8 * Port_reg)

{

	uint8 u8LocalPortValue = *Port_reg;

	return u8LocalPortValue;

}
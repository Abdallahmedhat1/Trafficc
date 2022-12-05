/*
 * DIO.h
 *
 * Created: 9/18/2021 10:33:21 PM
 *  Author: abdallah
 */ 

#include "STD_TYPES.h"
#ifndef DIO_H_
#define DIO_H_

typedef enum
{
	
DIO_PIN0,
DIO_PIN1,
DIO_PIN2,
DIO_PIN3,	
DIO_PIN4,
DIO_PIN5,
DIO_PIN6,
DIO_PIN7	
	
  	}Dio_PinEnum_t;
	  
typedef enum
{
DIO_LOW,
DIO_HIGH
	
	}Dio_PinStateEnum_t;
typedef enum
{
DIO_INPUT,
DIO_OUTPUT	
	}Dio_PinDirEnum_t;
void Dio_ChannelDirectionSet(volatile uint8 * Port_reg, Dio_PinEnum_t Channel,Dio_PinDirEnum_t Direction);
Dio_PinStateEnum_t Dio_ChannelRead(volatile uint8 * Port_reg, Dio_PinEnum_t Channel);
void Dio_ChannelWrite(volatile uint8 * Port_reg,Dio_PinEnum_t Channel,Dio_PinStateEnum_t state);
void Dio_ChannelToggle(volatile uint8 * Port_reg,Dio_PinEnum_t Channel);
void Dio_PortWrite(volatile uint8 * Port_reg,uint8 Value);
uint8 Dio_PortRead(volatile uint8 * Port_reg);	


#endif /* DIO_H_ */








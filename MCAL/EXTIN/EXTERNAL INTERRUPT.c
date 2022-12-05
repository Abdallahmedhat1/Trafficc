/*
 * EXTERNAL_INTERRUPT.c
 *
 * Created: 3/12/2022 6:20:39 PM
 *  Author: abdallah medhat 
 */ 
#include "EXTERNAL INTERRUPT.h"
#include "Macros.h"
#include "atmega32a_conf.h"
#include "STD_TYPES.h"

#define  NULL 0
void (*EXTI_pvInt0Func)(void)= NULL;

void ExternalInterruptEnable(ExternalInterruptSourceEnum_t source, ExternalInterruptModeEnum_t mode)
{
	switch(source)
	{
		case EXT_INT0:
		/* 1- Configure INT0 mode */
		switch(mode)
		{
			case LOW_LEVEL_MODE:
			CLEAR_BIT(*MCU_CTRL_REG, INT0_ISC00);
			CLEAR_BIT(*MCU_CTRL_REG, INT0_ISC01);
			break;
			case EDGE_TRIGGERED_MODE:
			SET_BIT(*MCU_CTRL_REG, INT0_ISC00);
			CLEAR_BIT(*MCU_CTRL_REG, INT0_ISC01);
			break;
			case FALLING_EDGE_MODE:
			CLEAR_BIT(*MCU_CTRL_REG, INT0_ISC00);
			SET_BIT(*MCU_CTRL_REG, INT0_ISC01);
			break;
			case RISING_EDGE_MODE:
			SET_BIT(*MCU_CTRL_REG, INT0_ISC00);
			SET_BIT(*MCU_CTRL_REG, INT0_ISC01);
			break;
		}
		/* 2- Enable INT0 */
		SET_BIT(*GENERAL_INTERRUPT_CTRL_REG, INT0_ENABLE_BIT);
		break;
		
		case EXT_INT1:
		/* 1- Configure INT1 mode */
		switch(mode)
		{
			case LOW_LEVEL_MODE:
			CLEAR_BIT(*MCU_CTRL_REG, INT1_ISC10);
			CLEAR_BIT(*MCU_CTRL_REG, INT1_ISC11);
			break;
			case EDGE_TRIGGERED_MODE:
			SET_BIT(*MCU_CTRL_REG, INT1_ISC10);
			CLEAR_BIT(*MCU_CTRL_REG, INT1_ISC11);
			break;
			case FALLING_EDGE_MODE:
			CLEAR_BIT(*MCU_CTRL_REG, INT1_ISC10);
			SET_BIT(*MCU_CTRL_REG, INT1_ISC11);
			break;
			case RISING_EDGE_MODE:
			SET_BIT(*MCU_CTRL_REG, INT1_ISC10);
			SET_BIT(*MCU_CTRL_REG, INT1_ISC11);
			break;
		}
		/* 2- Enable INT1 */
		SET_BIT(*GENERAL_INTERRUPT_CTRL_REG, INT1_ENABLE_BIT);
		break;
		
		case EXT_INT2:
		/* 1- Configure INT2 mode */
		switch(mode)
		{
			case FALLING_EDGE_MODE:
			CLEAR_BIT(*MCU_CTRL_STATUS_REG, INT2_ISC2);
			break;
			case RISING_EDGE_MODE:
			SET_BIT(*MCU_CTRL_STATUS_REG, INT2_ISC2);
			break;
		}
		/* 2- Enable INT2 */
		SET_BIT(*GENERAL_INTERRUPT_CTRL_REG, INT2_ENABLE_BIT);
		break;
		
		default:
		break;
	}
}


void ExternalInterruptDisable(ExternalInterruptSourceEnum_t source)
{
	switch(source)
	{
		case EXT_INT0:
		CLEAR_BIT(*GENERAL_INTERRUPT_CTRL_REG, INT0_ENABLE_BIT);
		break;
		case EXT_INT1:
		CLEAR_BIT(*GENERAL_INTERRUPT_CTRL_REG, INT1_ENABLE_BIT);
		break;
		case EXT_INT2:
		CLEAR_BIT(*GENERAL_INTERRUPT_CTRL_REG, INT2_ENABLE_BIT);
		break;
		default:
		break;
	}
}


void GlobalInterruptsStateSet(GlobalInterruptStateEnum_t state)
{
	switch(state)
	{
		case GLOBAL_INTERRUPT_DISABLE:
		CLEAR_BIT(*AVR_STATUS_REG_I_BIT, GLOBAL_INTERRUPTS_ENABLE_BIT);
		break;
		case GLOBAL_INTERRUPT_ENABLE:
		SET_BIT(*AVR_STATUS_REG_I_BIT, GLOBAL_INTERRUPTS_ENABLE_BIT);
		break;
		default:
		break;
	}
}


uint8 EXTI_voidInt0_SetCallBack(void (*Copy_vpInt0Func)(void))
{
	uint8 Local_u8ErrorState=OK;
	if(Copy_vpInt0Func != NULL)
	{
		EXTI_pvInt0Func = Copy_vpInt0Func;
	}
	else
	{
		Local_u8ErrorState=NULL_POINTER;
	}
	return Local_u8ErrorState;
}
/*INT_0 ISR*/
void __vector_1 (void)  __attribute__((signal));
void __vector_1 (void)
{
	if(EXTI_pvInt0Func !=NULL){
		EXTI_pvInt0Func();
	}
	else
	{
		
	}
}

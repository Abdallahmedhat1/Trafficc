/*
 * EXTERNAL_INTERRUPT.h
 *
 * Created: 10/3/2021 6:19:58 PM
 *  Author: ahmed
 */ 



#ifndef EXTERNAL_INTERRUPTS_H_
#define EXTERNAL_INTERRUPTS_H_
#include "STD_TYPES.h"

typedef enum
{
	EXT_INT0,
	EXT_INT1,
	EXT_INT2
}ExternalInterruptSourceEnum_t;

typedef enum
{
	RISING_EDGE_MODE,
	FALLING_EDGE_MODE,
	EDGE_TRIGGERED_MODE,
	LOW_LEVEL_MODE
}ExternalInterruptModeEnum_t;

typedef enum
{
	GLOBAL_INTERRUPT_DISABLE,
	GLOBAL_INTERRUPT_ENABLE
}GlobalInterruptStateEnum_t;


#define INT0_ISC00            (0U)
#define INT0_ISC01            (1U)
#define INT1_ISC10            (2U)
#define INT1_ISC11            (3U)
#define INT2_ISC2             (6U)    //el arkam de rkam el bit

#define INT0_ENABLE_BIT       (6U)
#define INT1_ENABLE_BIT       (7U)
#define INT2_ENABLE_BIT       (5U)

#define GLOBAL_INTERRUPTS_ENABLE_BIT  (7U)    //I-BIT


void ExternalInterruptEnable(ExternalInterruptSourceEnum_t source, ExternalInterruptModeEnum_t mode);
void ExternalInterruptDisable(ExternalInterruptSourceEnum_t source);
void GlobalInterruptsStateSet(GlobalInterruptStateEnum_t state);
uint8 EXTI_voidInt0_SetCallBack(void (*Copy_vpInt0Func)(void));



#endif /* EXTERNAL_INTERRUPTS_H_ */
/*
 * atmega32a_con.h
 *
 * Created: 9/18/2021 8:14:43 PM
 *  Author: ahmed
 */ 


#ifndef ATMEGA32A_CONF_H_
#define ATMEGA32A_CONF_H_

#include "STD_TYPES.h"
#define  F_CPU (16000000U)
#define  PORTA_DIR_REG       ((uint8 volatile*)0x3AU)
#define  PORTA_OUT_REG       ((uint8 volatile*)0x3BU)
#define  PORTA_INP_REG       ((uint8 volatile*)0x39U)


#define  PORTB_DIR_REG       ((uint8 volatile*)0x37U)
#define  PORTB_OUT_REG       ((uint8 volatile*)0x38U)
#define  PORTB_INP_REG       ((uint8 volatile*)0x36U)


#define  PORTC_DIR_REG       ((uint8 volatile*)0x34U)
#define  PORTC_OUT_REG       ((uint8 volatile*)0x35U)
#define  PORTC_INP_REG       ((uint8 volatile*)0x33U)

#define  PORTD_DIR_REG       ((uint8 volatile*)0x31U)
#define  PORTD_OUT_REG       ((uint8 volatile*)0x32U)
#define  PORTD_INP_REG       ((uint8 volatile*)0x30U)

#define   MCU_CTRL_REG              ((volatile uint8*) 0x55)
#define   MCU_CTRL_STATUS_REG       ((volatile uint8*) 0x54)
#define  GENERAL_INTERRUPT_CTRL_REG ((volatile uint8*) 0x5B)
#define  AVR_STATUS_REG_I_BIT       ((volatile uint8*) 0X5A)










#endif /* ATMEGA32A CON_H_ */
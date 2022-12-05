/*
 * PORT_PROGRAM.c
 *
 * Created: 11/2/2022 4:58:21 PM
 *  Author: ahmed
 */ 
#include "STD_TYPES.h"

#include "PORT_CONFIG.h"
#include "PORT_PRIVATE.h"
#include "PORT_INTERFACE.h"
#include "atmega32a_conf.h"



/*set all PORTS Direction*/
void PORT_voidInit(void){


	*PORTA_DIR_REG  =PORTA_DIR;
	*PORTB_DIR_REG  =PORTB_DIR;
	*PORTC_DIR_REG  =PORTC_DIR;
	*PORTD_DIR_REG  =PORTD_DIR;

	*PORTA_OUT_REG  =PORTA_INITIAL_VALUE;
	*PORTB_OUT_REG =PORTB_INITIAL_VALUE;
	*PORTC_OUT_REG  =PORTC_INITIAL_VALUE;
	*PORTD_OUT_REG  =PORTD_INITIAL_VALUE;

}
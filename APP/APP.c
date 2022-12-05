/*
 * APP.c
 *
 * Created: 12/3/2022 12:41:35 PM
 *  Author: abdallah medhat
 */ 
#include "../LIB/STD_TYPES.h"
#include "../LIB/Macros.h"
/*MCAL includes */
#include "../MCAL/DIO/DIO.h"
#include "../MCAL/DIO/atmega32a_conf.h"
#include "../MCAL/PORT/PORT_INTERFACE.h"
#include "../MCAL/EXTIN/EXTERNAL INTERRUPT.h"
#include "../MCAL/GIE/GIE_INTERFACE.h"
#include "../MCAL/TIMER0/TIMER0_INTERFACE.h"
/*HAL includes */
#include "../HAL/LEDS/LEDS.h"
#include "../HAL/SW/sw.h"

#include "APP.h"



MODE_T modeState = NORMAL_MODE;

void init(void)
{
	PORT_voidInit();
	Dio_PortWrite(PORTA_DIR_REG,0X07);
	Dio_PortWrite(PORTC_DIR_REG,0X07);
	TIMER_voidTimer0Init();
	ExternalInterruptEnable(EXT_INT0,FALLING_EDGE_MODE);
	GlobalInterruptsStateSet(GLOBAL_INTERRUPT_ENABLE);
	EXTI_voidInt0_SetCallBack(&INT0_ISR);
	Sw_init(PORTD_DIR_REG,DIO_PIN2);
GIE_voidEnable();
	
}

uint8 Start_App(void)
{
	uint8 error_state;
	switch(modeState)
	{
		//in case normal mode
		case NORMAL_MODE:
		//turn on car led
		set_led(PORTA_OUT_REG,DIO_PIN0,led_on);
		TIMER_voidTimer0Delay(5000);
		//turn off car led 
		set_led(PORTA_OUT_REG,DIO_PIN0,led_off);
		// turn on car green led
		set_led(PORTA_OUT_REG,DIO_PIN1,led_on);
		TIMER_voidTimer0Delay(5000);
	    //turn off car  green led 
		set_led(PORTA_OUT_REG,DIO_PIN1,led_off);
		//blanking car yellow
		for(uint8 count=0;count<5;count++)
		{
			set_led(PORTA_OUT_REG,DIO_PIN2,led_on);
			TIMER_voidTimer0Delay(500);
			set_led(PORTA_OUT_REG,DIO_PIN2,led_off);
			TIMER_voidTimer0Delay(500);
		}
		break;
		// in case pedestrain_mode
		case PEDSTRAIN_MODE:
		 pedestrain_mode();
		 break;
		 default:
		 error_state=1;
		 break;
		
	}
	modeState = NORMAL_MODE ;
	Start_App();

	//return error state
	return error_state;
}

uint8 pedestrain_mode(void)
{
uint8 error_state=0;
  //turn off all leds
	set_led(PORTA_OUT_REG,DIO_PIN0,led_off);
	set_led(PORTA_OUT_REG,DIO_PIN1,led_off);
	set_led(PORTA_OUT_REG,DIO_PIN2,led_off);
	set_led(PORTC_OUT_REG,DIO_PIN0,led_off);
	set_led(PORTC_OUT_REG,DIO_PIN1,led_off);
	set_led(PORTC_OUT_REG,DIO_PIN2,led_off);
	//read car led 
	if(READ_BIT(*PORTA_OUT_REG,DIO_PIN0)==1)
	{
		// turn on pedstrain_green_led
		set_led(PORTC_OUT_REG,DIO_PIN1,led_on);
		//turn on car_red_led
		set_led(PORTA_OUT_REG,DIO_PIN0,led_on);
		
		TIMER_voidTimer0Delay(5000);
		//turn of both car red and green bed_strain
		set_led(PORTA_OUT_REG,DIO_PIN0,led_off);
		set_led(PORTC_OUT_REG,DIO_PIN1,led_off);
	}
		//if car green or yellow leds active
		else if((READ_BIT(*PORTA_OUT_REG,DIO_PIN1)==1)||READ_BIT(*PORTA_OUT_REG,DIO_PIN2)==1)
		//blinking for 5 sec to start pedsrain_mode
		{
			for(uint8 count=0;count<5;count++)
			
			{
				set_led(PORTC_OUT_REG,DIO_PIN2,led_on);
				set_led(PORTA_OUT_REG,DIO_PIN2,led_on);
				TIMER_voidTimer0Delay(500);
				set_led(PORTC_OUT_REG,DIO_PIN2,led_off);
				set_led(PORTA_OUT_REG,DIO_PIN2,led_off);
				TIMER_voidTimer0Delay(500);
				
			}
			//turn off all yellow led
			set_led(PORTC_OUT_REG,DIO_PIN2,led_off);
			set_led(PORTA_OUT_REG,DIO_PIN2,led_off);
			//turn on ped_strain green led to pass
			set_led(PORTC_OUT_REG,DIO_PIN1,led_on);
			set_led(PORTA_OUT_REG,DIO_PIN0,led_on);
			TIMER_voidTimer0Delay(5000);
			//turnoff car red and green ped_strain
			set_led(PORTC_OUT_REG,DIO_PIN1,led_off);
			set_led(PORTA_OUT_REG,DIO_PIN0,led_off);
			
		}
	else
	{
		error_state=1;
	}
	 App_Finish();
	return error_state;
}
uint8 App_Finish(void)
{
	uint8 error_state=0;
	//blinking yellow leds to stop pede_strain
	for (uint8 count=0;count<5;count++)
	{
		set_led(PORTC_OUT_REG,DIO_PIN2,led_on);
		set_led(PORTA_OUT_REG,DIO_PIN2,led_on);
		TIMER_voidTimer0Delay(500);
		
		set_led(PORTC_OUT_REG,DIO_PIN2,led_off);
		set_led(PORTA_OUT_REG,DIO_PIN2,led_off);
		TIMER_voidTimer0Delay(500);
	}
	set_led(PORTC_OUT_REG,DIO_PIN2,led_off);
	set_led(PORTA_OUT_REG,DIO_PIN2,led_off);
	// back to normal mode
		set_led(PORTC_OUT_REG,DIO_PIN1,led_off);
		set_led(PORTC_OUT_REG,DIO_PIN0,led_on);
		set_led(PORTA_OUT_REG,DIO_PIN0,led_off);
		TIMER_voidTimer0Delay(5000);
		// turn off all leds
		set_led(PORTA_OUT_REG,DIO_PIN0,led_off);
		set_led(PORTA_OUT_REG,DIO_PIN1,led_off);
		set_led(PORTA_OUT_REG,DIO_PIN2,led_off);
		set_led(PORTC_OUT_REG,DIO_PIN0,led_off);
		set_led(PORTC_OUT_REG,DIO_PIN1,led_off);
		set_led(PORTC_OUT_REG,DIO_PIN2,led_off);
		modeState=NORMAL_MODE;
		Start_App();
		return error_state;
}

void INT0_ISR(void)
{
	
	modeState = PEDSTRAIN_MODE;
	Start_App();
}

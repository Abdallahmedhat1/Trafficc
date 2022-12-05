/*6
 * LEDS.c
 *
 * Created: 3/19/2022 5:29:23 PM
 *  Author: abdallah medhat
 */ 
#include "LEDS.h"
#include "DIO.h"
#include "MACROS.h"
void init_led(volatile uint8*led_reg,Led_Enum Channel)
{
	Dio_ChannelDirectionSet(led_reg,Channel,DIO_OUTPUT);
} 

void set_led(volatile uint8*led_reg,Led_Enum Channel,Led_state State)
{
	switch(State)
	{
	case led_off:
	clear_bit(*led_reg,Channel);
	break;
	case led_on:
	set_bit(*led_reg,Channel);
	break;
	case led_toggle:
	toggle_bit(*led_reg,Channel);
	break;
	default:
	break;	
		
	}
}
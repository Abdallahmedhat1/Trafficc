/*
 * LEDS.h
 *
 * Created: 3/19/2022 4:52:00 PM
 *  Author: ahmed
 */ 


#ifndef LEDS_H_
#define LEDS_H_
#include "DIO.h"
#define LED0_1_DIR_REG        (PORTC_DIR_REG)
#define LED0_1_OUT_REG        (PORTC_OUT_REG)
#define LED2_DIR_REG          (PORTD_DIR_REG)
#define LED2_OUT_REG          (PORTD_OUT_REG)

typedef enum
{
led0=DIO_PIN0,

led1=DIO_PIN1,

led2=DIO_PIN2	
	}Led_Enum;
	
typedef enum
{
led_off,
led_on,
led_toggle	
		
}Led_state;

void init_led(volatile uint8*led_reg,Led_Enum Channel);
void set_led(volatile uint8*led_reg,Led_Enum Channel,Led_state State);



#endif /* LEDS_H_ */
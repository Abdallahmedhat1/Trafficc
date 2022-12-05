/*
 * TIMER0_INTERFACE.h
 *
 * Created: 11/2/2022 5:06:01 PM
 *  Author: ahmed
 */ 


#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_



/*
 * by this function we can initialize Timer 0 in normal mode.
 * parameter: void
*/
void TIMER_voidTimer0Init(void);

/*
 * by this function we can make a delay with 256 pre-scaler.
 * parameter: Copy_u32Delay_ms.
*/
void TIMER_voidTimer0Delay(uint32 Copy_u32Delay_ms);

#endif /* TIMER_INTERFACE_H_ */
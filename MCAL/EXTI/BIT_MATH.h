/*
 * BIT_MATH.h
 *
 * Created: 11/2/2022 4:20:06 PM
 *  Author: ABDALLAH MEDHAT
 */ 





#ifndef _BIT_MATH_H_
#define _BIT_MATH_H_

#define SETBIT(VAR,BITNO) (VAR) |=  (1 << (BITNO))
#define CLRBIT(VAR,BITNO) (VAR) &= ~(1 << (BITNO))
#define TOGBIT(VAR,BITNO) (VAR) ^=  (1 << (BITNO))
#define GETBIT(VAR,BITNO) (((VAR) >> (BITNO)) & 0x01)


#endif



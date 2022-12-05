/*
 * MACROS.h
 *
 * Created: 3/17/2022 10:29:37 PM
 *  Author: abdallah
 */ 


#ifndef MACROS_H_
#define MACROS_H_

#define set_bit(reg,bit)      (reg|=(1U<<bit))

#define clear_bit(reg,bit)    (reg&=~(1U<<bit))

#define toggle_bit(reg,bit)   (reg^=(1U<<bit))

#define read_bit(reg,bit)   ((reg & (1U<<bit)) >> bit) 

#endif /* MACROS_H_ */
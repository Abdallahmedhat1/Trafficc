/*
 * Macros
 *
 * Created: 9/18/2021 8:25:04 PM
 *  Author: abdallah medhat
 */ 


#ifndef Macros_H_
#define Macros_H_
#define SET_BIT(Reg,Bit_no)      (Reg|=(1U<<Bit_no))
#define CLEAR_BIT(Reg,Bit_no)    (Reg&=~(1U<<Bit_no))
#define TOGGLE_BIT(Reg,Bit_no)    (Reg^= (1U<<Bit_no))
#define READ_BIT(Reg,Bit_no)      ((Reg & (1U<<Bit_no)) >> Bit_no)






#endif /* MaCROS_H_ */
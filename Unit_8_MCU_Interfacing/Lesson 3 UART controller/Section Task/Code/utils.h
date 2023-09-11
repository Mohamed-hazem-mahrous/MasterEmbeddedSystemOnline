/*
 * utils.h
 *
 * Created: 9/9/2023 7:44:19 PM
 *  Author: Mohamed
 */ 


#ifndef UTILS_H_
#define UTILS_H_

#define Set_Bit(Reg, Bit) (Reg |= (1<<Bit))

#define Reset_Bit(Reg, Bit) (Reg &= ~(1<<Bit))

#define Toggle_Bit(Reg, Bit) (Reg ^= (1<<Bit))

#define Read_Bit(Reg, Bit) ((Reg>>Bit)&1)



#endif /* UTILS_H_ */
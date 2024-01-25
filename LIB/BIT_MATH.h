#ifndef BIT_MATH_H
#define BIT_MATH_H


#define SET_BIT(num,bit) num=num|(1<<bit)
#define CLR_BIT(num,bit) num=num&(~(1<<bit))
#define GET_BIT(num,bit) (num >> bit) & 0x01
#define TOOGLE_BIT(num,bit)  num=num^(1<<bit)
#define CONC(b7,b6,b5,b4,b3,b2,b1,b0)   CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)

#define CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)  0b##b7##b6##b5##b4##b3##b2##b1##b0



#endif

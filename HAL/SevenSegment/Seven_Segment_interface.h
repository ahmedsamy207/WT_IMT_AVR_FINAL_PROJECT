/*******************************************************************/
/* Author  : Ahmed Samy                                                */
/* SWC     : Seven_Segment                                         */
/* Version : 1.0                                                   */
/* Date    : 10 Dec 2023                                           */
/*******************************************************************/
#ifndef SEVEN_SEGMENT_INTERFACE_H_
#define SEVEN_SEGMENT_INTERFACE_H_


#define COMMON_CATHODE		1
#define COMMON_ANODE		0



#define PORT_A		0
#define PORT_B		1
#define PORT_C		2
#define PORT_D		3

void SevSeg_voidDisplay(u8 PortNum, u8 u8NumberCpy);

#endif

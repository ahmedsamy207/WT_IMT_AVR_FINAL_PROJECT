#ifndef ULTRASONIC_INTERFACE_H
#define ULTRASONIC_INTERFACE_H



void ULTRASONIC_voidInit(void);
void ULTRASONIC_voidTrigger(void);
u16 ULTRASONIC_u16GetDistance(void);
void ULTRASONIC_voidEdgeProcessing(void);
#endif

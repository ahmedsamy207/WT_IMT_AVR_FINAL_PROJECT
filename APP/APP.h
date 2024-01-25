/*****************************************************************/
/* Author  : Ahmed Samy                                              */
/* SWC     : AVR Project (RC and ObstacleAvoiding Robot)                                                */
/* Version : 1.0                                                 */
/* Date    : 20 Jan 2024                                         */
/*****************************************************************/

#ifndef APP_APP_H_
#define APP_APP_H_

/*********************************************************** Configuration *****************************************************************/
/* Configuration L298 Port and pits */
#define Robot_u8_MOTOR_DRIVER_L298_PORT            DIO_u8_PORTC
#define Robot_u8_MOTOR_DRIVER_L298_IN1             DIO_u8_PIN1
#define Robot_u8_MOTOR_DRIVER_L298_IN2             DIO_u8_PIN2
#define Robot_u8_MOTOR_DRIVER_L298_IN3             DIO_u8_PIN3
#define Robot_u8_MOTOR_DRIVER_L298_IN4             DIO_u8_PIN4
/* Init modes Speeds*/
#define Robot_u8_INIT_SPEED                        50 	/* 50 % */
#define Robot_u8_ObstacleAvoidingMode_SPEED        40  	/* 40 % */
#define Robot_u8_BluetoothMode_SPEED        	   60  	/* 60 % */
/* Init control modes*/
#define BluetoothMode                       		1
#define ObstacleAvoidingMode       			 		0

/*********************************************************** Prototypes *****************************************************************/
void Robot_voidInit(void);
void Robot_voidSpeed(u8 Copy_u8SpeedIntinsty);
void Robot_voidStop(void);
void Robot_voidForward(void);
void Robot_voidBackward(void);
void Robot_voidLeft(void);
void Robot_voidRight(void);
void Robot_voidStep(void);
void Robot_voidComparisonlogic(u16 Copy_u16LeftObject,u16 Copy_u16RightObject);
void Robot_voidObstacleAvoidingMode(void);
void Robot_voidBluetoothRCMode(void);

#endif /* APP_APP_H_ */

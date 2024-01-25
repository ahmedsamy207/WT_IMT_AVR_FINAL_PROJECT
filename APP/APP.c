/*****************************************************************/
/* Author  : Ahmed Samy                                              */
/* SWC     : AVR Project (RC and ObstacleAvoiding Robot)                                                */
/* Version : 1.0                                                 */
/* Date    : 20 Jan 2024                                         */
/*****************************************************************/
/* LIB */
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#define  F_CPU 8000000UL
#include <util/delay.h>
/* MCAL */
#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/UART/UART_interface.h"
#include "../MCAL/TIMER/TIMER_interface.h"
/* HAL */
#include "../HAL/SERVO/SERVO_interface.h"
#include "../HAL/ULTRASONIC/ULTRASONIC_interface.h"
#include "../HAL/BUZZER/BUZZER_interface.h"
#include "../HAL/SevenSegment/Seven_Segment_interface.h"
/* APP */
#include "APP.h"

/****************************************************************** Speed ******************************************************************/
void Robot_voidSpeed(u8 Copy_u8SpeedIntinsty)
{
	/* Speed control by Timer0 and Timer2 */
	TIMER_voidTimer0GeneratePWM(Copy_u8SpeedIntinsty);
	TIMER_voidTimer2GeneratePWM(Copy_u8SpeedIntinsty);
}
/************************************************************* Directions ******************************************************************/
void Robot_voidStop(void)
{
	/* Stop motors */
	DIO_voidSetPinValue(Robot_u8_MOTOR_DRIVER_L298_PORT,Robot_u8_MOTOR_DRIVER_L298_IN1,DIO_u8_LOW);
	DIO_voidSetPinValue(Robot_u8_MOTOR_DRIVER_L298_PORT,Robot_u8_MOTOR_DRIVER_L298_IN2,DIO_u8_LOW);
	DIO_voidSetPinValue(Robot_u8_MOTOR_DRIVER_L298_PORT,Robot_u8_MOTOR_DRIVER_L298_IN3,DIO_u8_LOW);
	DIO_voidSetPinValue(Robot_u8_MOTOR_DRIVER_L298_PORT,Robot_u8_MOTOR_DRIVER_L298_IN4,DIO_u8_LOW);
}
void Robot_voidForward(void)
{
	/* all motors forward */
	DIO_voidSetPinValue(Robot_u8_MOTOR_DRIVER_L298_PORT,Robot_u8_MOTOR_DRIVER_L298_IN1,DIO_u8_LOW);
	DIO_voidSetPinValue(Robot_u8_MOTOR_DRIVER_L298_PORT,Robot_u8_MOTOR_DRIVER_L298_IN2,DIO_u8_HIGH);
	DIO_voidSetPinValue(Robot_u8_MOTOR_DRIVER_L298_PORT,Robot_u8_MOTOR_DRIVER_L298_IN3,DIO_u8_LOW);
	DIO_voidSetPinValue(Robot_u8_MOTOR_DRIVER_L298_PORT,Robot_u8_MOTOR_DRIVER_L298_IN4,DIO_u8_HIGH);
}
void Robot_voidBackward(void)
{
	/* all motors Backward */
	DIO_voidSetPinValue(Robot_u8_MOTOR_DRIVER_L298_PORT,Robot_u8_MOTOR_DRIVER_L298_IN1,DIO_u8_HIGH);
	DIO_voidSetPinValue(Robot_u8_MOTOR_DRIVER_L298_PORT,Robot_u8_MOTOR_DRIVER_L298_IN2,DIO_u8_LOW);
	DIO_voidSetPinValue(Robot_u8_MOTOR_DRIVER_L298_PORT,Robot_u8_MOTOR_DRIVER_L298_IN3,DIO_u8_HIGH);
	DIO_voidSetPinValue(Robot_u8_MOTOR_DRIVER_L298_PORT,Robot_u8_MOTOR_DRIVER_L298_IN4,DIO_u8_LOW);
}
void Robot_voidLeft(void)
{
	/* Left motors forward and Right motors Backward */
	DIO_voidSetPinValue(Robot_u8_MOTOR_DRIVER_L298_PORT,Robot_u8_MOTOR_DRIVER_L298_IN1,DIO_u8_HIGH);
	DIO_voidSetPinValue(Robot_u8_MOTOR_DRIVER_L298_PORT,Robot_u8_MOTOR_DRIVER_L298_IN2,DIO_u8_LOW);
	DIO_voidSetPinValue(Robot_u8_MOTOR_DRIVER_L298_PORT,Robot_u8_MOTOR_DRIVER_L298_IN3,DIO_u8_LOW);
	DIO_voidSetPinValue(Robot_u8_MOTOR_DRIVER_L298_PORT,Robot_u8_MOTOR_DRIVER_L298_IN4,DIO_u8_HIGH);
}
void Robot_voidRight(void)
{
	/* Left motors Backward and Right motors forward */
	DIO_voidSetPinValue(Robot_u8_MOTOR_DRIVER_L298_PORT,Robot_u8_MOTOR_DRIVER_L298_IN1,DIO_u8_LOW);
	DIO_voidSetPinValue(Robot_u8_MOTOR_DRIVER_L298_PORT,Robot_u8_MOTOR_DRIVER_L298_IN2,DIO_u8_HIGH);
	DIO_voidSetPinValue(Robot_u8_MOTOR_DRIVER_L298_PORT,Robot_u8_MOTOR_DRIVER_L298_IN3,DIO_u8_HIGH);
	DIO_voidSetPinValue(Robot_u8_MOTOR_DRIVER_L298_PORT,Robot_u8_MOTOR_DRIVER_L298_IN4,DIO_u8_LOW);
}
void Robot_voidStep(void)
{
	/* After Stop take Step */
	Robot_voidSpeed(60);
	Robot_voidForward();
	_delay_ms(170);
}
/****************************************************************************************************************************************
 *                                                            Robot Modes                                                               *
 ****************************************************************************************************************************************/
/************************************************************ Obstacle Avoiding Mode ******************************************************/
/***************************************************************** Comparison *************************************************************/
void Robot_voidComparisonlogic(u16 Copy_u16LeftObject,u16 Copy_u16RightObject)
{
	/* Comparison between to direction and set Orientation*/
	if (Copy_u16LeftObject > Copy_u16RightObject){
		Robot_voidLeft();   // turn it on going left
		_delay_ms(350);
	}
	else if (Copy_u16RightObject > Copy_u16LeftObject){
		Robot_voidRight();  // the other right
		_delay_ms(350);
	}
	else{
		Robot_voidBackward();  // the other way
		_delay_ms(300);
		Robot_voidLeft();   // turn it on going left
		_delay_ms(500);
	}
}

void Robot_voidObstacleAvoidingMode(void)
{
	u16 Local_u16distance_L=0, Local_u16distance_F=0, Local_u16distance_R=0;
	u16 Local_u16Set = 20;
	/* Read distance -->if no object go forward */
	Local_u16distance_F = ULTRASONIC_u16GetDistance();
	if (Local_u16distance_F==0)
	{
		Robot_voidForward();
	}
	if (Local_u16distance_F > Local_u16Set)
	{
		Robot_voidForward();
	}
	else
	{
		BUZZER_voidBuzzer_Work(BUZZER_ON);
		_delay_ms(200);
		BUZZER_voidBuzzer_Work(BUZZER_OFF);
		Robot_voidStop();

		SERVO_voidTimer1ServoSetAngleOCR1B(0);
		_delay_ms(300);
		Local_u16distance_R = ULTRASONIC_u16GetDistance();
		if (Local_u16distance_R==0)
		{
			Local_u16distance_R=100;
		}
		_delay_ms(100);
		SERVO_voidTimer1ServoSetAngleOCR1B(170);
		_delay_ms(500);
		Local_u16distance_L = ULTRASONIC_u16GetDistance();
		if (Local_u16distance_L==0)
		{
			Local_u16distance_L=100;
		}
		_delay_ms(100);
		SERVO_voidTimer1ServoSetAngleOCR1B(90);
		_delay_ms(300);
		Robot_voidComparisonlogic(Local_u16distance_L, Local_u16distance_R);

	}
}

/************************************************************ RC Mode ******************************************************/
void Robot_voidBluetoothRCMode(void)
{
	u8 Local_u8Data = 0;
	Local_u8Data= UART_u8GetCharBlocking();
	switch (Local_u8Data) {
	case 'F':
		SevSeg_voidDisplay(DIO_u8_PORTA, 0);
		Robot_voidForward();
		break;
	case 'B':
		SevSeg_voidDisplay(DIO_u8_PORTA, 1);
		BUZZER_voidBuzzer_Work(BUZZER_ON);
		_delay_ms(200);
		BUZZER_voidBuzzer_Work(BUZZER_OFF);
		Robot_voidBackward();
		break;
	case 'L':
		SevSeg_voidDisplay(DIO_u8_PORTA, 3);
		Robot_voidLeft();
		break;
	case 'R':
		SevSeg_voidDisplay(DIO_u8_PORTA, 2);
		Robot_voidRight();
		break;
	case 'S':
		SevSeg_voidDisplay(DIO_u8_PORTA, 4);
		Robot_voidStop();
		break;
	default:
		break;
	}
}
/*********************************************************** Initialization ****************************************************************/
void Robot_voidInit(void)
{
	/***************************** INIT Mode Switch ****************************/
	DIO_voidSetPinDirection(DIO_u8_PORTB , DIO_u8_PIN0 , DIO_u8_PIN_INPUT);
	DIO_voidSetPinValue(DIO_u8_PORTB , DIO_u8_PIN0 , DIO_u8_HIGH);
	/************************** Init UART *************************************/
	UART_voidInit();
	DIO_voidSetPinDirection(DIO_u8_PORTD,DIO_u8_PIN0,DIO_u8_PIN_INPUT);
	DIO_voidSetPinDirection(DIO_u8_PORTD,DIO_u8_PIN1,DIO_u8_PIN_OUTPUT);
	/************************** Init Timer ************************************/
	TIMER_voidTimer0Init();
	DIO_voidSetPinDirection(DIO_u8_PORTB,DIO_u8_PIN3,DIO_u8_PIN_OUTPUT);
	TIMER_voidTimer2Init();
	DIO_voidSetPinDirection(DIO_u8_PORTD,DIO_u8_PIN7,DIO_u8_PIN_OUTPUT);
	/**************************** Init Servo **********************************/
	SERVO_voidTimer1InitOCR1B();
	SERVO_voidTimer1ServoSetAngleOCR1B(90);
	/**************************** Init ULTRASONIC *****************************/
	ULTRASONIC_voidInit();
	/***************************** INIT SPEAD ****************************/
	Robot_voidSpeed(Robot_u8_INIT_SPEED);
	/************************************** MOTOR DRIVER L298******************************************************/
	DIO_voidSetPinDirection(Robot_u8_MOTOR_DRIVER_L298_PORT,Robot_u8_MOTOR_DRIVER_L298_IN1,DIO_u8_PIN_OUTPUT);
	DIO_voidSetPinDirection(Robot_u8_MOTOR_DRIVER_L298_PORT,Robot_u8_MOTOR_DRIVER_L298_IN2,DIO_u8_PIN_OUTPUT);
	DIO_voidSetPinDirection(Robot_u8_MOTOR_DRIVER_L298_PORT,Robot_u8_MOTOR_DRIVER_L298_IN3,DIO_u8_PIN_OUTPUT);
	DIO_voidSetPinDirection(Robot_u8_MOTOR_DRIVER_L298_PORT,Robot_u8_MOTOR_DRIVER_L298_IN4,DIO_u8_PIN_OUTPUT);
	/***************************** INIT 7 SEGMENT ****************************/
	DIO_voidSetPortDirection(DIO_u8_PORTA ,DIO_u8_PORT_OUTPUT);
	/***************************** INIT BUZZER ****************************/
	DIO_voidSetPinDirection(DIO_u8_PORTC , DIO_u8_PIN5 , DIO_u8_PIN_OUTPUT);
}





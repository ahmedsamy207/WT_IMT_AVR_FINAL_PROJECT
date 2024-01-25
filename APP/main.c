/*****************************************************************/
/* Author  : Ahmed Samy                                              */
/* SWC     : AVR Project (RC and ObstacleAvoiding Robot)                                                */
/* Version : 1.0                                                 */
/* Date    : 20 Jan 2024                                         */
/*****************************************************************/
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "APP.h"

int main(void)
{
	/* Initialization Robot */
	Robot_voidInit();
	u8 Mode=0;
    while(1)
    {
    	Mode = DIO_u8GetPinValue(DIO_u8_PORTB , DIO_u8_PIN0);
		if(Mode == ObstacleAvoidingMode)
		{
			Robot_voidObstacleAvoidingMode();
		}
		else
		{
			Robot_voidBluetoothRCMode();
		}

    }

return 0;
}

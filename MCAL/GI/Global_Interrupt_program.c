#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "Global_Interrupt_private.h"
#include "Global_Interrupt_interface.h"

void Global_Interrupt_Enable(void)
{
	SET_BIT(SREG,I);
}
void Global_Interrupt_Disable(void)
{
	CLR_BIT(SREG,I);
}

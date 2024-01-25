/*******************************************************************/
/* Author  : Ahmed Samy                                                 */
/* SWC     : Seven_Segment                                         */
/* Version : 1.0                                                   */
/* Date    : 10 Dec 2023                                           */
/*******************************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_interface.h"
#include "Seven_Segment_interface.h"
#include "Seven_Segment_private.h"
#include "Seven_Segment_config.h"

/* COMMON CATHODE  				  F		B	  R	    L	  S	  */
u8 Seven_SegmentDIRLetter[5]={0x71, 0x7F, 0x50, 0x38, 0x6D};

void SevSeg_voidDisplay(u8 PortNum, u8 u8NumberCpy)
{
#if COMMON_TYPE == COMMON_CATHODE
	DIO_voidSetPortValue(PortNum, Seven_SegmentDIRLetter[u8NumberCpy]);
#elif COMMON_TYPE == COMMON_ANODE
	DIO_voidSetPortValue(PortNum, ~Seven_SegmentDIRLetter[u8NumberCpy]);
#endif
}

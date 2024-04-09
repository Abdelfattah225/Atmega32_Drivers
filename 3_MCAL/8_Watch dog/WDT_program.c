/**********************************************************************************************
 *  SWC				: MCAL
 *
 *  File			: WDT_interface.h
 *
 *  Created on		: oct 27, 2023
 *
 *  Author			: Abdelfattah Moawed
 *
 *  Version			: 1.0
 *******************************************************************************************/
/*LIB*/
#include"BIT_CALC.h"
#include"STD_TYPES.h"
/*MCAL*/
#include"DIO_interface.h"
#include"WDT_config.h"
#include"WDT_interface.h"
#include"WDT_private.h"

/* time:
 * 1- T16_3_ms
 * 2- T32_5_ms
 * 3- T65_ms
 * 4- T0_13_s
 * 5- T0_26_s
 * 6- T0_52_s
 * 7- T1_0_s
 * 8- T2_1_s
 * */
void WDT_void_Enable(u8 Copy_U8_Time)
{
	Assign_Bit(WDT_U8_WDTCR,DIO_U8_PIN0,Get_Bit(Copy_U8_Time,0));
	Assign_Bit(WDT_U8_WDTCR,DIO_U8_PIN1,Get_Bit(Copy_U8_Time,1));
	Assign_Bit(WDT_U8_WDTCR,DIO_U8_PIN2,Get_Bit(Copy_U8_Time,2));
	Assign_Bit(WDT_U8_WDTCR,DIO_U8_PIN3,1);
}
void WDT_void_Disable(void)
{
	WDT_U8_WDTCR =0b00011000;
	WDT_U8_WDTCR =0;
}




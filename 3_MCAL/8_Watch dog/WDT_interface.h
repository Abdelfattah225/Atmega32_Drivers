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

/******************************************< inclusion >************************************/

#ifndef WDT_INTERFACE_H_
#define WDT_INTERFACE_H_

void WDT_void_Enable(u8 Copy_U8_Time);
void WDT_void_Disable(void);


#define  T16_3_ms    0
#define  T32_5_ms	 1
#define  T65_ms      2
#define  T0_13_s     3
#define  T0_26_s     4
#define  T0_52_s     5
#define  T1_0_s      6
#define  T2_1_s      7

#endif /* WDT_INTERFACE_H_ */

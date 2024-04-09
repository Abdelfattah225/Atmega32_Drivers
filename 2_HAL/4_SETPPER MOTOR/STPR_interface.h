/*****************************************************************************/

/* File Defination :
 *
 * File 		: STPR_interface.h
 *
 * Created on	: Sep 30, 2023
 *
 * Author 		: ABDELFATTAH MOAWED
 */
/*****************************************************************************/


#ifndef STPR_INTERFACE_H_
#define STPR_INTERFACE_H_


void STEPPER_Rotate_CW_Full_Step(void);
void STEPPER_Rotate_ACW_Full_Step(void);
void STEPPER_Rotate_CW_Half_Step(void);
void STEPPER_Rotate_ACW_Half_Step(void);
void STEPPER_Set_Angle(u32 angle , u8 direction);



#define COIL_BLUE_PORT		PORTD_ID
#define COIL_BLUE_PIN		DIO_U8_PIN0

#define COIL_PINK_PORT		PORTD_ID
#define COIL_PINK_PIN		DIO_U8_PIN1

#define COIL_YELLOW_PORT	PORTD_ID
#define COIL_YELLOW_PIN		DIO_U8_PIN2

#define COIL_ORANGE_PORT	PORTD_ID
#define COIL_ORANGE_PIN		DIO_U8_PIN3

#define CW	0
#define ACW	1

#endif /* STPR_INTERFACE_H_ */

/*****************************************************************************/

/* File Defination :
 *
 * File 		: STPR_program.c
 *
 * Created on	: Sep 30, 2023
 *
 * Author 		: ABDELFATTAH MOAWED
 */
/*****************************************************************************/

#include"BIT_CALC.h"
#include"STD_Types.h"
#include<util/delay.h>
#include"DIO_interface.h"
#include"STPR_interface.h"

/*CLOCKWISE*/
void STEPPER_Rotate_CW_Full_Step(void)
{
	DIO_U8_Set_Pin_value(COIL_BLUE_PORT,COIL_BLUE_PIN,PIN_HIGH);
	DIO_U8_Set_Pin_value(COIL_PINK_PORT,COIL_PINK_PIN,PIN_LOW);
	DIO_U8_Set_Pin_value(COIL_YELLOW_PORT,COIL_YELLOW_PIN,PIN_LOW);
	DIO_U8_Set_Pin_value(COIL_ORANGE_PORT,COIL_ORANGE_PIN,PIN_LOW);
	_delay_ms(2);
	DIO_U8_Set_Pin_value(COIL_BLUE_PORT,COIL_BLUE_PIN,PIN_LOW);
	DIO_U8_Set_Pin_value(COIL_PINK_PORT,COIL_PINK_PIN,PIN_HIGH);
	DIO_U8_Set_Pin_value(COIL_YELLOW_PORT,COIL_YELLOW_PIN,PIN_LOW);
	DIO_U8_Set_Pin_value(COIL_ORANGE_PORT,COIL_ORANGE_PIN,PIN_LOW);
	_delay_ms(2);
	DIO_U8_Set_Pin_value(COIL_BLUE_PORT,COIL_BLUE_PIN,PIN_LOW);
	DIO_U8_Set_Pin_value(COIL_PINK_PORT,COIL_PINK_PIN,PIN_LOW);
	DIO_U8_Set_Pin_value(COIL_YELLOW_PORT,COIL_YELLOW_PIN,PIN_HIGH);
	DIO_U8_Set_Pin_value(COIL_ORANGE_PORT,COIL_ORANGE_PIN,PIN_LOW);
	_delay_ms(2);
	DIO_U8_Set_Pin_value(COIL_BLUE_PORT,COIL_BLUE_PIN,PIN_LOW);
	DIO_U8_Set_Pin_value(COIL_PINK_PORT,COIL_PINK_PIN,PIN_LOW);
	DIO_U8_Set_Pin_value(COIL_YELLOW_PORT,COIL_YELLOW_PIN,PIN_LOW);
	DIO_U8_Set_Pin_value(COIL_ORANGE_PORT,COIL_ORANGE_PIN,PIN_HIGH);
	_delay_ms(2);
}







/*COUNTER-CLOCKWISE*/
void STEPPER_Rotate_ACW_Full_Step(void)
{
	DIO_U8_Set_Pin_value(COIL_BLUE_PORT,COIL_BLUE_PIN,PIN_LOW);
	DIO_U8_Set_Pin_value(COIL_PINK_PORT,COIL_PINK_PIN,PIN_LOW);
	DIO_U8_Set_Pin_value(COIL_YELLOW_PORT,COIL_YELLOW_PIN,PIN_LOW);
	DIO_U8_Set_Pin_value(COIL_ORANGE_PORT,COIL_ORANGE_PIN,PIN_HIGH);
	_delay_ms(2);
	DIO_U8_Set_Pin_value(COIL_BLUE_PORT,COIL_BLUE_PIN,PIN_LOW);
	DIO_U8_Set_Pin_value(COIL_PINK_PORT,COIL_PINK_PIN,PIN_LOW);
	DIO_U8_Set_Pin_value(COIL_YELLOW_PORT,COIL_YELLOW_PIN,PIN_HIGH);
	DIO_U8_Set_Pin_value(COIL_ORANGE_PORT,COIL_ORANGE_PIN,PIN_LOW);
	_delay_ms(2);
	DIO_U8_Set_Pin_value(COIL_BLUE_PORT,COIL_BLUE_PIN,PIN_LOW);
	DIO_U8_Set_Pin_value(COIL_PINK_PORT,COIL_PINK_PIN,PIN_HIGH);
	DIO_U8_Set_Pin_value(COIL_YELLOW_PORT,COIL_YELLOW_PIN,PIN_LOW);
	DIO_U8_Set_Pin_value(COIL_ORANGE_PORT,COIL_ORANGE_PIN,PIN_LOW);
	_delay_ms(2);
	DIO_U8_Set_Pin_value(COIL_BLUE_PORT,COIL_BLUE_PIN,PIN_HIGH);
	DIO_U8_Set_Pin_value(COIL_PINK_PORT,COIL_PINK_PIN,PIN_LOW);
	DIO_U8_Set_Pin_value(COIL_YELLOW_PORT,COIL_YELLOW_PIN,PIN_LOW);
	DIO_U8_Set_Pin_value(COIL_ORANGE_PORT,COIL_ORANGE_PIN,PIN_LOW);
	_delay_ms(2);

}

void STEPPER_Rotate_CW_Half_Step(void)
{
		DIO_U8_Set_Pin_value(COIL_BLUE_PORT,COIL_BLUE_PIN,PIN_HIGH);
		DIO_U8_Set_Pin_value(COIL_PINK_PORT,COIL_PINK_PIN,PIN_LOW);
		DIO_U8_Set_Pin_value(COIL_YELLOW_PORT,COIL_YELLOW_PIN,PIN_LOW);
		DIO_U8_Set_Pin_value(COIL_ORANGE_PORT,COIL_ORANGE_PIN,PIN_HIGH);
		_delay_ms(2);
		DIO_U8_Set_Pin_value(COIL_BLUE_PORT,COIL_BLUE_PIN,PIN_HIGH);
		DIO_U8_Set_Pin_value(COIL_PINK_PORT,COIL_PINK_PIN,PIN_LOW);
		DIO_U8_Set_Pin_value(COIL_YELLOW_PORT,COIL_YELLOW_PIN,PIN_LOW);
		DIO_U8_Set_Pin_value(COIL_ORANGE_PORT,COIL_ORANGE_PIN,PIN_LOW);
		_delay_ms(2);
		DIO_U8_Set_Pin_value(COIL_BLUE_PORT,COIL_BLUE_PIN,PIN_HIGH);
		DIO_U8_Set_Pin_value(COIL_PINK_PORT,COIL_PINK_PIN,PIN_HIGH);
		DIO_U8_Set_Pin_value(COIL_YELLOW_PORT,COIL_YELLOW_PIN,PIN_LOW);
		DIO_U8_Set_Pin_value(COIL_ORANGE_PORT,COIL_ORANGE_PIN,PIN_LOW);
		_delay_ms(2);
		DIO_U8_Set_Pin_value(COIL_BLUE_PORT,COIL_BLUE_PIN,PIN_LOW);
		DIO_U8_Set_Pin_value(COIL_PINK_PORT,COIL_PINK_PIN,PIN_HIGH);
		DIO_U8_Set_Pin_value(COIL_YELLOW_PORT,COIL_YELLOW_PIN,PIN_LOW);
		DIO_U8_Set_Pin_value(COIL_ORANGE_PORT,COIL_ORANGE_PIN,PIN_LOW);
		_delay_ms(2);
		DIO_U8_Set_Pin_value(COIL_BLUE_PORT,COIL_BLUE_PIN,PIN_LOW);
		DIO_U8_Set_Pin_value(COIL_PINK_PORT,COIL_PINK_PIN,PIN_HIGH);
		DIO_U8_Set_Pin_value(COIL_YELLOW_PORT,COIL_YELLOW_PIN,PIN_HIGH);
		DIO_U8_Set_Pin_value(COIL_ORANGE_PORT,COIL_ORANGE_PIN,PIN_LOW);
		_delay_ms(2);
		DIO_U8_Set_Pin_value(COIL_BLUE_PORT,COIL_BLUE_PIN,PIN_LOW);
		DIO_U8_Set_Pin_value(COIL_PINK_PORT,COIL_PINK_PIN,PIN_LOW);
		DIO_U8_Set_Pin_value(COIL_YELLOW_PORT,COIL_YELLOW_PIN,PIN_HIGH);
		DIO_U8_Set_Pin_value(COIL_ORANGE_PORT,COIL_ORANGE_PIN,PIN_LOW);
		_delay_ms(2);
		DIO_U8_Set_Pin_value(COIL_BLUE_PORT,COIL_BLUE_PIN,PIN_LOW);
		DIO_U8_Set_Pin_value(COIL_PINK_PORT,COIL_PINK_PIN,PIN_LOW);
		DIO_U8_Set_Pin_value(COIL_YELLOW_PORT,COIL_YELLOW_PIN,PIN_HIGH);
		DIO_U8_Set_Pin_value(COIL_ORANGE_PORT,COIL_ORANGE_PIN,PIN_HIGH);
		_delay_ms(2);
		DIO_U8_Set_Pin_value(COIL_BLUE_PORT,COIL_BLUE_PIN,PIN_LOW);
		DIO_U8_Set_Pin_value(COIL_PINK_PORT,COIL_PINK_PIN,PIN_LOW);
		DIO_U8_Set_Pin_value(COIL_YELLOW_PORT,COIL_YELLOW_PIN,PIN_LOW);
		DIO_U8_Set_Pin_value(COIL_ORANGE_PORT,COIL_ORANGE_PIN,PIN_HIGH);
		_delay_ms(2);



}
void STEPPER_Rotate_ACW_Half_Step(void)
{
	DIO_U8_Set_Pin_value(COIL_BLUE_PORT,COIL_BLUE_PIN,PIN_LOW);
	DIO_U8_Set_Pin_value(COIL_PINK_PORT,COIL_PINK_PIN,PIN_LOW);
	DIO_U8_Set_Pin_value(COIL_YELLOW_PORT,COIL_YELLOW_PIN,PIN_LOW);
	DIO_U8_Set_Pin_value(COIL_ORANGE_PORT,COIL_ORANGE_PIN,PIN_HIGH);
	_delay_ms(2);
	DIO_U8_Set_Pin_value(COIL_BLUE_PORT,COIL_BLUE_PIN,PIN_LOW);
	DIO_U8_Set_Pin_value(COIL_PINK_PORT,COIL_PINK_PIN,PIN_LOW);
	DIO_U8_Set_Pin_value(COIL_YELLOW_PORT,COIL_YELLOW_PIN,PIN_HIGH);
	DIO_U8_Set_Pin_value(COIL_ORANGE_PORT,COIL_ORANGE_PIN,PIN_HIGH);
	_delay_ms(2);
	DIO_U8_Set_Pin_value(COIL_BLUE_PORT,COIL_BLUE_PIN,PIN_LOW);
	DIO_U8_Set_Pin_value(COIL_PINK_PORT,COIL_PINK_PIN,PIN_LOW);
	DIO_U8_Set_Pin_value(COIL_YELLOW_PORT,COIL_YELLOW_PIN,PIN_HIGH);
	DIO_U8_Set_Pin_value(COIL_ORANGE_PORT,COIL_ORANGE_PIN,PIN_LOW);
	_delay_ms(2);
	DIO_U8_Set_Pin_value(COIL_BLUE_PORT,COIL_BLUE_PIN,PIN_LOW);
	DIO_U8_Set_Pin_value(COIL_PINK_PORT,COIL_PINK_PIN,PIN_HIGH);
	DIO_U8_Set_Pin_value(COIL_YELLOW_PORT,COIL_YELLOW_PIN,PIN_HIGH);
	DIO_U8_Set_Pin_value(COIL_ORANGE_PORT,COIL_ORANGE_PIN,PIN_LOW);
	_delay_ms(2);
	DIO_U8_Set_Pin_value(COIL_BLUE_PORT,COIL_BLUE_PIN,PIN_LOW);
	DIO_U8_Set_Pin_value(COIL_PINK_PORT,COIL_PINK_PIN,PIN_HIGH);
	DIO_U8_Set_Pin_value(COIL_YELLOW_PORT,COIL_YELLOW_PIN,PIN_LOW);
	DIO_U8_Set_Pin_value(COIL_ORANGE_PORT,COIL_ORANGE_PIN,PIN_LOW);
	_delay_ms(2);
	DIO_U8_Set_Pin_value(COIL_BLUE_PORT,COIL_BLUE_PIN,PIN_HIGH);
	DIO_U8_Set_Pin_value(COIL_PINK_PORT,COIL_PINK_PIN,PIN_HIGH);
	DIO_U8_Set_Pin_value(COIL_YELLOW_PORT,COIL_YELLOW_PIN,PIN_LOW);
	DIO_U8_Set_Pin_value(COIL_ORANGE_PORT,COIL_ORANGE_PIN,PIN_LOW);
	_delay_ms(2);
	DIO_U8_Set_Pin_value(COIL_BLUE_PORT,COIL_BLUE_PIN,PIN_HIGH);
	DIO_U8_Set_Pin_value(COIL_PINK_PORT,COIL_PINK_PIN,PIN_LOW);
	DIO_U8_Set_Pin_value(COIL_YELLOW_PORT,COIL_YELLOW_PIN,PIN_LOW);
	DIO_U8_Set_Pin_value(COIL_ORANGE_PORT,COIL_ORANGE_PIN,PIN_LOW);
	_delay_ms(2);
	DIO_U8_Set_Pin_value(COIL_BLUE_PORT,COIL_BLUE_PIN,PIN_HIGH);
	DIO_U8_Set_Pin_value(COIL_PINK_PORT,COIL_PINK_PIN,PIN_LOW);
	DIO_U8_Set_Pin_value(COIL_YELLOW_PORT,COIL_YELLOW_PIN,PIN_LOW);
	DIO_U8_Set_Pin_value(COIL_ORANGE_PORT,COIL_ORANGE_PIN,PIN_HIGH);
	_delay_ms(2);
}


void STEPPER_Set_Angle(u32 angle , u8 direction)
{
	u32 steps =(angle*2048)/360;
	u32 loops = steps/4;
	if(direction==CW)
	{
		for(u32 i=0 ; i<loops ;i++)
		{
		STEPPER_Rotate_CW_Full_Step();
		}
	}
	else
	{
		for(u32 i=0 ; i<loops ;i++)
		{
			STEPPER_Rotate_ACW_Full_Step();
		}
	}
}

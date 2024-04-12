/*
 * RTOS_program.c
 *
 *  Created on: Dec 1, 2023
 *      Author: Administrator
 */
#include"util/delay.h"
#include"STD_Types.h"
#include"BIT_CALC.h"
#include"DIO_interface.h"
#include"RTOS_interface.h"

u8 Tick_Counts; // IN TIMER DRIVER
Task arr[NO_OF_TASKS];

void Task_Creation(u8 priority , u8 periodicity ,void(*func_ptr)(void))
{
	arr[priority].periodicity = periodicity;
	arr[priority].fptr = func_ptr ;

}
void Task_Delete(u8 priority)
{
	arr[priority].fptr = Null ;
}
void Task_Suspend(u8 priority)
{
	arr[priority].flag_is_active = 0;
}
void Task_Resume(u8 priority)
{
	arr[priority].flag_is_active = 1;
}
void Task_delay(u8 priority , u8 delay_time)
{
	arr[priority].Delay_counts = delay_time;
}
void Scheduler(void)
{
	for(u8 i=0 ; i<NO_OF_TASKS ; i++)
	{
		if(arr[i].fptr != Null)
		{
			if(arr[i].flag_is_active == 1)
			{
				if(arr[i].Delay_counts==0)
				{
					if(Tick_Counts % arr[i].periodicity == 0)
					{
						arr[i].fptr();
					}
				}
				else
				{
					arr[i].Delay_counts--;
				}
			}
		}
	}
}

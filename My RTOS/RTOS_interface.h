/*
 * RTOS_interface.h
 *
 *  Created on: Dec 1, 2023
 *      Author: Administrator
 */

#ifndef RTOS_INTERFACE_H_
#define RTOS_INTERFACE_H_

#include"util/delay.h"
#include"STD_Types.h"
#include"BIT_CALC.h"



#define NO_OF_TASKS		3

typedef struct{
	u8 periodicity;
	void (*fptr)(void);
	u8 flag_is_active = 1 ;
	u8 Delay_counts = 0 ;
}Task;



void Task_Creation(u8 priority , u8 periodicity ,void(*func_ptr)(void));
void Task_Delete(u8 priority)   ;
void Task_Suspend(u8 priority)  ;
void Task_Resume(u8 priority)   ;
void Task_delay(u8 priority , u8 delay_time);
void Scheduler(void);


#endif /* RTOS_INTERFACE_H_ */

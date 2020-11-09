/*
 * Test1.h
 *
 * Created: 11/9/2020 4:09:25 PM
 *  Author: star
 */ 


#ifndef TEST1_H_
#define TEST1_H_

#include "Config.h"
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "Timer.h"

typedef unsigned char tByte;
typedef unsigned int  tWord;
typedef unsigned long tLong;


#define SCH_MAX_TASKS (4)



typedef struct
{
	void (* pTask)(void);
	tWord Delay;
	tWord Period;
	tByte RunMe;
	tWord Repeat;
	
} sTask;

void SCH_Init(void);
void SCH_Start(void);

void SCH_Add_Task(void (* pFunction)(), const tWord DELAY, const tWord PERIOD, const tWord Repeat);
void SCH_Delete_Task(const tByte TASK_INDEX);


void SCH_Update(void);
void SCH_Dispatch_Tasks(void);


#endif 
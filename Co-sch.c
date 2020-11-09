/*
 * Test1.c
 *
 * Created: 11/9/2020 4:09:38 PM
 *  Author: star
 */ 


#include "Co-sch.h"




sTask SCH_tasks_G[SCH_MAX_TASKS];


void SCH_Init(void) {

	tByte i;

	for (i = 0; i < SCH_MAX_TASKS; i++) {
		SCH_Delete_Task(i);
	}
 Timer_init(SCH_Update);
}

void SCH_Start(void) {
	sei(); 
}




void SCH_Update(void) {
	tByte Index;
	for (Index = 0; Index < SCH_MAX_TASKS; Index++) {
		if (SCH_tasks_G[Index].pTask) {
			if (SCH_tasks_G[Index].Delay == 0) {
				SCH_tasks_G[Index].RunMe += 1;	
				if (SCH_tasks_G[Index].Repeat) {
					SCH_tasks_G[Index].Delay = SCH_tasks_G[Index].Repeat;
				}
				} else {
				SCH_tasks_G[Index].Delay -= 1;
			}
		}
	}
}

void SCH_Dispatch_Tasks(void) {
	while (1)
	{
			tByte Index;
			for (Index = 0; Index < SCH_MAX_TASKS; Index++) {
				if (SCH_tasks_G[Index].RunMe > 0) {
					(*SCH_tasks_G[Index].pTask)();

					SCH_tasks_G[Index].RunMe -= 1;
					
					if (SCH_tasks_G[Index].Period == 0) {
						SCH_Delete_Task(Index);
					}
				}
			}
	}
}

void SCH_Add_Task(void (*pFunction)(), const tWord DELAY, const tWord PERIOD,const tWord Repeat) {
	tByte Index = 0;


	while ((SCH_tasks_G[Index].pTask != 0) && (Index < SCH_MAX_TASKS)) {
		Index++;
	}

	SCH_tasks_G[Index].pTask = pFunction;

	SCH_tasks_G[Index].Delay = DELAY;
	SCH_tasks_G[Index].Repeat = Repeat;
	SCH_tasks_G[Index].Period = PERIOD;

	SCH_tasks_G[Index].RunMe = 0;


}

void SCH_Delete_Task(const tByte TASK_INDEX) {


	SCH_tasks_G[TASK_INDEX].pTask = 0;
	SCH_tasks_G[TASK_INDEX].Delay = 0;
	SCH_tasks_G[TASK_INDEX].Period = 0;
	SCH_tasks_G[TASK_INDEX].RunMe = 0;

      
}




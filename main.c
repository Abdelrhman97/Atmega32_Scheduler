/*
 * gainKnewledge.c
 *
 * Created: 10/20/2020 2:45:03 PM
 * Author : Abdelrhman Shaban
 */ 


#include "Co-sch.h"
void Task1 (void)
{
	PORTC = ~PORTC;
}
void Task2 (void)
{
	PORTD = ~PORTD;
}
void Task3 (void)
{
	PORTB = ~PORTB;
}
void Task4 (void)
{
	PORTA = ~PORTA;
}
int main()
{
	DDRC = 0xff;
	DDRD = 0xff;
	DDRB = 0xff;
	DDRA = 0xff;
	
	
SCH_Init();

SCH_Add_Task(Task1, 0, 1, 10);
SCH_Add_Task(Task2, 0, 1, 20);
SCH_Add_Task(Task3, 0, 1, 30);
SCH_Add_Task(Task4, 0, 1, 40);

	SCH_Start();

		SCH_Dispatch_Tasks();
	return 0;
}



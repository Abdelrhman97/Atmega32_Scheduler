/*
 * Timer.c
 *
 * Created: 11/8/2020 4:04:33 PM
 *  Author: star
 */ 
#include "Timer.h"

static void (*P2F_Call)();

ISR(TIMER0_OVF_vect)
{
	P2F_Call();
	TCNT0=248;
}
void Timer_init(void (*P2F)())
{
	P2F_Call = P2F; 
	TIMSK |= 1<<0;	//enable interrupt for timer
	TCCR0 |= (1<<CS02) | (1<<CS00);
	TCNT0 =248;
}


void Timer_Start(void)
{
	TIMSK |= (1<<0);	//Enable interrupt for timer
}

void Timer_Stop(void)
{
	TIMSK &= ~(1<<0);	//disable interrupt for timer
}
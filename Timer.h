/*
 * Timer.h
 *
 * Created: 11/8/2020 4:04:45 PM
 *  Author: star
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "Config.h"
#include <avr/io.h>
#include <avr/interrupt.h>

void Timer_init(void (*P2F)());

void Timer_Start(void);

void Timer_Stop(void);



#endif /* TIMER_H_ */
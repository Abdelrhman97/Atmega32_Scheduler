#ifndef Config_H_
#define Config_H_

#define F_CPU 8000000ul
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define Base_A 0x39 
#define Base_B 0x36
#define Base_C 0x33 
#define Base_D 0x30

typedef enum 
{
	A = Base_A,
	B = Base_B,
	C = Base_C,
	D = Base_D, 
}pName; 



/* - INPUT = 0.....OUTPUT = 1 - */
typedef enum 
{
	INPUT = 0,
	OUTPUT = 1,
}Direction;

/* - LOW = 0.....HIGH = 1 - */
typedef enum 
{
	LOW = 0,
	HIGH = 1, 
}Value;


typedef char int8; 
typedef unsigned char uint8;
typedef short  int16;
typedef unsigned short uint16; 
typedef long int int32; 
typedef unsigned long int uint32; 
typedef char* String; 

#endif 
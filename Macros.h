#ifndef Macros_H_
#define Macros_H_

#include "Config.h"

/*******************************************************************************
 *                      Functions-Like Macros                                  *
 *******************************************************************************/
 
/* -  Write 1 on a certain bit in any register - */
 
#define SetBit(REG,BIT) (REG |= (1<<BIT));

/* -  Write 0 on a certain bit in any register - */

#define ClearBit(REG,BIT) (REG &= ~(1<<BIT));

/* - Toggle a certain bit in any register - */ 
#define ToggleBit(REG,BIT)  (REG ^= (1 << BIT))  

/* - Check if a specific bit is cleared in any register - */
#define BitIsClear(REG,BIT) ( !(REG & (1<<BIT)) )

/* - Check if a specific bit is set in any register - */
#define BitIsSet (REG,BIT)  (REG & (1 << BIT))  

/* - Rotate right the register value with specific number of rotates - */
#define ROR(REG,NUM)			(REG = (REG >> NUM) | (REG << (8 - NUM)))

/* - Rotate left the register value with specific number of rotates - */
#define ROL(REG,NUM)			(REG = (REG << NUM) | (REG >> (8 - NUM)))




#endif 
/***************************************************************************************************************************
* This file is subject to the terms and conditions defined in file 'LICENSE.txt', 
* which is part of this source code package. 
*
* Project									: MCU Init and Blinky LED
* Program Name						: Blinky_STM32_Discovery.uvprojx
* Author									: vkaiser
* Date Created						: Sept 27, 2019
* 
* Purpose									: Initialize eval board and operate GPIO
*														- Toggle LED
*														
* MCU											: STM32F407VGT6
* Language								: C
* Hardware Modifications	: N/A
* Debugger								: ST-Link Debugger (on-board)
*
* Repo / Revision History	: https://github.com/vlkaiser/STM32F407_Disc_Test_1
*
* - Special Setup -
* Keil Pack Installer 		: Device Specific DFP
*													: LED API & supporting resources (classic)						
* 
* Revision History				:
* 	Date				Author			Notes
* 09272019			vkaiser			- Initial commit
*
***************************************************************************************************************************/
#include <stdint.h>	
#include "Board_LED.h"			//Contains LED function prototpes (See Board support package - LED)

/* Functions */
/**
  \fn          void delay(void)
  \brief       Use a counter as a program wait function
  \returns		 Nothing - ?
**/
void delay(void)
{
	//unsigned int i = 0;			//long-hand type
	uint32_t i = 0;						//shorthand type, but must include stdint.h
	for(i=0; i<1000000; i++);
}

/* Main */
int main(void)
{
	while(1)
		{
			LED_Initialize ();					//From Board Support Package - LED
			LED_On (0); 								//BSP - LED: Function takes in LED identifier number
			LED_On (1);
			LED_On (2);
			LED_On (3);
			delay();										//Our Function (see above)
			LED_Off (0); 								//BSP - LED: Function takes in LED identifier number
			LED_Off (1);
			LED_Off (2);
			LED_Off (3);
			delay();
		}

	return 0;
}

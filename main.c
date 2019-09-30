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
* 												: Button API
* Revision History				:
* 	Date				Author			Notes
* 09272019			vkaiser			- Initial commit
*
***************************************************************************************************************************/
#include <stdint.h>	
#include "Board_LED.h"			//Contains LED function prototpes (See Board support package - LED)
#include "Board_Buttons.h"	//Contains Button function prototypes

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

/**
  \fn          void toggleLED(void)
  \brief       Pass in a value 0-3, turn on and off that led
  \returns		 Nothing - ?
	\notes			 NO ERROR CHECKING if value > 3
**/
void toggleLED(uint8_t num)
{
			LED_On (num); 								//BSP - LED: Function takes in LED identifier number
			delay();										//Our Function (see above)
			LED_Off (num); 								//BSP - LED: Function takes in LED identifier number
			delay();
}

/* Main */
int main(void)
{
	LED_Initialize ();					//From Board Support Package - LED
	Buttons_Initialize();				//From BSP - Button
		
	/* Do this forever: */
	while(1)
		{	
			/* When button USER is pressed, flash led 0 until it is released */
			if(Buttons_GetState() == 1)		//Returns 1 on USER pressed, 0 normally (from BSP)
			{
				toggleLED(0);
			}
			
		}

	return 0;
}

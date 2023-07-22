/*
 * ====================================================================================================================================
 *  Project		: Vehicle Door Handle Control Unit
 * 	File Name	: Led.c
 *	Team 		: 20
 *	Members		: Abdelrahman Yasser - Omar Ahmed Anwar - Mo'men Mohamed - Neveen Mohamed
 *  ===================================================================================================================================
 */

/*---------------------- Includes ----------------------*/
#include "led.h"
/*------------------------------------------------------*/

/*---------------------- Functions Definition ----------------------*/

/*
 * description:
 * 	Argument(s):
 * 		--> portName:	LED Port.
 * 		--> pinNum: 	LED pin.
 * 	Function to configure Port and pin of the LED.
 */
void LED_Init(GPIO_handleTypedef *GPIOx, uint8 pinNum){

	GPIO_ConfigPin(GPIOx, pinNum);

	GPIO_WritePinValue(GPIOx, (GPIO_Data)LED_OFF, pinNum);
}

/*
 * description:
 * 	Argument(s):
 * 		--> portName:	LED Port.
 * 		--> pinNum: 	LED pin.
 * 		--> state: 		Activate the led HIGH or LOW.
 * 	Function to activate the LED corresponding to the state.
 */
void LED_Activate(GPIO_handleTypedef *GPIOx, LED_States state, uint8 pinNum){

	GPIO_WritePinValue(GPIOx, (GPIO_Data)state, pinNum);

}

/*
 * description:
 * 	Argument(s):
 * 		--> portName:	LED Port.
 * 		--> pinNum: 	LED pin.
 * 	Function to toggle the LED.
 */
void LED_Toggle(GPIO_handleTypedef *GPIOx, uint8 pinNum){

	GPIO_TogglePin(GPIOx, pinNum);

}
/*-----------------------------------------------------------------------------*/




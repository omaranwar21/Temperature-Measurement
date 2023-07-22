/*
 * ====================================================================================================================================
 *  Project		: SPI_TC72
 * 	File Name	: TC72.h
 *	Author		: Omar Anwar
 *  ===================================================================================================================================
 */
#ifndef TC72_H_
#define TC72_H_

#include "Std_Types.h"
#include "SPI.h"
#include "Gpio.h"

#define TC72_WRITE_ADDRESS				(0X80U)
#define TC72_READ_LSB_TEMP_ADDRESS		(0X01U)
#define TC72_READ_MSB_TEMP_ADDRESS		(0X02U)

#define TC72_DUMMY_DATA					(0x00U)

#define TC72_CR_SHDN_BIT				0
#define TC72_CR_OS_BIT					4

#define TC72_DATA_SET_BIT_7				(1<<7)
#define TC72_DATA_RESET_BIT_7			(~(1<<7))

typedef enum{
	TC72_MODE_CTC,			/* 		Continuous Temperature Conversion Mode 		*/
	TC72_MODE_SHDN,			/* 					Shut Down Mode					*/
	TC72_MODE_OS = 3		/* 					One-Shot Mode					*/
}TC72_Mode;

void TC72_Init(SPI_handler *pSPIx, TC72_Mode mode);

void TC72_WriteRegister(SPI_handler *pSPIx, uint8 regAdd, uint8 data);

uint8 TC72_ReadRegister(SPI_handler *pSPIx, uint8 regAdd);

void TC72_GetTemperature(GPIO_handleTypedef TC72_gpio, SPI_handler TC72_spi, uint8 chipSelectPin, sint8* temp);

#endif /* TC72_H_ */

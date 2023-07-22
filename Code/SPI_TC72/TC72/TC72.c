/*
 * ====================================================================================================================================
 *  Project		: SPI_TC72
 * 	File Name	: TC72.c
 *	Author		: Omar Anwar
 *  ===================================================================================================================================
 */

#include "TC72.h"
#include "Bit_Operations.h"

void TC72_Init(SPI_handler *pSPIx, TC72_Mode mode){
	uint8 data = 0;
	data |= READ_BIT(mode, TC72_CR_SHDN_BIT);
	data |= (READ_BIT(mode, TC72_CR_OS_BIT) << TC72_CR_OS_BIT);
	TC72_WriteRegister(pSPIx, TC72_WRITE_ADDRESS, data);
}

void TC72_WriteRegister(SPI_handler *pSPIx, uint8 regAdd, uint8 data){
	SPI_TransmitRecieveByte(pSPIx->pSPIx, (regAdd | TC72_DATA_SET_BIT_7));
	SPI_TransmitRecieveByte(pSPIx->pSPIx, data);
}

uint8 TC72_ReadRegister(SPI_handler *pSPIx, uint8 regAdd){
	SPI_TransmitRecieveByte(pSPIx->pSPIx, (regAdd & TC72_DATA_RESET_BIT_7));
	return SPI_TransmitRecieveByte(pSPIx->pSPIx, TC72_DUMMY_DATA);
}

void TC72_GetTemperature(GPIO_handleTypedef TC72_gpio, SPI_handler TC72_spi, uint8 chipSelectPin, sint8* temp){

	uint8 data = 0;

	GPIO_WritePinValue(&TC72_gpio, HIGH, chipSelectPin);
	data = TC72_ReadRegister(&TC72_spi, TC72_READ_LSB_TEMP_ADDRESS);
	GPIO_WritePinValue(&TC72_gpio, LOW, chipSelectPin);

	temp[1] = 0;
	if (READ_BIT(data, 7)) {
		temp[1] += 50;
	}
	if (READ_BIT(data, 6)) {
		temp[1] += 25;
	}

	GPIO_WritePinValue(&TC72_gpio, HIGH, chipSelectPin);
	data = TC72_ReadRegister(&TC72_spi, TC72_READ_MSB_TEMP_ADDRESS);
	GPIO_WritePinValue(&TC72_gpio, LOW, chipSelectPin);

	temp[0] = (sint8) data;

}


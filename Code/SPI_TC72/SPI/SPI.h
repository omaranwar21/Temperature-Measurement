/*
 * ====================================================================================================================================
 *  Project		: SPI_driver
 * 	File Name	: SPI.h
 *	Author		: Omar Anwar
 *  ===================================================================================================================================
 */
#ifndef SPI_H_
#define SPI_H_

#include "SPI_Private.h"

#define SPI1		((SPI_TypeDef*)SPI1_BASE_ADDRESS)
#define SPI2		((SPI_TypeDef*)SPI2_BASE_ADDRESS)
#define SPI3		((SPI_TypeDef*)SPI3_BASE_ADDRESS)
#define SPI4		((SPI_TypeDef*)SPI4_BASE_ADDRESS)

/*====================================================================================
 * Bit field of Registers
 =====================================================================================*/
/*
 * SPI_CR1 Register
 */
typedef enum{
	SPI_CR1_CPHA,
	SPI_CR1_CPOL,
	SPI_CR1_MSTR,
	SPI_CR1_BR,
	SPI_CR1_SPE = 6,
	SPI_CR1_LSBFIRST,
	SPI_CR1_SSI,
	SPI_CR1_SSM,
	SPI_CR1_RXONLY,
	SPI_CR1_DFF,
	SPI_CR1_CRCNEXT,
	SPI_CR1_CRCEN,
	SPI_CR1_BIDIOE,
	SPI_CR1_BIDIMODE
}SPI_CR1;

/*
 * SPI_CR2 Register
 */
typedef enum{
	SPI_CR2_RXDMAEN,
	SPI_CR2_TXDMAEN,
	SPI_CR2_SSOE,
	SPI_CR2_FRF = 4,
	SPI_CR2_ERRIE,
	SPI_CR2_RXNEIE,
	SPI_CR2_TXEIE,
}SPI_CR2;

/*
 * SPI_SR (Status Register) Register
 */
typedef enum{
	SPI_SR_RXNE,
	SPI_SR_TXE,
	SPI_SR_CHSIDE,
	SPI_SR_UDR,
	SPI_SR_CRCERR,
	SPI_SR_MODF,
	SPI_SR_OVR,
	SPI_SR_BSY,
	SPI_SR_FRE,
}SPI_SR;


typedef enum{
	SPI_DEVICE_MODE_SLAVE, SPI_DEVICE_MODE_MASTER
}SPI_DeviceMode;

typedef enum{
	SPI_BUS_HALF_DUPLEX, SPI_BUS_FULL_DUPLEX, SPI_BUS_SIMPLEX_RXONLY
}SPI_BusConfig;

typedef enum{
	SPI_SPEED_DIV_2, SPI_SPEED_DIV_4,
	SPI_SPEED_DIV_8, SPI_SPEED_DIV_16,
	SPI_SPEED_DIV_32, SPI_SPEED_DIV_64,
	SPI_SPEED_DIV_128, SPI_SPEED_DIV_256
}SPI_SclkSpeed;

typedef enum{
	SPI_8_BITS_DATA, SPI_16_BITS_DATA
}SPI_DataFrameFormat;

typedef enum{
	SPI_CLK_POL_LOW, SPI_CLK_POL_HIGH
}SPI_ClkPOL;

typedef enum{
	SPI_CLK_PHA_LOW, SPI_CLK_PHA_HIGH
}SPI_ClkPHA;

typedef enum{
	SPI_MSB_FIRST, SPI_LSB_FIRST
}SPI_FirstBit;

typedef enum{
	SPI_SSM_EN, SPI_SSM_DI
}SPI_SSM;

typedef enum{
	SPI_Buffer_NOT_EMPTY, SPI_Buffer_EMPTY
}SPI_Buffer;

typedef enum{
	SPI_ENABLE, SPI_DISABLE
}SPI_EnableOrDisable;

typedef struct{
	SPI_DeviceMode		deviceMode;			/* Master or Slave									 	*/
	SPI_BusConfig		busConfig;			/* Half-duplex, Full-duplex, simplex				 	*/
	SPI_SclkSpeed		clkSpeed;			/* BaudRate (Clock divisor) 						 	*/
	SPI_DataFrameFormat	dataFrame;			/* 8-bit or 16-bit									 	*/
	SPI_ClkPOL			clkPolarity;		/* Idle state value of the clock					 	*/
	SPI_ClkPHA			clkPhase;			/* Controls at which clock edge data will be sampled 	*/
	SPI_FirstBit		frameFormat;		/* Controls which bit will be sampled transfered first	*/
	SPI_SSM				swSlaveManagement;	/* Software slave management						 	*/
}SPI_Config;

typedef struct{
	SPI_TypeDef *pSPIx;
	SPI_Config	SPIconfig;
}SPI_handler;


void SPI_init(SPI_handler *pSPIHandle);

uint8 SPI_TransmitRecieveByte(SPI_TypeDef *pSPIx, uint8 TxData);


#endif /* SPI_H_ */

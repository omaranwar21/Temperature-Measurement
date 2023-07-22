/*
 * ====================================================================================================================================
 *  Project		: SPI_driver
 * 	File Name	: SPI_Private.h
 *	Author		: Omar Anwar
 *  ===================================================================================================================================
 */
#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

#include "Std_Types.h"

#define SPI1_BASE_ADDRESS		0x40013000UL
#define SPI2_BASE_ADDRESS		0x40003800UL
#define SPI3_BASE_ADDRESS		0x40003C00UL
#define SPI4_BASE_ADDRESS		0x40013400UL

typedef struct{
	__IO uint32 CR1;			/* SPI control register 1, !<not used in I2S mode>		*/
	__IO uint32 CR2;			/* SPI control register 2 								*/
	__IO uint32 SR;				/* SPI status register 									*/
	__IO uint32 DR;				/* SPI status register									*/
	__IO uint32 CRCPR;			/* SPI CRC polynomial register, !<not used in I2S mode> */
	__IO uint32 RXCRCR;			/* SPI RX CRC register, !<not used in I2S mode> 		*/
	__IO uint32 TXCRCR;			/* SPI TX CRC register, !<not used in I2S mode>			*/
	__IO uint32 I2SCFGR;		/* SPI_I2S configuration register						*/
	__IO uint32 I2SPR;			/* SPI_I2S prescaler register							*/
}SPI_TypeDef;




#endif /* SPI_PRIVATE_H_ */

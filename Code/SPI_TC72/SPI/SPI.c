/*
 * ====================================================================================================================================
 *  Project		: SPI_driver
 * 	File Name	: SPI.c
 *	Author		: Omar Anwar
 *  ===================================================================================================================================
 */

#include "SPI.h"
#include "Bit_Operations.h"

void SPI_init(SPI_handler *pSPIHandle){

	SET_BIT(pSPIHandle->pSPIx->CR1, SPI_CR1_SSI);
	/*
	 * All configuration must be done while SPI peripheral is disabled
	 */

	// Make sure to disable SPI peripheral <Reset SPE bit in SPI_CR1>.
	pSPIHandle->pSPIx->CR1 &= ~(1<< SPI_CR1_SPE);

	// 1. configure device mode
	pSPIHandle->pSPIx->CR1 &= ~(1 << SPI_CR1_MSTR);
	pSPIHandle->pSPIx->CR1 |= (pSPIHandle->SPIconfig.deviceMode << SPI_CR1_MSTR);

	// 2. Bus configuration.
	switch (pSPIHandle->SPIconfig.busConfig) {
		case SPI_BUS_FULL_DUPLEX:
			// 2-line unidirectional data mode selected
			pSPIHandle->pSPIx->CR1 &= ~(1 << SPI_CR1_BIDIMODE);
			break;
		case SPI_BUS_HALF_DUPLEX:
			// 1-line bidirectional data mode selected
			pSPIHandle->pSPIx->CR1 |= (1 << SPI_CR1_BIDIMODE);
			break;
		case SPI_BUS_SIMPLEX_RXONLY:
			// 2-line unidirectional data mode selected
			pSPIHandle->pSPIx->CR1 &= ~(1 << SPI_CR1_BIDIMODE);
			// Output disabled (Receive-only mode)
			pSPIHandle->pSPIx->CR1 |= (1 << SPI_CR1_RXONLY);
			break;
	}

	// 3.configure SPI clock speed.
	pSPIHandle->pSPIx->CR1 &= ~(0x3 << SPI_CR1_BR);
	pSPIHandle->pSPIx->CR1 |= (pSPIHandle->SPIconfig.clkSpeed << SPI_CR1_BR);

	// 4. Configure data frame format.
	pSPIHandle->pSPIx->CR1 &= ~(1 << SPI_CR1_DFF);
	pSPIHandle->pSPIx->CR1 |= (pSPIHandle->SPIconfig.dataFrame << SPI_CR1_DFF);

	// 5. Configure clock polarity.
	pSPIHandle->pSPIx->CR1 &= ~(1 << SPI_CR1_CPOL);
	pSPIHandle->pSPIx->CR1 |= (pSPIHandle->SPIconfig.clkPolarity << SPI_CR1_CPOL);

	// 6. Configure clock phase.
	pSPIHandle->pSPIx->CR1 &= ~(1 << SPI_CR1_CPHA);
	pSPIHandle->pSPIx->CR1 |= (pSPIHandle->SPIconfig.clkPhase << SPI_CR1_CPHA);

	// 7. First bit frame format.
	pSPIHandle->pSPIx->CR1 &= ~(1 << SPI_CR1_LSBFIRST);
	pSPIHandle->pSPIx->CR1 |= (pSPIHandle->SPIconfig.frameFormat << SPI_CR1_LSBFIRST);

	// 8. Enable/Disable Software slave management.
	pSPIHandle->pSPIx->CR1 &= ~(1 << SPI_CR1_SSM);
	pSPIHandle->pSPIx->CR1 |= (pSPIHandle->SPIconfig.swSlaveManagement << SPI_CR1_SSM);

	SET_BIT(pSPIHandle->pSPIx->CR1, SPI_CR1_SPE);
}


uint8 SPI_TransmitRecieveByte(SPI_TypeDef *pSPIx, uint8 TxData){
	if (READ_BIT(pSPIx->SR,SPI_SR_TXE)) {
		pSPIx->DR = TxData;
		while(READ_BIT(pSPIx->SR,SPI_SR_BSY));
		return pSPIx->DR;
	}

	return 0xFF;
}



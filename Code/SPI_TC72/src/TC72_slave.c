/*
 * ====================================================================================================================================
 *  Project		: SPI_TC72
 * 	File Name	: TC72_slave.c
 *	Author		: Omar Anwar
 *  ===================================================================================================================================
 */

#include "Gpio.h"
#include "TC72.h"
#include "SPI.h"
#include "Rcc.h"
#include "lcd.h"
#include "Delay.h"

#define SPI1_NSS_PIN	4
#define SPI1_SCK_PIN	5
#define SPI1_MISO_PIN	6
#define SPI1_MOSI_PIN	7

SPI_handler TC72_spi = {
		SPI1,
		{
			SPI_DEVICE_MODE_MASTER,
			SPI_BUS_FULL_DUPLEX,
			SPI_SPEED_DIV_2,
			SPI_8_BITS_DATA,
			SPI_CLK_POL_LOW,
			SPI_CLK_PHA_HIGH,
			SPI_MSB_FIRST,
			SPI_SSM_DI
		}
};

GPIO_handleTypedef TC72_gpio = {
		GPIO_A,
		GPIO_MEDIUM_SPEED,
		GPIO_AF,
		GPIO_PUSH_PULL,
		GPIO_NO_PULL_UP_DOWN,
		GPIO_AF05
};

int main(void) {

	Rcc_Init();
	Rcc_Enable(RCC_GPIOA);
	Rcc_Enable(RCC_GPIOB);
	Rcc_Enable(RCC_GPIOC);
	Rcc_Enable(RCC_SPI1);

	LCD_init();
	LCD_displayString("HELLO");
	GPIO_ConfigPin(&TC72_gpio, SPI1_SCK_PIN);
	GPIO_ConfigPin(&TC72_gpio, SPI1_MISO_PIN);
	GPIO_ConfigPin(&TC72_gpio, SPI1_MOSI_PIN);
	TC72_gpio.pinMode = GPIO_OUTPUT;
	GPIO_ConfigPin(&TC72_gpio, SPI1_NSS_PIN);

	SPI_init(&TC72_spi);

	GPIO_WritePinValue(&TC72_gpio, HIGH, SPI1_NSS_PIN);
	TC72_Init(&TC72_spi, TC72_MODE_CTC);
	GPIO_WritePinValue(&TC72_gpio, LOW, SPI1_NSS_PIN);

	while(1){
		sint8 temp[2];

		delay_ms(1000);
		LCD_clearScreen();

		TC72_GetTemperature(TC72_gpio, TC72_spi, SPI1_NSS_PIN, temp);

		LCD_intgerToString(temp[0]);
		LCD_displayCharacter('.');
		LCD_intgerToString(temp[1]);


	}





}






/*
 * Driver_SPI.c
 *
 * Created: 14.07.2026 13:00:54
 * Author : rakel
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "driverSpi.h"

static void CS_LOW(void)
{
  PORTB &= ~(1 << PB2);
}

static void CS_HIGH(void)
{
  PORTB |= (1 << PB2);
}


 int main(void)
{   

         spi_Init();
	
	 spi_SetClockDivider(SPI_DIV4);
	 spi_SetMode(SPI_MODE0);
	 spi_SetBitOrder(SPI_MSB);
	
    while (1) 
    {
		
		CS_LOW();
		spi_MasterTransmit(0xD0);
		uint8_t bmeValue = spi_MasterTransmit(0x00);
		CS_HIGH();
		_delay_ms(500);          // Debug Проверка драйвера SPI
    }
}
/*
 * driverSpi.h
 *
 * Created: 14.07.2026 13:05:09
 *  Author: rakel
 */ 


#ifndef DRIVERSPI_H_
#define DRIVERSPI_H_
#define F_CPU 8000000UL
#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>

typedef enum
{
  SPI_LSB,
  SPI_MSB,
}SPI_BitOrder;

typedef enum
{
  SPI_MODE0,
  SPI_MODE1,
  SPI_MODE2,
  SPI_MODE3,
	
}SPI_Mode;

typedef enum
{
  SPI_DIV2,
  SPI_DIV4,
  SPI_DIV8,
  SPI_DIV16,
  SPI_DIV32,
  SPI_DIV64,
  SPI_DIV128,
  
}SPI_ClockDivider;

void spi_Init();
void spi_SetClockDivider(SPI_ClockDivider divider);
void spi_SetMode(SPI_Mode mode);
void spi_SetBitOrder(SPI_BitOrder order);
uint8_t spi_MasterTransmit(uint8_t data);

//void SS_LOW();  // DEBUG
//void SS_HIGH(); // DEBUG




#endif /* DRIVERSPI_H_ */
/*
 * driverSpi.c
 *
 * Created: 14.07.2026 13:06:01
 *  Author: rakel
 */ 

#include "Driver_SPIatm8.h"
#define SPI_SS   PB2
#define SPI_MOSI PB3
#define SPI_MISO PB4
#define SPI_SCK  PB5



void spi_Init()
{
 /*1*///установка аппаратных пинов SPI (MOSI,SS,SCK) на выход (MISO на вход) на пин MISO в PORTx установить подтяжку к "+" питания
      //установить пин SS на выход(чтобы во время работы он случайно не стал входом)иначе МК перейдет в режим SLAVE
 /*2*///установить контроллер в режим MASTER в регистре SPCR бит MSTR установить в 1
 /*3*///запустить интерфейс SPI в регистре SPCR бит SPE установить в 1
 /*4*///частоту тактирования работы SPI устанавливаем в универсальной функции настройки под каждое устройство spi_SetClockDivider(SPI_ClockDivider divider);
	
 /*1*/ DDRB |= (1 << SPI_MOSI) | (1 << SPI_SCK) | (1 << SPI_SS);
       PORTB |= (1 << SPI_SS); 
       DDRB &= ~(1 << SPI_MISO);
	   PORTB |= (1 << SPI_MISO);
	   
 /*2*/ SPCR |= (1 << MSTR);
 /*3*/ SPCR |= (1 << SPE);
	
}
void spi_SetClockDivider(SPI_ClockDivider divider)
{
	//Частоту тактирования устанавливаем комбинацией битаов SPR1, SPR0 в регистре SPCR и бита SPI2X в регистре SPSR
	switch(divider)
	{
	   case SPI_DIV2: SPSR |= (1 << SPI2X); SPCR &= ~(1 << SPR1); SPCR &= ~(1 << SPR0);  break;
	   case SPI_DIV4: SPSR &= ~(1 << SPI2X); SPCR &= ~(1 << SPR1); SPCR &= ~(1 << SPR0); break;
	   case SPI_DIV8: SPSR |= (1 << SPI2X); SPCR &= ~(1 << SPR1); SPCR |= (1 << SPR0);   break;
	   case SPI_DIV16: SPSR &= ~(1 << SPI2X); SPCR &= ~(1 << SPR1); SPCR |= (1 << SPR0); break;
	   case SPI_DIV32: SPSR |= (1 << SPI2X); SPCR |= (1 << SPR1); SPCR &= ~(1 << SPR0);  break;
	   case SPI_DIV64: SPSR |= (1 << SPI2X); SPCR |= (1 << SPR1); SPCR |= (1 << SPR0);   break;
	   case SPI_DIV128: SPSR &= ~(1 << SPI2X); SPCR |= (1 << SPR1); SPCR |= (1 << SPR0); break;
	   
	}
}

void spi_SetMode(SPI_Mode mode)
{
 //Выставляем режим работы SPI шины:
 // 1).(полярность сигнала SCK->сигнал в покое либо "0" либо "1")-> выставляется битом CPOL в регистре SPCR 
 // 2).(считывание значения)-> либо по переднему фронту либо по заднему фронту меандра тактовой частоты -> выставляется битом CPHA в регистре SPCR
  
  switch(mode)
  {
	  case SPI_MODE0: SPCR &= ~(1 << CPOL); SPCR &= ~(1 << CPHA); break;
	  case SPI_MODE1: SPCR &= ~(1 << CPOL); SPCR |= (1 << CPHA);  break;
	  case SPI_MODE2: SPCR |= (1 << CPOL); SPCR &= ~(1 << CPHA);  break;
	  case SPI_MODE3: SPCR |= (1 << CPOL); SPCR |= (1 << CPHA); break;
  }
}

void spi_SetBitOrder(SPI_BitOrder order)
{
  // Установка выполняется битом DORD в регистре SPCR
  // Выставляем то, какой бит будет пересылаться первым:
  // 1). DORD = 1; -> LSB of the data word transmitted first
  // 2). DORD = 0; -> MSB of the data word transmitted first
   switch(order)
   {
	   case SPI_MSB: SPCR &= ~(1 << DORD); break;
	   case SPI_LSB: SPCR |= (1 << DORD);  break;
   }
}

uint8_t spi_MasterTransmit(uint8_t data)
{
  SPDR = data;
  while(!(SPSR & (1 << SPIF)));
  return SPDR;
}



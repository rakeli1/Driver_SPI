
 # SPI Configuration

 ## Overview

 The SPI driver allows the the application to configure the communication parameters required by different SPI pereferal devices
 
 The following parameters can be configured:

 - SPI clock frequency
 - SPI mode
 - Bit order

 -----------------------------------------------------------------------

 ## SPI clock frequency (Clock Divider)

 The SPI clock frequency is configured using:

 void spi_SetClockDivider(SPI_ClockDivider divider);

 Available values:

  SPI_DIV2,
  SPI_DIV4,
  SPI_DIV8,
  SPI_DIV16,
  SPI_DIV32,
  SPI_DIV64,
  SPI_DIV128,

 Select a clock divider according to the timing requirementsof the target SPI device

 ------------------------------------------------------------------------

 ## SPI Mode

 The SPI mode is configured using:

 void spi_SetMode(SPI_Mode mode);

 Supported modes:

  SPI_MODE0,
  SPI_MODE1,
  SPI_MODE2,
  SPI_MODE3,

 Always use the SPI mode specified in the pereferal device datasheet.

 --------------------------------------------------------------------------

 ## Bit Order

 The bit transmission order is configured using:

 void spi_SetBitOrder(SPI_BitOrder);

 Supported values:

   SPI_LSB,
   SPI_MSB,

 Most SPI periferals use MSB First.

 --------------------------------------------------------------------------

 ## Chip Select

 Chip Select (CS) control is not implemented by the SPI driver.

 Each periferal driver is responsible for controlling its own CS pin.

 Example:

 CS_LOW();

 /* SPI communication */

 CS_HIGH();

 ----------------------------------------------------------------------------
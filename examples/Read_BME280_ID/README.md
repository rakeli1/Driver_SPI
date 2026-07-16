
# Read BME280 Chip ID

## Description

This example demonstrates how to use the SPI driver to read the Chip ID register of the BME280 sensor.

##Expected Result

Chip ID register address: 0xD0

Expected value:           0x60

##Notes

- SPI Mode 0
- Bit Order: MSB First
- Clock Divider: SPI_DIV4
- Chip Select (CS) is controled by the application.

      #Driver_SPI

 SPI Master Driver for AVR ATmega8

       ##Design Goal

 This driver is intended to serve as reusable SPI communication layer for periferal device drivers.
 It is independent of any specific SPI device and provides configurable clock frequency, SPI Mode and Bit Order

       ##Architecture:
[Application]-->[Device Driver]-->[**Driver_SPI**]-->[SPI HardWare(Atmega8)]

       ##Features

 - Bare-metal implementation
 - Configurable SPI clock
 - Configurable SPI Mode (0-3)
 - Configurable Bit Order (MSB first/LSB first)
 - SPI Master Mode
 - Full duplex communication
 - No external libraries
 - Design for reusable periferal drive

       ##Folder Structure

 - include/  - Header files
 - src/      - Source files
 - examples/ - Usage examples
 - docs/     - Documentation

       ##NOTE

 The SPI driver does not control the Chip Select (CS/SS) pin. Chip Select managment is the
 responsibility of the device driver or the application.
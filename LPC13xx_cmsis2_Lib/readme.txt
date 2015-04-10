LPC13xx_cmsis2_Lib
==================

This library project contains code to handle various peripherals contained
in the LPC13xx.

Several files have been modified slightly from the original NXP sources to
comment out application specific code (mainly the interrupt handlers).

This means that the library project only contains the common code. Interrupt
handlers are moved into projects making use of the peripherals.

The project makes use of code from the following library project:
- CMSISv2p00_LPC13xx : for CMSIS 2.00 files relevant to LPC13xx



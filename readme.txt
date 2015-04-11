This is an LPCXpresso project for the LPC1343 that is being used on an RGBW Lamp for a PKI IEEE project Spring 2015. The lamp also uses an ESP8266 Wifi module.

Function Descriptions:

void setRed(uint8_t setValue);
Sets the red LED. Takes uint8_t value from 0 to 255 which controls the
brightness of the LED.
Example use:
	setRed(128) // sets red led to medium brightness

void setGreen(uint8_t setValue);
Sets the green LED. Takes uint8_t value from 0 to 255 which controls the
brightness of the LED.
Example use:
	setGreen(128) // sets green led to medium brightness

void setBlue(uint8_t setValue);
Sets the blue LED. Takes uint8_t value from 0 to 255 which controls the
brightness of the LED.
Example use:
	setBlue(128) // sets blue led to medium brightness

void setWhite(uint8_t setValue);
Sets the white LED. Takes uint8_t value from 0 to 255 which controls the
brightness of the LED.
Example use:
	setWhite(128) // sets white led to medium brightness

void setColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t white);
Sets all 4 LEDs at once. Can be used to blend the LED colors.
Takes four uint8_t value from 0 to 255 which control the
brightness of the LEDs.
Example use:
	setColor(255, 255, 0, 0); // sets lamp to produce yellow color at full brightness

void testRed();
Brings the red led from off to full brightness in about 13 seconds.
	Example use:
		testRed();

void testGreen();
Brings the green led from off to full brightness in about 13 seconds.
	Example use:
		testGreen();

void testBlue();
Brings the blue led from off to full brightness in about 13 seconds.
	Example use:
		testBlue();

void testWhite();
Brings the white led from off to full brightness in about 13 seconds.
	Example use:
		testWhite();

void delay_us(uint32_t delay);
Uses TMR16B0 to create a delay in us.
	Example use:
		delay_us(1000); // delays for 1000 us

void delay_ms(uint32_t delay);
Uses delay_us function in a loop to create delay in ms
	Example use:
		delay_ms(1000); // delays for 1 second
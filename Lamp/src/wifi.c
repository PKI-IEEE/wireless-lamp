#include "lamp.h"

struct ipStc {
	uint8_t b1;
	uint8_t b2;
	uint8_t b3;
	uint8_t b4;
};

void wifiConnect() {
	unsigned char setMode[] = "wifi.setmode(wifi.STATION)";
	unsigned char staConfig[] = "wifi.sta.config(\"YOUR SSID\",\"YOUR PASSWORD\")"; // enter your network SSID and password. Notice the escaped quotes. SSID and password must be in quotes
	unsigned char staConnect[] = "wifi.sta.connect()";
	unsigned char CRLF[2] = {0x0D, 0x0A};

	UARTSend(setMode,sizeof(setMode)-1);
	UARTSend(CRLF,2);
	delay_us(100);
	UARTSend(staConfig,sizeof(staConfig)-1);
	UARTSend(CRLF,2);
	delay_us(100);
	UARTSend(staConnect,sizeof(staConnect)-1);
	UARTSend(CRLF,2);
	delay_us(100);
}

struct ipStc getIp() {
	NVIC_DisableIRQ(UART_IRQn); // disable UART interrupt
	uint8_t LSRValue;
	uint8_t index = 0;
	char buffer[16];
	struct ipStc ipAddress;
	ipAddress.b1 = 0;
	ipAddress.b2 = 0;
	ipAddress.b3 = 0;
	ipAddress.b4 = 0;
	unsigned char getIp[] = "=wifi.sta.getip()";

	unsigned char CRLF[2] = {0x0D, 0x0A};


	UARTSend(getIp,sizeof(getIp)-1);
	UARTSend(CRLF,2);
	delay_ms(500); // give ESP8266 time to send IP to FIFO

	uint8_t i;
	for(i=0;i<16;i++) { // read all 16 bytes from FIFO
		LSRValue = LPC_UART->LSR;
		if (LSRValue & 0x01)	{
			buffer[index++] = LPC_UART->RBR;
		}
	}

	index = 0;
	if(buffer[0] != 'n') {
		char *ipSection = strtok(buffer, ".");
		while(ipSection) {
			if(index == 0) {
				ipAddress.b1 = atoi(ipSection);
			}
			else if(index == 1) {
				ipAddress.b2 = atoi(ipSection);
			}
			else if(index == 2) {
				ipAddress.b3 = atoi(ipSection);
			}
			else if(index == 3) {
				ipAddress.b4 = atoi(ipSection);
			}
			index++;
			ipSection = strtok(NULL, ".");

		}
}

	NVIC_EnableIRQ(UART_IRQn); // enable UART interrupt
	return ipAddress;

}

void blinkIp(struct ipStc ipAddress) {

	uint8_t hundreds = ipAddress.b1 / 100;
	uint8_t tens = (ipAddress.b1 - (hundreds*100)) / 10;
	uint8_t ones = (ipAddress.b1 - (hundreds*100)) - (tens * 10);
	uint8_t i = 0;
	if(hundreds != 0) {
		for(i=0;i<hundreds;i++) {
			blinkRed();
		}
	}
	if(tens != 0) {
		delay_ms(500);
		for(i=0;i<tens;i++) {
			blinkBlue();
		}
	}
	if(ones != 0) {
		delay_ms(500);
		for(i=0;i<ones;i++) {
			blinkGreen();
		}
	}

	blinkWhite();
	delay_ms(500);
	//-----------Second Number------------------------------//
	hundreds = ipAddress.b2 / 100;
	tens = (ipAddress.b2 - (hundreds*100)) / 10;
	ones = (ipAddress.b2 - (hundreds*100)) - (tens * 10);

	if(hundreds != 0) {
		for(i=0;i<hundreds;i++) {
			blinkRed();
		}
	}
	if(tens != 0) {
		delay_ms(500);
		for(i=0;i<tens;i++) {
			blinkBlue();
		}
	}
	if(ones != 0) {
		delay_ms(500);
		for(i=0;i<ones;i++) {
			blinkGreen();
		}
	}

	blinkWhite();
	delay_ms(500);
	//-----------Third Number------------------------------//
	hundreds = ipAddress.b3 / 100;
	tens = (ipAddress.b3 - (hundreds*100)) / 10;
	ones = (ipAddress.b3 - (hundreds*100)) - (tens * 10);

	if(hundreds != 0) {
		for(i=0;i<hundreds;i++) {
			blinkRed();
		}
	}
	if(tens != 0) {
		delay_ms(500);
		for(i=0;i<tens;i++) {
			blinkBlue();
		}
	}
	if(ones != 0) {
		delay_ms(500);
		for(i=0;i<ones;i++) {
			blinkGreen();
		}
	}

	blinkWhite();
	delay_ms(500);

	//-----------Fourth Number------------------------------//
	hundreds = ipAddress.b4 / 100;
	tens = (ipAddress.b4 - (hundreds*100)) / 10;
	ones = (ipAddress.b4 - (hundreds*100)) - (tens * 10);

	if(hundreds != 0) {
		for(i=0;i<hundreds;i++) {
			blinkRed();
		}
	}
	if(tens != 0) {
		delay_ms(500);
		for(i=0;i<tens;i++) {
			blinkBlue();
		}
	}
	if(ones != 0) {
		delay_ms(500);
		for(i=0;i<ones;i++) {
			blinkGreen();
		}
	}

	setRed(100);
	setBlue(100);
	delay_ms(600);
	setRed(0);
	setBlue(0);
}












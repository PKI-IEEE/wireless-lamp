#include "lamp.h"
void wifiConnect() {
	unsigned char setMode[] = "wifi.setmode(wifi.STATION)";
	unsigned char staConfig[] = "wifi.sta.config(\"YOUR SSID\",\"NETWORK PASSWORD\")"; // enter your network SSID and password. Notice the escaped quotes. SSID and password must be in quotes
	unsigned char staConnect[] = "wifi.sta.connect()";
	unsigned char CRLF[2] = {0x0D, 0x0A};;

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


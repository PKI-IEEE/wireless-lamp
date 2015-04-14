#include "lamp.h"


const int gamma_table[256] = {
0x23411, 	0x23410, 	0x2340C, 	0x23404, 	0x233FA, 	0x233EC, 	0x233DA, 	0x233C5, 	0x233AC, 	0x23390, 	0x23370, 	0x2334D, 	0x23325, 	0x232FA, 	0x232CB, 	0x23299,
0x23262, 	0x23227, 	0x231E9, 	0x231A7, 	0x23160, 	0x23116, 	0x230C8, 	0x23075, 	0x2301F, 	0x22FC5, 	0x22F66, 	0x22F04, 	0x22E9D, 	0x22E32, 	0x22DC3, 	0x22D50,
0x22CD9, 	0x22C5E, 	0x22BDE, 	0x22B5B, 	0x22AD3, 	0x22A47, 	0x229B6, 	0x22922, 	0x22889, 	0x227EC, 	0x2274A, 	0x226A4, 	0x225FA, 	0x2254C, 	0x2249A, 	0x223E3,
0x22327, 	0x22268, 	0x221A4, 	0x220DC, 	0x2200F, 	0x21F3E, 	0x21E68, 	0x21D8F, 	0x21CB0, 	0x21BCE, 	0x21AE7, 	0x219FB, 	0x2190B, 	0x21817, 	0x2171E, 	0x21621,
0x2151F, 	0x21419, 	0x2130F, 	0x211FF, 	0x210EC, 	0x20FD4, 	0x20EB7, 	0x20D96, 	0x20C70, 	0x20B46, 	0x20A18, 	0x208E4, 	0x207AD, 	0x20670, 	0x20530, 	0x203EA,
0x202A0, 	0x20152, 	0x1FFFF, 	0x1FEA7, 	0x1FD4B, 	0x1FBEA, 	0x1FA84, 	0x1F91A, 	0x1F7AC, 	0x1F638, 	0x1F4C0, 	0x1F344, 	0x1F1C3, 	0x1F03D, 	0x1EEB3, 	0x1ED24,
0x1EB90, 	0x1E9F7, 	0x1E85A, 	0x1E6B9, 	0x1E512, 	0x1E367, 	0x1E1B8, 	0x1E003, 	0x1DE4A, 	0x1DC8D, 	0x1DACA, 	0x1D903, 	0x1D737, 	0x1D567, 	0x1D391, 	0x1D1B7,
0x1CFD9, 	0x1CDF5, 	0x1CC0D, 	0x1CA20, 	0x1C82F, 	0x1C638, 	0x1C43D, 	0x1C23D, 	0x1C039, 	0x1BE2F, 	0x1BC21, 	0x1BA0E, 	0x1B7F7, 	0x1B5DA, 	0x1B3B9, 	0x1B193,
0x1AF68, 	0x1AD39, 	0x1AB04, 	0x1A8CB, 	0x1A68D, 	0x1A44B, 	0x1A203, 	0x19FB7, 	0x19D65, 	0x19B0F, 	0x198B5, 	0x19655, 	0x193F0, 	0x19187, 	0x18F19, 	0x18CA6,
0x18A2E, 	0x187B2, 	0x18530, 	0x182AA, 	0x1801E, 	0x17D8E, 	0x17AF9, 	0x17860, 	0x175C1, 	0x1731D, 	0x17075, 	0x16DC8, 	0x16B16, 	0x1685F, 	0x165A3, 	0x162E2,
0x1601C, 	0x15D51, 	0x15A82, 	0x157AD, 	0x154D4, 	0x151F6, 	0x14F13, 	0x14C2B, 	0x1493E, 	0x1464C, 	0x14355, 	0x14059, 	0x13D58, 	0x13A53, 	0x13748, 	0x13439,
0x13124, 	0x12E0B, 	0x12AED, 	0x127C9, 	0x124A1, 	0x12174, 	0x11E42, 	0x11B0B, 	0x117CF, 	0x1148E, 	0x11148, 	0x10DFD, 	0x10AAD, 	0x10758, 	0x103FE, 	0x1009F,
0x0FD3C, 	0x0F9D3, 	0x0F665, 	0x0F2F2, 	0x0EF7A, 	0x0EBFD, 	0x0E87C, 	0x0E4F5, 	0x0E169, 	0x0DDD8, 	0x0DA42, 	0x0D6A8, 	0x0D308, 	0x0CF63, 	0x0CBB9, 	0x0C80A,
0x0C456, 	0x0C09D, 	0x0BCDF, 	0x0B91C, 	0x0B554, 	0x0B187, 	0x0ADB5, 	0x0A9DE, 	0x0A602, 	0x0A220, 	0x09E3A, 	0x09A4F, 	0x0965E, 	0x09269, 	0x08E6E, 	0x08A6F,
0x0866A, 	0x08260, 	0x07E52, 	0x07A3E, 	0x07625, 	0x07207, 	0x06DE4, 	0x069BC, 	0x0658F, 	0x0615C, 	0x05D25, 	0x058E8, 	0x054A7, 	0x05060, 	0x04C15, 	0x047C4,
0x0436E, 	0x03F13, 	0x03AB3, 	0x0364D, 	0x031E3, 	0x02D74, 	0x028FF, 	0x02485, 	0x02007, 	0x01B83, 	0x016FA, 	0x0126C, 	0x00DD8, 	0x00940, 	0x004A3, 	0x00000 };

void setRed(uint8_t setValue) {
	float set = (float)setValue;
	float brightness = 1-(set / 255);
	float dutyCycle = 144400 * brightness;
	PWM_R = (uint32_t)(dutyCycle);
}

void setGreen(uint8_t setValue) {
	float set = (float)setValue;
	float brightness = 1-(set / 255);
	float dutyCycle = 144400 * brightness;
	PWM_G = (uint32_t)(dutyCycle);
}

void setBlue(uint8_t setValue) {
	float set = (float)setValue;
	float brightness = 1-(set / 255);
	float dutyCycle = 144400 * brightness;
	PWM_B = (uint32_t)(dutyCycle);
}

void setWhite(uint8_t setValue) {
	float set = (float)setValue;
	float brightness = 1-(set / 255);
	float dutyCycle = 144400 * brightness;
	PWM_W = (uint32_t)(dutyCycle);
}

void setColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t white) {
	setRed(red);
	setGreen(green);
	setBlue(blue);
	setWhite(white);
}

void testRed() {
	uint8_t i;
	for(i=0;i<255;i++) {
		setRed(i);
		delay_ms(50);
	}
	setRed(0);
}

void testGreen() {
	uint8_t i;
	for(i=0;i<255;i++) {
		setGreen(i);
		delay_ms(50);
	}
	setGreen(0);
}

void testBlue() {
	uint8_t i;
	for(i=0;i<255;i++) {
		setBlue(i);
		delay_ms(50);
	}
	setBlue(0);
}

void testWhite() {
	uint8_t i;
	for(i=0;i<255;i++) {
		setWhite(i);
		delay_ms(50);;
	}
	setWhite(0);
}

void blinkBlue() {
	setBlue(50);
	delay_ms(500);
	setBlue(0);
	delay_ms(500);
}

void blinkGreen() {
	setGreen(50);
	delay_ms(500);
	setGreen(0);
	delay_ms(500);
}

void blinkRed() {
	setRed(50);
	delay_ms(500);
	setRed(0);
	delay_ms(500);
}

void blinkWhite() {
	setWhite(50);
	delay_ms(500);
	setWhite(0);
	delay_ms(500);
}

void colorWheel(uint32_t delay) {
	int c = 0;
	while(c < 0x300) {


		int r = 0;
		int g = 0;
		int b = 0;

		if (c < 0x100)
			{
				g = c;
				r = 0xFF - c;
			}
			else if (c < 0x200)
			{
				b = c - 0x100;
				g = 0x1FF - c;
			}
			else if (c < 0x300)
			{
				r = c - 0x200;
				b = 0x2FF - c;
			}
			else
			{
				r = g = b = 0xFF;
			}

		PWM_R = gamma_table[r];
		PWM_G = gamma_table[g];
		PWM_B = gamma_table[b];
		PWM_W = 144400;

		c+=5;
		delay_ms(delay);
	}

}



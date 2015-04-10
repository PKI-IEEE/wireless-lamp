#include "LPC13xx.h"
#include "clkconfig.h"
#include "gpio.h"
#include "uart.h"
#include "led.h"
#include <cr_section_macros.h>
#include <NXP/crp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wifi.h"

void PWMInit();
void lampInit();
void delay_us(uint32_t delay);
void delay_ms(uint32_t delay);

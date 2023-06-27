

#ifndef PIBBY_LCD_INIT_H
#define PIBBY_LCD_INIT_H

#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "hardware/spi.h"
#include "stdio.h"

#include "GPIO.h"

void Init_Pins();
void Init_Pin(uint, bool);
void Init_SPI();
void Set_Pin(uint, bool);

#endif

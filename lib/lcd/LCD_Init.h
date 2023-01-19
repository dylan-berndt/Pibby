

#ifndef PIBBY_LCD_INIT_H
#define PIBBY_LCD_INIT_H

#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "hardware/spi.h"
#include "stdio.h"

#define X_PIN 26
#define Y_PIN 27

#define A_PIN 7
#define B_PIN 6

#define LCD_RST_PIN		15
#define LCD_DC_PIN		8
#define LCD_CS_PIN		9
#define LCD_CLK_PIN		10
#define LCD_BKL_PIN		13
#define LCD_MOSI_PIN	11
#define LCD_MISO_PIN	12
#define TP_CS_PIN		16
#define TP_IRQ_PIN		17
#define SD_CS_PIN		22

#define SPI_PORT spi1

#define IN true
#define OUT false

void Init_Pins();
void Init_Pin(uint, bool);
void Init_SPI();

#endif

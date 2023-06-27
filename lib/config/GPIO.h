//
// Created by dylan on 6/26/2023.
//

#ifndef PIBBY_GPIO_H
#define PIBBY_GPIO_H

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


////////////////////////////////////////////////////////////////////


#define NO_COMMAND 0x00

#define SLEEP_IN 0x10
#define SLEEP_OUT 0x11

#define DISPLAY_INVERSION_ON 0x21

#define MEMORY_ACCESS_CONTROL 0x36

#define INTERFACE_PIXEL_FORMAT 0x3A

#define RGB_16 0b01010000
#define RGB_18 0b01100000
#define RGB_24 0b01110000

#define MCU_3 0b00000001
#define MCU_16 0b00000101
#define MCU_18 0b00000110
#define MCU_24 0b00000111

#define FRAME_RATE_8COL 0xB1
#define FRAME_RATE_FULL 0xB2
#define DISPLAY_FUNCTION_CONTROL 0xB6
#define ENTRY_MODE_SET 0xB7

#define POWER_CONTROL_1 0xC0
#define POWER_CONTROL_2 0xC1
#define POWER_CONTROL_3 0xC2
#define POWER_CONTROL_4 0xC3
#define POWER_CONTROL_5 0xC4

#define VCOM_CONTROL 0xC5

#define CABC_CONTROL 0xC6
#define NV_MEMORY_WRITE 0xD0

#define POSITIVE_GAMMA_CONTROL 0xE0
#define NEGATIVE_GAMMA_CONTROL 0xE1

#define BRIGHTNESS_ADAPTIVE_CONTROL 0x55
#define DISPLAY_ON 0x29

#define COLUMN_ADDRESS_SET 0x2A
#define PAGE_ADDRESS_SET 0x2B
#define MEMORY_WRITE 0x2C
#define MEMORY_READ 0x2E

#define SCREEN_WIDTH 480
#define SCREEN_HEIGHT 320
#define SCREEN_SIZE SCREEN_HEIGHT * SCREEN_WIDTH


void Set_Pin(uint, bool);
uint8_t Write_Byte(uint8_t);

#endif
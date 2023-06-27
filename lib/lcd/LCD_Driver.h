

#ifndef PIBBY_LCD_DRIVER_H
#define PIBBY_LCD_DRIVER_H

#include "pico/stdlib.h"
#include "LCD_Init.h"
#include "hardware/spi.h"

void Begin_Command();
void Begin_Write();
uint8_t Write(uint8_t);
void End_Write();
uint8_t Write_Command(uint8_t);
uint8_t Write_Byte(uint8_t);
void Write_Unit(uint16_t);
void Write_Screen();
void Write_To_Buffer(uint16_t, uint16_t, uint8_t);
void Write_Exact_To_Buffer(uint16_t, uint16_t, uint8_t);
void Clear_Buffer(uint8_t);

void Hardware_Reset();
void Init_Board();

#endif

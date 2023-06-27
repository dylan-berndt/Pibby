

#ifndef PIBBY_LCD_INPUT_H
#define PIBBY_LCD_INPUT_H

#include "LCD_Init.h"

uint16_t JoyStick_X();
uint16_t JoyStick_Y();

uint8_t Touch_X();
uint8_t Touch_Y();

bool Press_A();
bool Press_B();

#endif

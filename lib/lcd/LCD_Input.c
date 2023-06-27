

#include "LCD_Input.h"

uint16_t JoyStick_X() {
    adc_select_input(0);
    const uint16_t result = adc_read();

    return result;
}

uint16_t JoyStick_Y() {
    adc_select_input(1);
    const uint16_t result = adc_read();

    return result;
}

uint8_t Touch_X() {
    return 0;
}

uint8_t Touch_Y() {
    return 0;
}

bool Press_A() {
    return gpio_get(A_PIN);
}

bool Press_B() {
    return gpio_get(B_PIN);
}

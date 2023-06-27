//
// Created by dylan on 6/26/2023.
//

#include "GPIO.h"

void Set_Pin(uint p, bool b) {
    gpio_put(p, b);
}


///// FUCKING HORSESHIT
uint8_t Write_Byte(uint8_t b) {
    gpio_put(LCD_DC_PIN, 1);
    gpio_put(LCD_CS_PIN, 0);
    uint8_t rxdata = spi_write_read_blocking(spi1, &b, &rxdata, 1);
    gpio_put(LCD_CS_PIN, 1);
    return rxdata;
}

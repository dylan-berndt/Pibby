

#include "LCD_Driver.h"

void Begin_Command() {
    gpio_put(LCD_DC_PIN, 0);
    gpio_put(LCD_CS_PIN, 0);
}

void Begin_Write() {
    gpio_put(LCD_DC_PIN, 1);
    gpio_put(LCD_CS_PIN, 0);
}

uint8_t Write(uint8_t b) {
    uint8_t rxdata;
    spi_write_read_blocking(spi1, &b, &rxdata, 1);
    return rxdata;
}

void End_Write() {
    gpio_put(LCD_CS_PIN, 1);
}

uint8_t Write_Command(uint8_t b) {
    Begin_Command();
    uint8_t rxdata = Write(b);
    End_Write();
    return rxdata;
}

uint8_t Write_Byte(uint8_t b) {
    Begin_Write();
    uint8_t rxdata = Write(b);
    End_Write();
    return rxdata;
}

void Write_Unit(uint16_t b) {
    Begin_Write();
    Write(b << 8);
    Write(b & 0xFF);
    End_Write();
}

void Hardware_Reset() {
    gpio_put(LCD_RST_PIN, 1);
    sleep_ms(250);
    gpio_put(LCD_RST_PIN, 0);
    sleep_ms(250);
    gpio_put(LCD_RST_PIN, 1);
    sleep_ms(250);

}

void Init_Board() {
    Init_Pins();

    Hardware_Reset();

    Write_Command(DISPLAY_INVERSION_ON);
    
    Write_Command(POWER_CONTROL_3);
    Write_Byte(0x33);

    Write_Command(VCOM_CONTROL);
    Write_Byte(0x00);
    Write_Byte(0x1e);//VCM_REG[7:0]. <=0X80.
    Write_Byte(0x80);

    Write_Command(FRAME_RATE_8COL);
    Write_Byte(0xB0);

    Write_Command(MEMORY_ACCESS_CONTROL);
    Write_Byte(0x28);

    Write_Command(POSITIVE_GAMMA_CONTROL);
    Write_Byte(0x0);
    Write_Byte(0x13);
    Write_Byte(0x18);
    Write_Byte(0x04);
    Write_Byte(0x0F);
    Write_Byte(0x06);
    Write_Byte(0x3a);
    Write_Byte(0x56);
    Write_Byte(0x4d);
    Write_Byte(0x03);
    Write_Byte(0x0a);
    Write_Byte(0x06);
    Write_Byte(0x30);
    Write_Byte(0x3e);
    Write_Byte(0x0f);

    Write_Command(NEGATIVE_GAMMA_CONTROL);
    Write_Byte(0x0);
    Write_Byte(0x13);
    Write_Byte(0x18);
    Write_Byte(0x01);
    Write_Byte(0x11);
    Write_Byte(0x06);
    Write_Byte(0x38);
    Write_Byte(0x34);
    Write_Byte(0x4d);
    Write_Byte(0x06);
    Write_Byte(0x0d);
    Write_Byte(0x0b);
    Write_Byte(0x31);
    Write_Byte(0x37);
    Write_Byte(0x0f);

    Write_Command(INTERFACE_PIXEL_FORMAT);
    Write_Byte(RGB_16 | MCU_16);

    Write_Command(SLEEP_OUT);
    sleep_ms(120);

    Write_Command(DISPLAY_ON);
}

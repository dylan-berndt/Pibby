

#include "LCD_Driver.h"

#define PIXEL_SIZE (uint8_t) 4
#define BUFFER_SIZE (480 * 160 / (PIXEL_SIZE * PIXEL_SIZE))

uint8_t BUFFER[BUFFER_SIZE];
const uint16_t R = 0b1111000000000000;
const uint16_t G = 0b0000111111100000;
const uint16_t B = 0b0000000000011111;

const uint32_t PALETTE[] = {0, R, G, B, R | G, R | B, G | B, R | G | B};

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
    Write(b >> 8);
    Write(b & 0xFF);
    End_Write();
}

void Clear_Buffer(uint8_t c) {
    uint8_t c_ = c | c << 4;
    for (uint32_t i = 0; i < BUFFER_SIZE; i++) {
        BUFFER[i] = c_;
    }
}

void Write_Screen() {
    Begin_Write();

    uint16_t row;
    uint32_t col;
    uint8_t b;
    uint32_t c;

    for (uint32_t i = 0; i < SCREEN_SIZE; i += PIXEL_SIZE) {
        row = (i % 320) / PIXEL_SIZE;
        col = 320 * (i / (320 * PIXEL_SIZE)) / (PIXEL_SIZE);
        b = BUFFER[(col + row) / 2];

        if ((i / PIXEL_SIZE) & 1) {
            c = PALETTE[b & 15];
        }
        else {
            c = PALETTE[b >> 4];
        }

        uint8_t c1 = c >> 8;
        uint8_t c2 = c & 0xFF;

        for (size_t p = 0; p < PIXEL_SIZE; p++) {
            while (!spi_is_writable(spi1))
                tight_loop_contents();

            spi1_hw->dr = c1;
            spi1_hw->dr = c2;
        }
    }

    while (spi_is_readable(spi1))
        (void)spi1_hw->dr;
    while (spi1_hw->sr & SPI_SSPSR_BSY_BITS)
        tight_loop_contents();
    while (spi_is_readable(spi1))
        (void)spi1_hw->dr;

    spi1_hw->icr = SPI_SSPICR_RORIC_BITS;

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

    Write_Command(FRAME_RATE_FULL);
    Write_Byte(0xB0);

    Write_Command(MEMORY_ACCESS_CONTROL);
    Write_Byte(0x08);

    Write_Command(DISPLAY_FUNCTION_CONTROL);
    Write_Byte(0x00);
    Write_Byte(0x22);

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
    Write_Byte( MCU_16);

    Write_Command(SLEEP_OUT);
    sleep_ms(120);

    Write_Command(DISPLAY_ON);
}

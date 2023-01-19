

#include "LCD_Init.h"

void Init_Pin(uint p, bool b) {
    gpio_init(p);
    gpio_set_dir(p, b ? GPIO_IN : GPIO_OUT);
}

void Init_SPI() {
    spi_init(SPI_PORT,4000000);
    gpio_set_function(LCD_CLK_PIN,GPIO_FUNC_SPI);
    gpio_set_function(LCD_MOSI_PIN,GPIO_FUNC_SPI);
    gpio_set_function(LCD_MISO_PIN,GPIO_FUNC_SPI);
}

void Init_Pins() {
    adc_init();
    stdio_init_all();

    adc_gpio_init(X_PIN);
    adc_gpio_init(Y_PIN);

    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    Init_Pin(A_PIN, IN);
    Init_Pin(B_PIN, IN);

    Init_Pin(LCD_RST_PIN,OUT);
    Init_Pin(LCD_DC_PIN, OUT);
    Init_Pin(LCD_BKL_PIN, OUT);
    Init_Pin(LCD_CS_PIN, OUT);
    Init_Pin(TP_CS_PIN,OUT);
    Init_Pin(TP_IRQ_PIN,IN);
    Init_Pin(SD_CS_PIN,OUT);
    gpio_set_pulls(TP_IRQ_PIN,true,false);

    gpio_put(TP_CS_PIN, 1);
    gpio_put(LCD_CS_PIN, 1);
    gpio_put(LCD_BKL_PIN, 1);
    gpio_put(SD_CS_PIN, 1);

    Init_SPI();
}

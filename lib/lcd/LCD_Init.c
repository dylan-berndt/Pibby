

#include "LCD_Init.h"

void Init_Pins() {
    adc_init();
    stdio_init_all();

    adc_gpio_init(X_PIN);
    adc_gpio_init(Y_PIN);

    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    gpio_init(A_PIN);
    gpio_init(B_PIN);

    gpio_set_dir(A_PIN, GPIO_IN);
    gpio_set_dir(B_PIN, GPIO_IN);
}


#include "LCD_Input.h"

int main() {
    Init_Pins();

    while (true) {
        printf("X: %u", (unsigned int) JoyStick_X());
    }
}

#include "LCD_Driver.h"
#include "LCD_Input.h"

int main() {
    Init_Board();

    while (true) {
        printf("X: %u \n", (unsigned int) JoyStick_X());
    }
}
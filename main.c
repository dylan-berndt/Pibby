
#include "LCD_GUI.h"
#include "math.h"

int main() {
    Init_Board();

    while (true) {
        absolute_time_t t = get_absolute_time();
        Clear_Buffer(0);

        Draw_Screen();
        int64_t time_diff = absolute_time_diff_us(t, get_absolute_time());
        double fps = 1 / ((float)time_diff / 1000000.0f);
        printf("FPS : %f \n", (double) fps);
    }
}
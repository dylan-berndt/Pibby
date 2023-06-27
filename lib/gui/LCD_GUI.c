
#include "LCD_GUI.h"
#include "PMP.h"

void Draw_Image(PMP image, uint16_t x, uint16_t y) {

}

void Draw_Screen() {
    Vector start = {0, 0};
    Vector end = {480, 320};
    Set_Draw_Bounds(start, end);
    Write_Command(MEMORY_WRITE);
    Write_Screen();
}

void Set_Draw_Bounds(Vector start, Vector end) {
    Write_Command(COLUMN_ADDRESS_SET);
    Write_Unit(start.x);
    Write_Unit(end.x);

    Write_Command(PAGE_ADDRESS_SET);
    Write_Unit(start.y);
    Write_Unit(end.y);
}

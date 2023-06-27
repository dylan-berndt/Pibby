aux_source_directory(. DIR_LCD_SRCS)

include_directories(../utils)
include_directories(../config)

add_library(lcd ${DIR_LCD_SRCS})
target_link_libraries(lcd PUBLIC utils hardware_adc pico_stdlib hardware_spi)
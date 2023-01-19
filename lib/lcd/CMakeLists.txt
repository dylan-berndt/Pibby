aux_source_directory(. DIR_LCD_SRCS)

add_library(lcd ${DIR_LCD_SRCS})
target_link_libraries(lcd PUBLIC hardware_adc pico_stdlib hardware_spi)
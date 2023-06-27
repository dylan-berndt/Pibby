aux_source_directory(. DIR_GUI_SRCS)

include_directories(../lcd)
include_directories(../utils)
include_directories(../config)
include_directories(../pmp)

add_library(gui ${DIR_GUI_SRCS})
target_link_libraries(gui PUBLIC utils hardware_adc pico_stdlib hardware_spi lcd pmp)
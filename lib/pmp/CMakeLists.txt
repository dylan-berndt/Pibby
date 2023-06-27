aux_source_directory(. DIR_PMP_SRCS)

include_directories(../utils)
include_directories(../config)
include_directories(../sdcard)
include_directories(../fatfs)

add_library(pmp ${DIR_PMP_SRCS})
target_link_libraries(pmp PUBLIC utils config hardware_adc pico_stdlib hardware_spi fatfs)
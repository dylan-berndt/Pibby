aux_source_directory(. DIR_CONFIG_SRCS)

add_library(config ${DIR_CONFIG_SRCS})
target_link_libraries(config PUBLIC hardware_adc pico_stdlib hardware_spi)
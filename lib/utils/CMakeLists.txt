aux_source_directory(. DIR_UTILS_SRCS)

add_library(utils ${DIR_UTILS_SRCS})
target_link_libraries(utils PUBLIC pico_stdlib)
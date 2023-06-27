cmake_minimum_required(VERSION 3.12)
include(pico_sdk_import.cmake)

set(PROJECT_NAME Pibby)

enable_language(C CXX ASM)

project(${PROJECT_NAME})
pico_sdk_init()

add_subdirectory(lib/lcd)
add_subdirectory(lib/utils)
add_subdirectory(lib/sdcard)
add_subdirectory(lib/fatfs)
add_subdirectory(lib/config)
add_subdirectory(lib/gui)
add_subdirectory(lib/pmp)

include_directories(./lib/pmp)
include_directories(./lib/lcd)
include_directories(./lib/utils)
include_directories(./lib/sdcard)
include_directories(./lib/fatfs)
include_directories(./lib/config)
include_directories(./lib/gui)

add_executable(${PROJECT_NAME} main.c)

pico_enable_stdio_usb(${PROJECT_NAME} 1)
pico_enable_stdio_uart(${PROJECT_NAME} 0)

pico_add_extra_outputs(${PROJECT_NAME})

#target_link_libraries(LCD pmp lcd utils pico_stdlib)

target_link_libraries(${PROJECT_NAME} lcd utils hardware_adc pico_stdlib sdcard fatfs config gui pmp)

#target_link_libraries(${PROJECT_NAME} lcd utils hardware_adc pico_stdlib)

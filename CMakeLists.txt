cmake_minimum_required(VERSION 3.13)

include(pico-sdk/pico_sdk_init.cmake)

project(lightItUp)
pico_sdk_init()

add_executable(blink main.c)
target_link_libraries(blink pico_stdlib)
pico_add_extra_outputs(blink)

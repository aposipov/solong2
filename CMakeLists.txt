cmake_minimum_required(VERSION 3.21)
project(solong2 C)

set(CMAKE_C_STANDARD 99)

add_executable(solong2 src/get_next_line.c src/get_next_line_utils.c
        src/so_long.c src/check.c src/draw.c src/search.c
        src/movements.c src/utils.c)

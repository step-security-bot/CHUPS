cmake_minimum_required(VERSION 3.0)

project(CHUPS)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")
set(CMAKE_COMPILER_IS_GNUCC TRUE)

set(SRCS
    src/main.c
    src/textcolor.c
    src/common.c
    src/host.c
    )

set(HEADERS
    include/textcolor.h
    include/common.h
    include/host.h
    )

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
add_executable(CHUPS ${SRCS} ${HEADERS})
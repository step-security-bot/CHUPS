cmake_minimum_required(VERSION 3.0)

project(CHUPS)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-g -O0 -Wall --std=c11")
set(CMAKE_COMPILER_IS_GNUCC TRUE)

set(SRCS
    src/main.c
    src/textcolor.c
    src/common.c
    src/host.c
    src/synack.c
    src/icmp.c
    src/menu.c
    src/file.c
    src/logs.c
    )

set(HEADERS
    include/textcolor.h
    include/common.h
    include/host.h
    include/synack.h
    include/icmp.h
    include/menu.h
    include/file.h
    include/logs.h
    )

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
add_executable(CHUPS ${SRCS} ${HEADERS})

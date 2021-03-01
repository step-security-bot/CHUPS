cmake_minimum_required(VERSION 3.0)

project(CHUPS)

set(SRCS
    src/main.c
    )

set(HEADERS

    )


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
add_executable(CHUPS ${SRCS} ${HEADERS})
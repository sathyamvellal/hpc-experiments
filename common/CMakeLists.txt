cmake_minimum_required(VERSION 3.9)
project(${CMAKE_PROJECT_NAME}-common)

set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

set(HELLO_SRC
        src/hello.cpp)

add_library(hpc-common STATIC
        ${HELLO_SRC})
add_library(hpc-util STATIC src/util.cpp)
add_library(hpc-random3 STATIC src/random3.cpp)

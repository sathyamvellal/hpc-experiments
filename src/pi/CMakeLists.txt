cmake_minimum_required(VERSION 3.9)
project(${CMAKE_PROJECT_NAME}-pi)

set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

set(PI_SEQ_SRC
        pi_seq.cpp)

add_library(${PROJECT_NAME} STATIC
        ${PI_SEQ_SRC})

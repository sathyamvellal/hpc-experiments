cmake_minimum_required(VERSION 3.8)
project(hpc-experiments)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_BUILD_DIR ${CMAKE_SOURCE_DIR}/build)
set(CMAKE_BINARY_DIR  ${CMAKE_BUILD_DIR}/bin)
set(CMAKE_TESTS_BINARY_DIR ${CMAKE_BINARY_DIR}/test)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

set(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(COMMON_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/common/include)

include_directories(${PROJECT_INCLUDE_DIR})
include_directories(${PROJECT_SOURCE_DIR})
include_directories(${COMMON_INCLUDE_DIR})

find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()

# Common code, packaged as a library
add_subdirectory(common)

# Sub-projects, packaged as libraries
add_subdirectory(src/pi)

# Tests for Sub-projects, as execiutables
add_subdirectory(test)
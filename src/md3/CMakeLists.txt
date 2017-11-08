cmake_minimum_required(VERSION 3.9)
project(${CMAKE_PROJECT_NAME}-pi)

set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

function(create_add_library name)
    add_library(${name} STATIC ${name}.cpp)
endfunction(create_add_library)

create_add_library(md_seq)

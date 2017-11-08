cmake_minimum_required(VERSION 3.9)
project(${CMAKE_PROJECT_NAME}-test-pi)

set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

function(create_add_executable suffix)
    add_executable(test_${suffix} test_${suffix}.cpp)
    target_link_libraries(test_${suffix} util random ${suffix} ${ARGV1})
endfunction(create_add_executable)

create_add_executable(md_seq)

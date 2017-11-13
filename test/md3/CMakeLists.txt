cmake_minimum_required(VERSION 3.9)
project(${CMAKE_PROJECT_NAME}-test-pi)

set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

function(create_add_executable prefix name)
    add_executable(test-${prefix}-${name} test-${name}.cpp)
    target_link_libraries(test-${prefix}-${name} ${prefix}-${name} hpc-util hpc-random3 hpc-common ${ARGV2})
endfunction(create_add_executable)

create_add_executable(md3 md_seq)

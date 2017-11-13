cmake_minimum_required(VERSION 3.9)
project(${CMAKE_PROJECT_NAME}-test-pi)

set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

function(create_add_executable prefix name)
    add_executable(test-${prefix}-${name} test-${name}.cpp)
    target_link_libraries(test-${prefix}-${name} ${prefix}-${name} hpc-common ${ARGV2})
endfunction(create_add_executable)

function(create_set_target_properties prefix name property value)
    set_target_properties(test-${prefix}-${name} PROPERTIES ${property} ${value})
endfunction(create_set_target_properties)

create_add_executable(pi pi_seq)
create_add_executable(pi pi_openmp -fopenmp)
# create_set_target_properties(pi pi_openmp PROPERTIES COMPILE_FLAGS "-fopenmp")
create_add_executable(pi pi_mpi mpi)

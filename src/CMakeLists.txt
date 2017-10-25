cmake_minimum_required(VERSION 3.9)
project(${CMAKE_PROJECT_NAME}-src)

set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

set(MAIN_SRC
        main.cpp)

add_executable(${CMAKE_PROJECT_NAME} ${MAIN_SRC})
target_link_libraries(${CMAKE_PROJECT_NAME}
        #${CMAKE_BINARY_DIR}/lib${CMAKE_PROJECT_NAME}-common.a
        #${CMAKE_BINARY_DIR}/lib${CMAKE_PROJECT_NAME}-pi.a
        ${CMAKE_PROJECT_NAME}-common
        ${CMAKE_PROJECT_NAME}-pi
        )
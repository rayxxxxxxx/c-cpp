cmake_minimum_required(VERSION 3.2)

set(SRC ${CMAKE_SOURCE_DIR}/src)

add_library(CArray STATIC
    ${SRC}/lib/carray.c
    ${SRC}/lib/carrayUtils.c
)

target_include_directories(CArray PUBLIC ${SRC}/include)
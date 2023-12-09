cmake_minimum_required(VERSION 3.2)

set(src ${CMAKE_SOURCE_DIR}/src)

add_library(CArray SHARED
    ${src}/lib/array.c
)

add_library(CArrayUtil SHARED
    ${src}/lib/arrayUtil.c
)

target_include_directories(CArray PUBLIC ${src}/include)

target_include_directories(CArrayUtil PUBLIC ${src}/include)
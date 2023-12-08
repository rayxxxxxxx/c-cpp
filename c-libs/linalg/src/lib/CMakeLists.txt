cmake_minimum_required(VERSION 3.2)

set(src ${CMAKE_SOURCE_DIR}/src)

add_library(Linalg SHARED
    ${src}/lib/vector.c
    ${src}/lib/matrix.c
    ${src}/lib/linalg.c
)

target_include_directories(Linalg PUBLIC ${src}/include)
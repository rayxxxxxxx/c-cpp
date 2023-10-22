cmake_minimum_required(VERSION 3.2)

set(include ${CMAKE_SOURCE_DIR}/include)
set(src ${CMAKE_SOURCE_DIR}/src)

project(Linalg)

add_library(Linalg SHARED
    ${src}/vector.cpp
    ${src}/matrix.cpp
    ${src}/linalg.cpp
    )
target_include_directories(Linalg PUBLIC ${include})
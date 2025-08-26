cmake_minimum_required(VERSION 3.2)

set(src ${CMAKE_SOURCE_DIR}/src)

add_library(Matrix SHARED ${src}/lib/matrix.c)

target_include_directories(Matrix PUBLIC ${src}/include)
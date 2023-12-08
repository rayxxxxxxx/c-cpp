cmake_minimum_required(VERSION 3.2)

add_library(matrix SHARED ${CMAKE_SOURCE_DIR}/src/lib/matrix.c)

target_include_directories(matrix PUBLIC ${CMAKE_SOURCE_DIR}/src/include)
cmake_minimum_required(VERSION 3.2)

add_library(array SHARED ${CMAKE_SOURCE_DIR}/src/lib/array.c)

target_include_directories(array PUBLIC ${CMAKE_SOURCE_DIR}/src/include)
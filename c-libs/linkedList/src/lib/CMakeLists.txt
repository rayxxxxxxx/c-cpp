cmake_minimum_required(VERSION 3.2)

set(src ${CMAKE_SOURCE_DIR}/src)

add_library(LinkedList SHARED ${src}/lib/linkedList.c)

target_include_directories(LinkedList PUBLIC ${src}/include)
cmake_minimum_required(VERSION 3.2)

add_library(Stack SHARED ${CMAKE_SOURCE_DIR}/src/lib/stack.c)

target_include_directories(Stack PUBLIC ${CMAKE_SOURCE_DIR}/src/include)
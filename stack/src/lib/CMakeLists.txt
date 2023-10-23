cmake_minimum_required(VERSION 3.22)

add_library(Stack SHARED
    ./stack.cpp
)

target_include_directories(Stack PUBLIC
    ../include
)
cmake_minimum_required(VERSION 3.22)

add_library(ComplexNumber SHARED
    ./complex.cpp
)

target_include_directories(ComplexNumber PUBLIC
    ../include
)

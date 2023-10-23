cmake_minimum_required(VERSION 3.2)

add_library(linkedList SHARED
    ${CMAKE_SOURCE_DIR}/src/lib/node.cpp
    ${CMAKE_SOURCE_DIR}/src/lib/linkedList.cpp
)

target_include_directories(linkedList PUBLIC
    ${CMAKE_SOURCE_DIR}/src/include
)
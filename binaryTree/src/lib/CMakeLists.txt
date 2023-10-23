cmake_minimum_required(VERSION 3.2)

add_library(binaryTree SHARED
    ${CMAKE_SOURCE_DIR}/src/lib/binaryTree/node.cpp
    ${CMAKE_SOURCE_DIR}/src/lib/binaryTree/binaryTree.cpp
)

target_include_directories(binaryTree PUBLIC
    ${CMAKE_SOURCE_DIR}/src/include
)

cmake_minimum_required(VERSION 3.2)

set(SRC ${CMAKE_SOURCE_DIR}/src)

add_library(CBTree STATIC
    ${SRC}/lib/Node.c
    ${SRC}/lib/btree.c
)

target_include_directories(CBTree PUBLIC ${SRC}/include)
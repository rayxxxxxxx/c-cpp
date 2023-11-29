cmake_minimum_required(VERSION 3.2)

add_library(hset SHARED ${CMAKE_SOURCE_DIR}/src/lib/hashSet.c)

target_include_directories(hset PUBLIC ${CMAKE_SOURCE_DIR}/src/include)
cmake_minimum_required(VERSION 3.2)

set(src ${CMAKE_SOURCE_DIR}/src)

add_library(HashSet SHARED ${src}/lib/hashSet.c)

target_include_directories(HashSet PUBLIC ${src}/include)
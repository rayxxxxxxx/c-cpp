cmake_minimum_required(VERSION 3.2)

add_library(linked_list SHARED ${CMAKE_SOURCE_DIR}/src/lib/linkedList.c)

target_include_directories(linked_list PUBLIC ${CMAKE_SOURCE_DIR}/src/include)
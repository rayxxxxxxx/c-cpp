cmake_minimum_required(VERSION 3.2)

add_library(Queue SHARED ${CMAKE_SOURCE_DIR}/src/lib/queue.c)

target_include_directories(Queue PUBLIC ${CMAKE_SOURCE_DIR}/src/include)
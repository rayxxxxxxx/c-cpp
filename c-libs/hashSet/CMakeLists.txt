cmake_minimum_required(VERSION 3.2)

project(hset)

add_subdirectory(src/lib)

add_executable(app src/main.c)

target_link_libraries(app PRIVATE hset)
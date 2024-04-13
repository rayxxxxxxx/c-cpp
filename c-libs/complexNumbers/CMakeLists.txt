cmake_minimum_required(VERSION 3.2)

set(src ${CMAKE_SOURCE_DIR}/src)
set(lib ${CMAKE_SOURCE_DIR}/src/lib)
set(inc ${CMAKE_SOURCE_DIR}/src/include)

project(complexnum)

add_subdirectory(${lib})

add_executable(app ${src}/main.c)

target_link_libraries(app PUBLIC Complexnum)

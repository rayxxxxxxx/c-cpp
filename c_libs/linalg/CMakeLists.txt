cmake_minimum_required(VERSION 3.2)

set(src ${CMAKE_SOURCE_DIR}/src)

project(Linalg)

add_subdirectory(${src}/lib)

add_executable(app ${src}/main.c)

target_link_libraries(app PUBLIC Linalg)
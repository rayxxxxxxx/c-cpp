cmake_minimum_required(VERSION 3.2)

set(SRC ${CMAKE_SOURCE_DIR}/src)

project(CBTree)

add_subdirectory(${SRC}/lib)

add_executable(app ${SRC}/main.c)

target_link_libraries(app PRIVATE CBTree)

target_include_directories(app PRIVATE ${SRC}/include)
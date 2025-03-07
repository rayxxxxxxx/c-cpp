cmake_minimum_required(VERSION 3.2)

set(SRC ${CMAKE_SOURCE_DIR}/src)
set(LIB ${CMAKE_SOURCE_DIR}/src/lib)
set(INCLUDE ${CMAKE_SOURCE_DIR}/src/include)

project(mstring)

add_subdirectory(${LIB})

add_executable(app ${SRC}/main.c)
target_include_directories(app PUBLIC ${INCLUDE})
target_link_libraries(app PUBLIC mstring)
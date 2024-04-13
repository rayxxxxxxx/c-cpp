cmake_minimum_required(VERSION 3.2)

set(src ${CMAKE_SOURCE_DIR}/src)
set(lib ${CMAKE_SOURCE_DIR}/src/lib)
set(inc ${CMAKE_SOURCE_DIR}/src/include)

add_library(Complexnum SHARED
    ${lib}/complexnum.c
)

target_link_libraries(Complexnum m)
target_include_directories(Complexnum PUBLIC ${inc})

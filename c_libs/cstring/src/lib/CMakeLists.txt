cmake_minimum_required(VERSION 3.2)

add_library(Cstring STATIC
    ${LIB}/cstring.c
    ${LIB}/cstringUtils.c
)

target_include_directories(Cstring PUBLIC ${INCLUDE})
cmake_minimum_required(VERSION 3.2)

add_library(mstring STATIC
    ${LIB}/mstring.c
    ${LIB}/mstring_utils.c
)

target_include_directories(mstring PUBLIC ${INCLUDE})
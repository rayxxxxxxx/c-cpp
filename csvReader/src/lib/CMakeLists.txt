cmake_minimum_required(VERSION 3.2)

add_library(CSVReader SHARED
    ${CMAKE_SOURCE_DIR}/src/lib/csvReader.cpp
    ${CMAKE_SOURCE_DIR}/src/lib/stringUtils.cpp
)

target_include_directories(CSVReader PUBLIC ${CMAKE_SOURCE_DIR}/src/include)
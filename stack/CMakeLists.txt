cmake_minimum_required(VERSION 3.22)

project(app)

add_subdirectory(src/lib)

add_executable(app
    src/main.cpp
)

target_link_libraries(app PRIVATE
    Stack
)
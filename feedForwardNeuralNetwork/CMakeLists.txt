cmake_minimum_required(VERSION 3.2)

project(app)

set(src ${CMAKE_SOURCE_DIR}/src)

add_subdirectory(${src}/lib/linalg)
add_subdirectory(${src}/lib/fnn)

add_executable(app 
    ${src}/main.cpp
)

target_link_libraries(app PRIVATE
    Linalg
)

target_link_libraries(app PRIVATE
    FNN
)

target_include_directories(app PRIVATE
    ${src}/include
)


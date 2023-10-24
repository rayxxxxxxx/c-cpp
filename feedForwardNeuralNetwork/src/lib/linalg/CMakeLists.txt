set(src ${CMAKE_SOURCE_DIR}/src)

add_library(Linalg SHARED
    ${src}/lib/linalg/vector.cpp
    ${src}/lib/linalg/matrix.cpp
    ${src}/lib/linalg/linalg.cpp
)

target_include_directories(Linalg PUBLIC
    ${src}/include
)

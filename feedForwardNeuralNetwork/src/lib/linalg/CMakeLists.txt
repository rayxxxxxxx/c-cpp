set(src ${CMAKE_SOURCE_DIR}/src)

add_library(Linalg SHARED
    ${src}/lib/linalg/vct.cpp
    ${src}/lib/linalg/mtrx.cpp
    ${src}/lib/linalg/linalg.cpp
)

target_include_directories(Linalg PUBLIC
    ${src}/include
)

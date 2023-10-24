cmake_minimum_required(VERSION 3.2)

project(Linalg)

add_library(Linalg SHARED
	./lib/vector.cpp
	./lib/matrix.cpp
	./lib/linalg.cpp
)
target_include_directories(Linalg PUBLIC ./include)

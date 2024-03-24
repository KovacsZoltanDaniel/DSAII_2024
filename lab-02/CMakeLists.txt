cmake_minimum_required(VERSION 3.25.2)
project(lab_02)

set(CMAKE_CXX_STANDARD 23)

add_executable(lab_02 Sources/main.cpp Sources/functionsRec.cpp Headers/functionsRec.h ../lab-04/sources/backtracking.cpp ../lab-04/headers/backtracking.h)

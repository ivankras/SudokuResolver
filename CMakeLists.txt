cmake_minimum_required(VERSION 3.12)
project(sudoku)

set(CMAKE_CXX_STANDARD 14)

add_executable(sudoku main.cpp box.h box.cpp grid.h grid.cpp)
cmake_minimum_required(VERSION 3.17)
project(CPP_TEST)

set(CMAKE_CXX_STANDARD 14)

add_executable(CPP_TEST main.cpp Game.cpp Game.h Position.h Sudoku.cpp Sudoku.h)
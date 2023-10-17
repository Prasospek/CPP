cmake_minimum_required(VERSION 3.24)
project(extra_homework)

set(CMAKE_CXX_STANDARD 14)

add_executable(extra_homework
        main.cpp Tile.h Tile.cpp Player.h Player.cpp Board.h Board.cpp)

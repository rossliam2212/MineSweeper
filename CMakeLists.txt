cmake_minimum_required(VERSION 3.21)
project(MineSweeper)

set(CMAKE_CXX_STANDARD 14)

add_executable(MineSweeper main.cpp MineSweeper.cpp MineSweeper.h WinTracker.cpp WinTracker.h)

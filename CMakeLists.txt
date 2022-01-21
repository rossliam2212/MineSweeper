cmake_minimum_required(VERSION 3.20)
project(MineSweeper)

set(CMAKE_CXX_STANDARD 14)

add_executable(MineSweeper src/main.cpp src/MineSweeper.cpp src/MineSweeper.h src/WinTracker.cpp src/WinTracker.h src/GameBoard.cpp src/GameBoard.h)

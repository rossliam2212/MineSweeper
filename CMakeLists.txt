cmake_minimum_required(VERSION 3.21)
project(MineSweeper)

set(CMAKE_CXX_STANDARD 14)

add_executable(MineSweeper src/main.cpp src/MineSweeper.cpp src/MineSweeper.h WinTracker.cpp WinTracker.h src/GameBoard.cpp src/GameBoard.h)

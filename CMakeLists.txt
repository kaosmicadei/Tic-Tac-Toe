cmake_minimum_required(VERSION 3.10)

project(TicTacToe)

enable_testing()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Binary directory.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Source code files.
add_subdirectory(src)
add_subdirectory(tests)

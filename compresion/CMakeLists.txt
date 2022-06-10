cmake_minimum_required(VERSION 3.21)
project(proyecto3)

set(CMAKE_CXX_STANDARD 14)

add_executable(proyecto3 main.cpp huffman.cpp huffman.hpp LZ77.cpp LZ77.hpp BinaryTools.cpp BinaryTools.hpp LZ78.cpp LZ78.hpp)

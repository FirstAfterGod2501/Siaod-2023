cmake_minimum_required(VERSION 3.26)
project(task8)

set(CMAKE_CXX_STANDARD 14)

add_executable(task8
        main.cpp
        RLE.h
        LZ77.h
        LZ.h
        shannonFano.h)

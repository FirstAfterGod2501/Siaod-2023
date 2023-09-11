cmake_minimum_required(VERSION 3.26)
project(task1)

set(CMAKE_CXX_STANDARD 23)


add_compile_options("-O3")

add_executable(task1
        main.cpp
        Headers/FirstTask.h
        Headers/MergeSort.h)

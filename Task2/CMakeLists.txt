cmake_minimum_required(VERSION 3.26)

project(Task2)

set(CMAKE_CXX_STANDARD 23)

add_executable(Task2
        main.cpp
        FileManager/Filemanager.h
        Students.h
        FileManager/Filemanager.cpp
        UI/UI.h
        UI/UI.cpp
        BinaryFileManager/BinaryFileManager.h
        BinaryFileManager/BinaryFileManager.cpp)

cmake_minimum_required(VERSION 3.26)
project(task5)

set(CMAKE_CXX_STANDARD 14)

add_executable(task5
        main.cpp
        BinaryTree/BinaryTree.h
        BinaryTree/BinaryTree.cpp
        BinaryTree/Record.h
        BinaryTreeService/BinaryTreeService.h
        BinaryTreeService/BinaryTreeService.cpp
        BinaryFileManager/BinaryFileManager.cpp
        BinaryFileManager/BinaryFileManager.h
        SplayTree/SplayTree.h
        SplayTree/SplayTree.cpp
        SplayTree/Node.h
        SplayTreeService/SplayTreeService.h
        SplayTreeService/SplayTreeService.cpp
        SplayTreeService/TreePrinter.h
        Tests/BinaryTreeTests/BinaryTreeTests.h
        Tests/BinaryTreeTests/BinaryTreeTests.cpp
        Tests/SplayTreeTests/SplayTreeTests.h
        Tests/SplayTreeTests/SplayTreeTests.cpp
        Tests/PerfomanceTest/SplayTreePerfomanceTest.h
        Tests/PerfomanceTest/SplayTreePerfomanceTest.cpp)

cmake_minimum_required(VERSION 3.26)
project(Task3)

set(CMAKE_CXX_STANDARD 14)

include_directories(FileService)
include_directories(HashTableFileManagerService)
include_directories(HashTableService)
include_directories(Model)
include_directories(Tests)

add_executable(Task3
        FileService/FileService.cpp
        FileService/FileService.h
        HashTableFileManagerService/HashTableFileManager.cpp
        HashTableFileManagerService/HashTableFileManager.h
        HashTableService/HashTable.cpp
        HashTableService/HashTable.h
        Model/Student.h
        Tests/FileSystemTests.h
        Tests/HashTableFileManagerTests.h
        Tests/HashTableTests.h
        main.cpp)

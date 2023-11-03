//
// Created by first on 13.10.23.
//

#ifndef TASK3_HASKTABLEFILEMANAGER_H
#define TASK3_HASKTABLEFILEMANAGER_H


#include <string>
#include "../FileService/FileService.h"
#include "../HashTableService/HashTable.h"

class HashTableFileManager : public HashTable, public BinaryFileManager {
private:

    std::string _filename;

public:
    explicit HashTableFileManager(const std::string &filename);

    void InsertElementFromFile(int id);

    void Delete(int id);

    Student GetStudentByIndex(int id);

};


#endif

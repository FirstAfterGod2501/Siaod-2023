//
// Created by first on 15.11.23.
//

#ifndef TASK5_SPLAYTREESERVICE_H
#define TASK5_SPLAYTREESERVICE_H


#include "../SplayTree/SplayTree.h"
#include "../BinaryFileManager/Student.h"

class SplayTreeService {
private:
    SplayTree _splayTree;

    std::string _filename;

public:
    explicit SplayTreeService(SplayTree tree, std::string filename);

    Student GetStudentByIndex(int id);

    Student InsertStudentByIndex(int id);

    void RemoveStudentByIndex(int id);

    void PrintTree();
};


#endif //TASK5_SPLAYTREESERVICE_H

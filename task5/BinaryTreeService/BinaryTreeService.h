//
// Created by first on 10.11.23.
//

#ifndef TASK5_BINARYTREESERVICE_H
#define TASK5_BINARYTREESERVICE_H


#include <string>
#include "../BinaryFileManager/Student.h"
#include "../BinaryFileManager/BinaryFileManager.h"
#include "../BinaryTree/BinaryTree.h"

class BinaryTreeService : public BinarySearchTree, public BinaryFileManager {
private:

    std::string _filename;

public:
    explicit BinaryTreeService(const std::string &filename);

    void InsertElementFromFile(int id);

    void Delete(int id);

    Student GetStudentByIndex(int id);
};


#endif //TASK5_BINARYTREESERVICE_H

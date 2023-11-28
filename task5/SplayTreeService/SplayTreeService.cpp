//
// Created by first on 15.11.23.
//

#include "SplayTreeService.h"

#include <utility>
#include <vector>
#include "../BinaryFileManager/BinaryFileManager.h"
#include "../SplayTreeService/TreePrinter.h"

SplayTreeService::SplayTreeService(SplayTree tree, std::string filename) {
    _splayTree = tree;
    _filename = std::move(filename);
}

Student SplayTreeService::GetStudentByIndex(int id) {
    auto student =  _splayTree.search(id);
    auto binaryFileManager = new BinaryFileManager();
    return binaryFileManager->accessByIndex(_filename, student->data);
}

Student SplayTreeService::InsertStudentByIndex(int id) {
    auto binaryFileManager = new BinaryFileManager();
    auto key = binaryFileManager->accessByIndex(_filename, id);
    _splayTree.insert(key.studentID);
    return key;
}

void SplayTreeService::RemoveStudentByIndex(int id) {
    auto student = _splayTree.search(id);
    _splayTree.remove(id);
    auto binaryFileManager = new BinaryFileManager();
    binaryFileManager->deleteRecord(_filename ,student->data);
}

void SplayTreeService::PrintTree() {
    auto printer = new TreePrinter();
    printer->printExpressionTree(_splayTree.GetRoot());
}

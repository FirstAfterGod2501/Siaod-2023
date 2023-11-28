//
// Created by first on 10.11.23.
//

#include "BinaryTreeService.h"

BinaryTreeService::BinaryTreeService(const std::string &filename) {
    _filename = filename;
}

void BinaryTreeService::InsertElementFromFile(int id) {
    auto student = accessByIndex(_filename, id);
    Record rc;
    rc.key = student.studentID;
    rc.data = std::to_string(student.studentID);
    insert(student.studentID, rc);
}


Student BinaryTreeService::GetStudentByIndex(int id) {
    auto student = search(id);
    return accessByIndex(_filename, id);
}

void BinaryTreeService::Delete(int id) {
    //undefined
}

//
// Created by first on 13.10.23.
//

#include "HashTableFileManager.h"

HashTableFileManager::HashTableFileManager(const std::string &filename) {
    _filename = filename;
}

void HashTableFileManager::InsertElementFromFile(int id) {
    auto student = accessByIndex(_filename, id);
    insert(student.studentId,student.studentId);
}

void HashTableFileManager::Delete(int id) {
    remove(id);
    deleteRecord(_filename, id);
}

Student HashTableFileManager::GetStudentByIndex(int id) {
    auto student = find(id);
    return accessByIndex(_filename, student);
}

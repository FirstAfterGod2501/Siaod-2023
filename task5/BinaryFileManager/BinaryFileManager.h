//
// Created by first on 21.09.23.
//

#ifndef TASK2_BINARYFILEMANAGER_H
#define TASK2_BINARYFILEMANAGER_H

#include <iostream>
#include <fstream>
#include <cstring>
#include "Student.h"

class BinaryFileManager {
public:
    void textToBinary(const std::string &inputFile, const std::string &outputFile);

    void binaryToText(const std::string &inputFile, const std::string &outputFile);

    void printBinaryFile(const std::string &inputFile);

    Student accessByIndex(const std::string &inputFile, int index);

    void deleteRecord(const std::basic_string<char>& inputFile, int studentIDToDelete);

    void formGroupList(const std::string &inputFile, int groupID, const std::string &outputFile);

    void transferStudents(const std::string &inputFile, const std::string &studentsFile, int newGroupID);

};


#endif //TASK2_BINARYFILEMANAGER_H

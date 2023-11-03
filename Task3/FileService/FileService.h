//
// Created by first on 11.10.23.
//

#ifndef TASK3_FILESERVICE_H
#define TASK3_FILESERVICE_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include "../Model/Student.h"

class BinaryFileManager {
public:
    void textToBinary(const std::string &inputFile, const std::string &outputFile);

    void binaryToText(const std::string &inputFile, const std::string &outputFile);

    void printBinaryFile(const std::string &inputFile);

    Student accessByIndex(const std::string &inputFile, int index);

    void deleteRecord(const std::basic_string<char>& inputFile, int studentIDToDelete);

    std::vector<Student> getStudents(const std::string &inputFile);

    void formGroupList(const std::string &inputFile, int groupID, const std::string &outputFile);

    void transferStudents(const std::string &inputFile, const std::string &studentsFile, int newGroupID);

};


#endif 

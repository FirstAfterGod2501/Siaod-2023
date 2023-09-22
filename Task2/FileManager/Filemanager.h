//
// Created by first on 15.09.23.
//

#ifndef TASK2_FILEMANAGER_H
#define TASK2_FILEMANAGER_H

#include <vector>
#include <algorithm>
#include <sstream>
#include "fstream"
#include "iostream"
#include "../Students.h"

class FileManager {
public:
    void writeToFile(const std::string& filename, const std::string& data);

    std::string readFromFile(const std::string& filename);

    void createTextFile(const std::string& fileName);

    void appendTextFile(const std::string& fileName, const std::vector<int>& numbers);

    int readNumberFromFile(const std::string& fileName, int index);

    int countNumbersInFile(const std::string& fileName);

    void createNewFileWithDividedValues(const std::string& inputFileName, const std::string& outputFileName);

private:
    template<typename EuclideanRingElement>
    EuclideanRingElement gcd(EuclideanRingElement m, EuclideanRingElement n);
};
#endif
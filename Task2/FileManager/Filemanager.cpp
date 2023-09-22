//
// Created by first on 21.09.23.
//

#include "Filemanager.h"
#include <vector>
#include <sstream>
#include <random>
#include "fstream"
#include "iostream"

void FileManager::writeToFile(const std::string &filename, const std::string &data) {
    std::ofstream file(filename);
    if (!file) {
        std::cout << "Failed to open file." << std::endl;
        return;
    }
    if(file << data){}
    else{
        std::cout<<"Failed to write";
        file.close();
        return;
    }
    file.close();
}

std::string FileManager::readFromFile(const std::string &filename) {
    std::string data;

    std::ifstream file(filename);

    if (!file) {
        std::cout << "Failed to open file." << std::endl;
        return data;
    }
    while(!file.eof()) {
        std::string tmp;
        std::getline(file, tmp);
        data += tmp + "\n";
    }
    file.close();

    return data;
}

void FileManager::createTextFile(const std::string &fileName) {
    std::ofstream file(fileName);
    if (!file.is_open()) {
        std::cout << "Failed to open file." << std::endl;
        return;
    }

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1,INT32_MAX); // distribution in range [1, 6]

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if(file << dist6(rng) << " "){}
            else{
                std::cout<<"Failed to write";
                file.close();
                return;
            }
        }
        if(file << std::endl){}
        else{
            std::cout<<"Failed to write";
            file.close();
            return;
        }
    }

    file.close();
}

void FileManager::appendTextFile(const std::string &fileName, const std::vector<int> &numbers) {
    std::ofstream file(fileName, std::ios_base::app);
    if (!file.is_open()) {
        std::cout << "Failed to open file." << std::endl;
        return;
    }

    for (const auto& num : numbers) {
        if(file << num << " "){}
        else{
            std::cout<<"Failed to write";
            file.close();
            return;
        }
    }
    if(file << std::endl){}
    else{
        std::cout<<"Failed to write";
        file.close();
        return;
    }

    file.close();
}

int FileManager::readNumberFromFile(const std::string &fileName, int index) {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cout << "Failed to open file." << std::endl;
        return -1;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);

        int currentNumberPosition = 0;

        int number;

        while (iss >> number) {
            currentNumberPosition++;
            if (currentNumberPosition == index) {
                file.close();
                return number;
            }
            break;
        }
    }

    file.close();
    return -1;
}

int FileManager::countNumbersInFile(const std::string &fileName) {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cout << "Failed to open file." << std::endl;
        return -1;
    }

    int count = 0;
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        int number;
        while (iss >> number) {
            count++;
        }
    }

    file.close();
    return count;
}

void FileManager::createNewFileWithDividedValues(const std::string &inputFileName, const std::string &outputFileName) {
    std::ifstream inputFile(inputFileName);
    if (!inputFile.is_open()) {
        std::cout << "Failed to open file." << std::endl;
        return;
    }

    std::vector<std::vector<int>> numbers;
    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        int number;
        std::vector<int> nums;
        while (iss >> number) {
            nums.push_back(number);
        }
        numbers.push_back(nums);
    }
    inputFile.close();

    int gcd = 0;
    for (const auto& nums : numbers) {
        for (const auto& num : nums) {
            gcd = FileManager::gcd(gcd, num);
        }
    }

    std::ofstream outputFile(outputFileName);
    if (!outputFile.is_open()) {
        std::cout << "Failed to open file." << std::endl;
        return;
    }

    for (const auto& nums : numbers) {
        for (const auto& num : nums) {
            if(outputFile << num / gcd << " "){}
            else{
                std::cout<<"Failed to write";
                outputFile.close();
                return;
            }
        }
        if(outputFile << std::endl){}
        else{
            std::cout<<"Failed to write";
            outputFile.close();
            return;
        }
    }
    outputFile.close();
}

//C++17 feature
template<typename EuclideanRingElement>
EuclideanRingElement FileManager::gcd(EuclideanRingElement m, EuclideanRingElement n) {
    while (n != 0)
    {
        EuclideanRingElement t = m % n;
        m = n;
        n = t;
    }
    return m;
}

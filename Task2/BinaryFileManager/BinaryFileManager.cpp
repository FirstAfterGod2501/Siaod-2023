//
// Created by first on 21.09.23.
//

#include "BinaryFileManager.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <unistd.h>

void BinaryFileManager::textToBinary(const std::string &inputFile, const std::string &outputFile) {
    std::ifstream input(inputFile);
    std::ofstream output(outputFile, std::ios::binary);

    if (!input.is_open()) {
        std::cerr << "Unable to open input file." << std::endl;
        return;
    }

    if (!output.is_open()) {
        std::cerr << "Unable to open output file." << std::endl;
        return;
    }

    int studentID, groupID;
    char name[50];

    while (input >> studentID >> groupID) {
        input.ignore();
        input.getline(name, sizeof(name));

        Student student{};
        student.studentID = studentID;
        student.groupID = groupID;
        std::strcpy(student.name, name);

        output.write(reinterpret_cast<const char*>(&student), sizeof(Student));
    }

    input.close();
    output.close();
}

void BinaryFileManager::binaryToText(const std::string &inputFile, const std::string &outputFile) {
    std::ifstream input(inputFile, std::ios::binary);
    std::ofstream output(outputFile);

    if (!input.is_open()) {
        std::cerr << "Unable to open input file." << std::endl;
        return;
    }

    if (!output.is_open()) {
        std::cerr << "Unable to open output file." << std::endl;
        return;
    }

    Student student{};
    while (input.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
        output << student.studentID << " " << student.groupID << " " << student.name << std::endl;
    }

    input.close();
    output.close();
}

void BinaryFileManager::printBinaryFile(const std::string &inputFile) {
    std::ifstream input(inputFile, std::ios::binary);

    if (!input.is_open()) {
        std::cerr << "Unable to open input file." << std::endl;
        return;
    }

    Student student{};
    while (input.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
        std::cout << "Student ID: " << student.studentID << std::endl;
        std::cout << "Group ID: " << student.groupID << std::endl;
        std::cout << "Name: " << student.name << std::endl;
        std::cout << std::endl;
    }

    input.close();
}

void BinaryFileManager::accessByIndex(const std::string &inputFile, int index) {
    std::ifstream input(inputFile, std::ios::binary);

    if (!input.is_open()) {
        std::cerr << "Unable to open input file." << std::endl;
        return;
    }

    input.seekg(index * sizeof(Student), std::ios::beg);

    Student student{};
    if (input.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
        std::cout << "Student ID: " << student.studentID << std::endl;
        std::cout << "Group ID: " << student.groupID << std::endl;
        std::cout << "Name: " << student.name << std::endl;
    }

    input.close();
}

void BinaryFileManager::deleteRecord(const std::string& inputFile, int studentIDToDelete) {
    std::fstream file(inputFile, std::ios::in | std::ios::out | std::ios::binary);

    if (!file.is_open()) {
        std::cerr << "Unable to open file." << std::endl;
        return;
    }

    Student student{};
    while (file.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
        if (student.studentID == studentIDToDelete) {
            file.seekg(-static_cast<int>(sizeof(Student)), std::ios::cur);
            Student lastStudent{};
            file.seekg(-static_cast<int>(sizeof(Student)), std::ios::end);
            file.read(reinterpret_cast<char*>(&lastStudent), sizeof(Student));
            file.seekp(-static_cast<int>(sizeof(Student)), std::ios::cur);
            file.write(reinterpret_cast<const char*>(&lastStudent), sizeof(Student));
        }
    }

    file.close();
}

void BinaryFileManager::formGroupList(const std::string &inputFile, int groupID, const std::string &outputFile) {
    std::ifstream input(inputFile, std::ios::binary);
    std::ofstream output(outputFile, std::ios::binary);

    if (!input.is_open()) {
        std::cerr << "Unable to open input file." << std::endl;
        return;
    }

    if (!output.is_open()) {
        std::cerr << "Unable to open output file." << std::endl;
        return;
    }

    Student student{};
    while (input.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
        if (student.groupID == groupID) {
            output.write(reinterpret_cast<const char*>(&student), sizeof(Student));
        }
    }

    input.close();
    output.close();
}

void BinaryFileManager::transferStudents(const std::string &inputFile, const std::string &studentsFile, int newGroupID) {
    std::ifstream input(inputFile, std::ios::binary);
    std::ofstream output("temp.bin", std::ios::binary);

    if (!input.is_open()) {
        std::cerr << "Unable to open input file." << std::endl;
        return;
    }

    if (!output.is_open()) {
        std::cerr << "Unable to open output file." << std::endl;
        return;
    }

    Student student{};
    while (input.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
        std::ifstream students(studentsFile);
        int studentID;

        bool shouldTransfer = false;
        while (students >> studentID) {
            if (student.studentID == studentID) {
                shouldTransfer = true;
                break;
            }
        }
        students.close();

        if (shouldTransfer) {
            student.groupID = newGroupID;
        }

        output.write(reinterpret_cast<const char*>(&student), sizeof(Student));
    }

    input.close();
    output.close();

    std::remove(inputFile.c_str());
    std::rename("temp.bin", inputFile.c_str());
}

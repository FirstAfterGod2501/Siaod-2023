//
// Created by first on 11.10.23.
//

#ifndef TASK3_FILESYSTEMTESTS_H
#define TASK3_FILESYSTEMTESTS_H

#include "../FileService/FileService.h"

class FileSystemTests{
public:
    FileSystemTests(){
        auto students = new BinaryFileManager();

        for (auto student : students->getStudents("students.bin")) {
            std::cout<<student.Fullname<< " " <<student.studentId<< "\n";
        }
    }

};

#endif
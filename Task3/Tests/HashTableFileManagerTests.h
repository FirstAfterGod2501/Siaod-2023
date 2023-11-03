//
// Created by first on 13.10.23.
//

#ifndef TASK3_HASHTABLEFILEMANAGERTESTS_H
#define TASK3_HASHTABLEFILEMANAGERTESTS_H

#include <utility>

#include "../HashTableFileManagerService/HashTableFileManager.h"

class HashTableManagerTests{
private:

    HashTableFileManager _hashTableFileManagerService;

    void RunInsertTest(){
        _hashTableFileManagerService.InsertElementFromFile(4);
        auto searched = _hashTableFileManagerService.GetStudentByIndex(4);
        if(searched.studentId == 4){
            std::cout<< "Insert test passed\n";
        }
    }

    void RunDeleteTest(){
        _hashTableFileManagerService.Delete(4);
        auto searched = _hashTableFileManagerService.find(4);
        if(searched != 4){
            std::cout<<"Delete test passed" << "\n";
        }
    }

    void RunGetStudentByIndexTest(){
        _hashTableFileManagerService.InsertElementFromFile(2);
        auto searched = _hashTableFileManagerService.GetStudentByIndex(2);
        if(searched.studentId != 2){
            std::cout<<"GetStudentByIndex test passed" << "\n";
        }
    }

public:
    explicit HashTableManagerTests(HashTableFileManager hashTableFileManagerService)
            : _hashTableFileManagerService(std::move(hashTableFileManagerService)) {
        RunInsertTest();
        RunDeleteTest();
        RunGetStudentByIndexTest();
    }
};
#endif
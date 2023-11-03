//
// Created by first on 11.10.23.
//

#ifndef TASK3_HASHTABLETESTS_H
#define TASK3_HASHTABLETESTS_H

#include "../HashTableService/HashTable.h"
#include "../FileService/FileService.h"

class HashTableTests {
public:
    HashTableTests(){
        HashTable hashTable;

        std::cout<<"Insert key without collision\n";

        hashTable.insert(7, 142);

        if(hashTable.find(7) == 142){
            std::cout<<"Insert key without collision passed\n";
        }
        else{
            std::cout<<"bad test\n";
        }

        std::cout<<"Insert key with collision\n";

        hashTable.insert(19, 145);

        if(hashTable.find(19) == 145){
            std::cout<<"Insert key without collision passed\n";
        }
        else{
            std::cout<<"bad test\n";
        }

        std::cout<<"Insert key with rehash\n";

        hashTable.insert(36, 145);

        for(int i = 0; i< 150;i++){
            hashTable.insert(i,34);
        }

        if(hashTable.find(149) == 34){
            std::cout<<"Insert key without collision passed\n";
        }
        else{
            std::cout<<"bad test\n";
        }

        std::cout<<"remove key\n";
        hashTable.remove(25);

        if(hashTable.find(25) != 145){
            std::cout<<"remove key test passed\n";
        }
        else{
            std::cout<<"bad test\n";
        }
    }
};


#endif

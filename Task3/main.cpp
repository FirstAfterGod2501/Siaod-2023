//
// Created by first on 13.10.23.
//

#include "FileService.h"
#include "HashTableFileManager.h"
#include "HashTableTests.h"
#include "HashTableFileManagerTests.h"
#include "FileSystemTests.h"

int main(){
    new FileSystemTests();
    std::cout<<"FileSystemTests passed\n\n\n";
    new HashTableManagerTests(*new HashTableFileManager("students.bin"));
    std::cout<<"HashTableManagerTests passed\n\n\n";
    new HashTableTests();
    std::cout<<"HashTableTests passed\n\n\n";
}
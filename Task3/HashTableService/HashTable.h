//
// Created by first on 11.10.23.
//

#ifndef TASK3_HASHTABLE_H
#define TASK3_HASHTABLE_H

#include <vector>
#include "HashTableElement.h"

class HashTable {
private:
    std::vector<HashStruct> table = *new std::vector<HashStruct>;
    std::vector<bool> isOccupied = *new std::vector<bool>;

    std::hash<int> hash;

    std::hash<int> secondHash;

    std::size_t doubleHash(int key);

public:
    std::size_t table_size = 100;

    HashTable() {
        table.resize(table_size);
        isOccupied.resize(table_size);
        for (int i = 0; i < table_size; i++) {
            table[i] = *new HashStruct();
            isOccupied[i] = false;
        }
    }

    void insert(int key, int id);

    bool remove(int key);

    int find(int key);

    void rehash();
};

#endif

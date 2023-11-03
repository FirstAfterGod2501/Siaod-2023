//
// Created by first on 11.10.23.
//


#include "HashTable.h"

void HashTable::insert(int key, int id) {
    std::size_t index = hash(key) % (table_size);

    std::vector<std::size_t> hashes;
    hashes.push_back(index);

    while (isOccupied[index]) {
        index = doubleHash(key);
        for (auto avbhash : hashes) {
            if(avbhash == index){
                rehash();
                hashes.clear();
                break;
            }
        }
        hashes.push_back(index);
    }

    table[index].hash = key;
    table[index].id = id;
    isOccupied[index] = true;
}

bool HashTable::remove(int key) {
    std::size_t index = hash(key) % (table_size);
    int i = 1;

    while (isOccupied[index]) {
        if (table[index].hash == key) {
            isOccupied[index] = false;
            return true;
        }
        index = doubleHash(key);
        i++;
    }

    return false;
}

int HashTable::find(int key) {
    std::size_t index = hash(key) % (table_size);

    while (isOccupied[index]) {
        if (table[index].hash == key) {
            return table[index].id;
        }
        index = doubleHash(key);
    }

    return -1;
}

void HashTable::rehash() {
    table_size*=2;
    table.resize(table_size);
    isOccupied.resize(table_size);
}

std::size_t HashTable::doubleHash(int key) {
    return (hash(key) + secondHash(key+1)) % (table_size) ;
}
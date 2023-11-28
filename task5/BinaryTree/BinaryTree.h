//
// Created by first on 10.11.23.
//

#ifndef TASK5_BINARYTREE_H
#define TASK5_BINARYTREE_H


#include <iostream>
#include "Record.h"

class BinarySearchTree {
private:
    struct Node {
        int key{};
        Record record;
        Node* left{};
        Node* right{};
    };

    Node* root;

    Node* insert(Node* node, int key, const Record& record);

    Node* search(Node* node, int key);

    static Node* findMin(Node* node);

    Node* remove(Node* node, int key);

    void display(Node* node);

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int key, const Record& record);

    Record* search(int key);

    void remove(int key);

    void display();
};


#endif //TASK5_BINARYTREE_H

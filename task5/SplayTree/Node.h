//
// Created by first on 10.11.23.
//

#ifndef TASK5_NODE_H
#define TASK5_NODE_H

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node* parent;

    explicit Node(int key) {
        this->data = key;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }

    explicit Node() {
        data = 0;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }
};

#endif //TASK5_NODE_H

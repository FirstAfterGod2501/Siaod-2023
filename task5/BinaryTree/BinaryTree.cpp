//
// Created by first on 10.11.23.
//

#include "BinaryTree.h"

#include <iostream>

BinarySearchTree::Node *BinarySearchTree::insert(BinarySearchTree::Node *node, int key, const Record &record) {
    if (node == nullptr) {
        Node* newNode = new Node;
        newNode->key = key;
        newNode->record = record;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }

    if (key < node->key) {
        node->left = insert(node->left, key, record);
    } else if (key > node->key) {
        node->right = insert(node->right, key, record);
    }

    return node;
}

BinarySearchTree::Node *BinarySearchTree::search(BinarySearchTree::Node *node, int key) {
    if (node == nullptr || node->key == key) {
        return node;
    }

    if (key < node->key) {
        return search(node->left, key);
    } else {
        return search(node->right, key);
    }
}

BinarySearchTree::Node *BinarySearchTree::findMin(BinarySearchTree::Node *node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

BinarySearchTree::Node *BinarySearchTree::remove(BinarySearchTree::Node *node, int key) {
    if (node == nullptr) {
        return node;
    }

    if (key < node->key) {
        node->left = remove(node->left, key);
    } else if (key > node->key) {
        node->right = remove(node->right, key);
    } else {
        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }

        Node* temp = findMin(node->right);
        node->key = temp->key;
        node->record = temp->record;
        node->right = remove(node->right, temp->key);
    }

    return node;
}

void BinarySearchTree::display(BinarySearchTree::Node *node) {
    if (node != nullptr) {
        display(node->left);
        std::cout << "Key: " << node->key << ", Data: " << node->record.data << std::endl;
        display(node->right);
    }
}

void BinarySearchTree::insert(int key, const Record &record) {
    root = insert(root, key, record);
}

Record *BinarySearchTree::search(int key) {
    Node* result = search(root, key);
    if (result != nullptr) {
        return &(result->record);
    } else {
        return nullptr;
    }
}

void BinarySearchTree::remove(int key) {
    root = remove(root, key);
}

void BinarySearchTree::display() {
    display(root);
}

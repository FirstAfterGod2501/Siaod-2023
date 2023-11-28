//
// Created by first on 16.11.23.
//

#include "BinaryTreeTests.h"
#include "../../BinaryTree/BinaryTree.h"

BinaryTreeTests::BinaryTreeTests() {
    auto binaryTree = new BinarySearchTree();

    Record record;
    record.key = 1;
    record.data = "some data";

    binaryTree->insert(1, record);

    if(binaryTree->search(1)){
        std::cout<<"insert and search tests passed\n";
    }

    binaryTree->remove(1);

    if(!binaryTree->search(1)){
        std::cout<<"remove tests passed\n";
    }
}

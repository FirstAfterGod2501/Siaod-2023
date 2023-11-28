#include <iostream>
#include "Node.h"

typedef Node *NodePtr;

class SplayTree {
private:
    NodePtr root;

    NodePtr searchTreeHelper(NodePtr node, int key);

    // rotate left at node x
    void leftRotate(NodePtr x);

    // rotate right at node x
    void rightRotate(NodePtr x);

    // splaying
    void splay(NodePtr x);

    void deleteNodeHelper(NodePtr node, int key);

    void printHelper(NodePtr nodePtr, std::string indent, bool last);

    void split(NodePtr &x, NodePtr &s, NodePtr &t);

    NodePtr join(NodePtr s, NodePtr t);

    NodePtr maximum(NodePtr node);


public:
    SplayTree();

    NodePtr search(int k);

    void insert(int key);


    void remove(int data) {
        deleteNodeHelper(this->root, data);
    }

    void prettyPrint();

    Node * GetRoot();

};
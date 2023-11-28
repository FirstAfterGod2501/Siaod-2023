#include <iostream>
#include "Node.h"
#include "SplayTree.h"

typedef Node *NodePtr;

Node * SplayTree::GetRoot() {
    return this->root;
}

void SplayTree::insert(int key) {
    auto node = new Node;
    node->data = key;
    NodePtr y = nullptr;
    NodePtr x = this->root;

    while (x != nullptr) {
        y = x;
        if (node->data < x->data) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    // y is parent of x
    node->parent = y;
    if (y == nullptr) {
        root = node;
    } else if (node->data < y->data) {
        y->left = node;
    } else {
        y->right = node;
    }

    // splay the node
    splay(node);
}


NodePtr SplayTree::search(int k) {
    NodePtr x = searchTreeHelper(this->root, k);
    if (x) {
        splay(x);
    }
    return x;
}

SplayTree::SplayTree() {
    root = nullptr;
}

void SplayTree::splay(NodePtr x) {
    while (x->parent) {
        if (!x->parent->parent) {
            if (x == x->parent->left) {
                // zig rotation
                rightRotate(x->parent);
            } else {
                // zag rotation
                leftRotate(x->parent);
            }
        } else if (x == x->parent->left && x->parent == x->parent->parent->left) {
            // zig-zig rotation
            rightRotate(x->parent->parent);
            rightRotate(x->parent);
        } else if (x == x->parent->right && x->parent == x->parent->parent->right) {
            // zag-zag rotation
            leftRotate(x->parent->parent);
            leftRotate(x->parent);
        } else if (x == x->parent->right && x->parent == x->parent->parent->left) {
            // zig-zag rotation
            leftRotate(x->parent);
            rightRotate(x->parent);
        } else {
            // zag-zig rotation
            rightRotate(x->parent);
            leftRotate(x->parent);
        }
    }
}

void SplayTree::rightRotate(NodePtr x) {
    NodePtr y = x->left;
    x->left = y->right;
    if (y->right != nullptr) {
        y->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) {
        this->root = y;
    } else if (x == x->parent->right) {
        x->parent->right = y;
    } else {
        x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
}

void SplayTree::leftRotate(NodePtr x) {
    NodePtr y = x->right;
    x->right = y->left;
    if (y->left != nullptr) {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) {
        this->root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

NodePtr SplayTree::searchTreeHelper(NodePtr node, int key) {
    if (node == nullptr || key == node->data) {
        return node;
    }

    if (key < node->data) {
        return searchTreeHelper(node->left, key);
    }
    return searchTreeHelper(node->right, key);
}

void SplayTree::deleteNodeHelper(NodePtr node, int key) {
    NodePtr x = nullptr;
    NodePtr t, s;
    while (node != nullptr){
        if (node->data == key) {
            x = node;
        }

        if (node->data <= key) {
            node = node->right;
        } else {
            node = node->left;
        }
    }

    if (x == nullptr) {
        std::cout<<"Couldn't find key in the tree"<<std::endl;
        return;
    }
    split(x, s, t); // split the tree
    if (s->left){ // remove x
        s->left->parent = nullptr;
    }
    root = join(s->left, t);
    delete(s);
    s = nullptr;
}

void SplayTree::split(NodePtr &x, NodePtr &s, NodePtr &t) {
    splay(x);
    if (x->right) {
        t = x->right;
        t->parent = nullptr;
    } else {
        t = nullptr;
    }
    s = x;
    s->right = nullptr;
    x = nullptr;
}

NodePtr SplayTree::join(NodePtr s, NodePtr t) {
    if (!s) {
        return t;
    }

    if (!t) {
        return s;
    }
    NodePtr x = maximum(s);
    splay(x);
    x->right = t;
    t->parent = x;
    return x;
}

NodePtr SplayTree::maximum(NodePtr node) {
    while (node->right != nullptr) {
        node = node->right;
    }
    return node;
}

void SplayTree::printHelper(NodePtr nodePtr, std::string indent, bool last) {
    if (nodePtr != nullptr) {
        std::cout<<indent;
        if (last) {
            std::cout<<"└────";
            indent += "     ";
        } else {
            std::cout<<"├────";
            indent += "|    ";
        }

        std::cout << nodePtr->data << std::endl;

        printHelper(nodePtr->left, indent, false);
        printHelper(nodePtr->right, indent, true);
    }
}

void SplayTree::prettyPrint() {
    printHelper(this->root, "", true);
}


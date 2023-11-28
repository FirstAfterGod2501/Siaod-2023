//
// Created by first on 16.11.23.
//

#include "SplayTreeTests.h"
#include "../../SplayTree/SplayTree.h"

SplayTreeTests::SplayTreeTests() {
    auto spl = new SplayTree;

    spl->insert(2);

    if(spl->search(2)){
        std::cout<< "splay tree insert and search test passed\n";
    }

    spl->remove(2);


    if(!spl->search(2)){
        std::cout<< "splay delete test passed\n";
    }
}

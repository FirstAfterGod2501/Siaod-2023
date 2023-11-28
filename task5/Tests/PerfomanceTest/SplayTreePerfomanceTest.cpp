//
// Created by first on 16.11.23.
//

#include <random>
#include "SplayTreePerfomanceTest.h"
#include "../../SplayTree/SplayTree.h"
#include "../../SplayTreeService/TreePrinter.h"

SplayTreePerformanceTest::SplayTreePerformanceTest() {
    auto spl = new SplayTree();

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(1,10000); // distribution in range [1, 6]

    std::vector<int> vecOfValue;
    std::vector<int> vecOfKeys;

    clock_t start = clock();
    for (int i = 0; i < 100000; ++i) {
        auto value = dist(rng);
        spl->insert(value);
        if(i == 250 || i == 400 || i == 600) {
            vecOfValue.push_back(value);
            vecOfKeys.push_back(value);
        }
    }

    int cnt = 0;
    for (int i = 0; i < vecOfKeys.size(); ++i) {
        if(spl->search(vecOfKeys[i])->data == vecOfValue[i]){
            cnt++;
        }
    }

    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;

    if(cnt == vecOfKeys.size()){
        std::cout << "test passed with " << seconds << "s\n";
    }


    auto tree = new TreePrinter();
    tree->printExpressionTree(spl->GetRoot());

    std::cout<<"\n\n\n";
    spl->prettyPrint();
}

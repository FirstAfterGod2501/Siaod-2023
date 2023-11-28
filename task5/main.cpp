

#include "Tests/BinaryTreeTests/BinaryTreeTests.h"
#include "Tests/SplayTreeTests/SplayTreeTests.h"
#include "Tests/PerfomanceTest/SplayTreePerfomanceTest.h"

int main() {
    new BinaryTreeTests();
    new SplayTreeTests();
    SplayTreePerformanceTest();
}

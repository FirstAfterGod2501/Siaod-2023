#include <iostream>
#include <list>
#include <map>
#include <set>

class ColorGraph {
private:
    int V;

    std::list<int> *adj;

public:
    explicit ColorGraph(int V);
    void addEdge(int v, int w);
    void greedyColoring();
};

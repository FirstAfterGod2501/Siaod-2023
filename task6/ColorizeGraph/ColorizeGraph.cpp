//
// Created by first on 21.11.23.
//

#include "ColorizeGraph.h"

ColorGraph::ColorGraph(int V) {
    this->V = V;
    adj = new std::list<int>[V];
}

void ColorGraph::addEdge(int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void ColorGraph::greedyColoring() {
    std::map<int, int> result;
    std::set<int> available;

    for (int u = 0; u < V; u++) {
        result[u] = -1;
        available.insert(u);
    }

    result[0] = 0;

    for (int u = 1; u < V; u++) {
        for (int & it : adj[u]) {
            if (result[it] != -1) {
                available.erase(result[it]);
            }
        }

        result[u] = *available.begin();
        available.insert(u);
    }

    std::cout << "Minimal number of colors required: " << *available.rbegin() << std::endl;
    std::cout << "Coloring of vertices: " << std::endl;
    for (int u = 0; u < V; u++) {
        std::cout << "Vertex " << u << " --> Color " << result[u] << std::endl;
    }
}
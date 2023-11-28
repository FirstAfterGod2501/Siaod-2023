//
// Created by first on 21.11.23.
//

#include <iostream>
#include <vector>
#include <stack>
#include "ColorizeGraph/ColorizeGraph.h"

class Graph {
private:

    int V;

    std::vector<std::vector<int>> adjacencyMatrix;

public:

    std::string dotOut;

    explicit Graph(int vertices) {
        V = vertices;
        adjacencyMatrix.resize(V, std::vector<int>(V, 0));
    }

    void addEdge(int u, int v) {
        adjacencyMatrix[u][v] = 1;
        adjacencyMatrix[v][u] = 1;

        dotOut += std::to_string(u) + "->" + std::to_string(v)+= "\n";
    }

    void depthFirstSearch(int v, std::vector<bool>& visited) {
        std::stack<int> stack;
        stack.push(v);
        visited[v] = true;

        while (!stack.empty()) {
            v = stack.top();
            stack.pop();

            std::cout << v << " ";

            for (int i = 0; i < V; i++) {
                if (adjacencyMatrix[v][i] && !visited[i]) {
                    visited[i] = true;
                    stack.push(i);
                }
            }
        }
    }

    void depthFirstTraversal() {
        std::vector<bool> visited(V, false);

        std::cout << "Depth First Traversal: ";
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                depthFirstSearch(i, visited);
            }
        }
        std::cout << std::endl;
    }

    void minimumSpanningTree() const {
        std::vector<bool> visited(V, false);
        std::stack<int> stack;

        visited[0] = true;
        stack.push(0);

        std::cout << "Minimum Spanning Tree: ";
        while (!stack.empty()) {
            int v = stack.top();
            stack.pop();

            std::cout << v << " ";

            for (int i = 0; i < V; i++) {
                if (!visited[i]) {
                    visited[i] = true;
                    stack.push(i);
                }
            }
        }
        std::cout << std::endl;
    }


    int getDepth() {
        int maxDepth = 0;
        std::vector<bool> visited(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                int depth = 0;
                std::stack<int> stack;
                stack.push(i);
                visited[i] = true;

                while (!stack.empty()) {
                    int v = stack.top();
                    stack.pop();
                    depth = std::max(depth, v);

                    for (int j = 0; j < V; j++) {
                        if (adjacencyMatrix[v][j] && !visited[j]) {
                            visited[j] = true;
                            stack.push(j);
                        }
                    }
                }
                maxDepth = std::max(maxDepth, depth);
            }
        }
        return maxDepth;
    }
};

int colorize() {
    ColorGraph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.greedyColoring();

    return 0;
}

int main() {
    Graph g(6);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(4, 3);
    g.addEdge(2, 5);

    g.depthFirstTraversal();
    g.minimumSpanningTree();
    std::cout<<g.dotOut;
    std::cout << "Depth of the graph: " << g.getDepth() << std::endl << std::endl << std::endl;

    colorize();

    return 0;
}
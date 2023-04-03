#include <iostream>

#include "kahn.hpp"

int main() {
    Graph G(8);
    G.addEdge(1,4);
    G.addEdge(1,6);
    G.addEdge(2,7);
    G.addEdge(3,4);
    G.addEdge(3,7);
    G.addEdge(4,5);
    G.addEdge(7,0);
    G.addEdge(7,5);
    G.addEdge(7,6);

    std::cout << "A Topological Sort: " << std::endl;
    G.topologicalSort();

    return 0;
}
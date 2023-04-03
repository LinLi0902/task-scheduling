#include <iostream>

#include "kahn_file.hpp"

int main(int argc, char** argv) {
    Graph G(argv[1]);

    std::cout << "A Topological Sort: " << std::endl;
    G.topologicalSort();

    return 0;
}
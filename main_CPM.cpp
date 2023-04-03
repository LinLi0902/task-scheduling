#include <iostream>
#include "CPM.hpp"

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
    G.setDuration(0,0.5);
    G.setDuration(1,3.);
    G.setDuration(2,1.2);
    G.setDuration(3,2.5);
    G.setDuration(4,1.);
    G.setDuration(5,2.6);
    G.setDuration(6,3.4);
    G.setDuration(7,0.7);

    G.schedule();
    
    return 0;
}
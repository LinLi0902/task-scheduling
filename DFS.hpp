#pragma once

#include <vector>
#include <list>
#include <stack>

struct Graph {
	int nverts; // No. of vertices

    // Vector containing adjacency lists
	std::vector<std::list<int>> adj;

	Graph(const int &nv); // Constructor

    // Add an edge to the graph
	void addEdge(const int &orig, const int &dest);

    // A recursive function used by topologicalSort
	void topologicalSortRecursive(int &vert, bool visited[], std::stack<int> &Stack);

    // Function to do topological sort
	void topologicalSort();
};
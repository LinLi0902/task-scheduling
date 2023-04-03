#pragma once

#include <vector>
#include <list>
#include <string>

struct Graph {
	int nverts; // No. of vertices

	// Vector containing adjacency lists
	std::vector<std::list<int>> adj;

	Graph(const char *filename); // Constructor

	// Add an edge to graph
	void addEdge(const int &orig, const int &dest);

	// Function to do Topological Sort
	void topologicalSort();
};
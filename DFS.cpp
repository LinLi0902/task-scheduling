#include <iostream>

#include "DFS.hpp"

Graph::Graph(const int &nv) : nverts(nv) {
	adj.resize(nv);
}

void Graph::addEdge(const int &orig, const int &dest) {
	adj[orig].push_back(dest);
}

// A recursive function used by topologicalSort
void Graph::topologicalSortRecursive(int &vert, bool visited[], std::stack<int> &Stack) {
	// Mark the current vertex as visited.
	visited[vert] = true;

	// Recur for all the vertices adjacent to this vertex
	for (auto& i : adj[vert])
		if (!visited[i])
			topologicalSortRecursive(i, visited, Stack);

	// Push current vertex to stack which stores result
	Stack.push(vert);
}

// Function to do Topological Sort
void Graph::topologicalSort() {
	std::stack<int> Stack;

	// Mark all the vertices as not visited
	bool* visited = new bool[nverts];
	for (int i = 0; i < nverts; i++)
		visited[i] = false;

	// Call the recursive function to store Topological Sort starting from all vertices one by one
	for (int i = 0; i < nverts; i++)
		if (!visited[i])
			topologicalSortRecursive(i, visited, Stack);

	// Print contents of stack
	while (!Stack.empty()) {
		std::cout << Stack.top() << " ";
		Stack.pop();
	}
    std::cout << std::endl;
}
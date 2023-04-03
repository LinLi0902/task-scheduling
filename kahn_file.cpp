#include <iostream>
#include <string>
#include <queue>
#include <fstream>
#include <sstream>

#include "kahn_file.hpp"

void Graph::addEdge(const int &orig, const int &dest) {
	adj[orig].push_back(dest);
}

Graph::Graph(const char *filename) {
	std::ifstream myfile;
	myfile.open(filename);
	std::string line;
	std::getline(myfile, line);
	std::stringstream ss(line);
	int nv;
	ss >> nv;
	nverts = nv;
	adj.resize(nverts);
	while (std::getline(myfile, line)) {
		std::stringstream ss(line);
		int orig, dest;
		ss >> orig;
		ss >> dest;
		addEdge(orig, dest);
	}
	myfile.close();
}

// Function to do Topological Sort
void Graph::topologicalSort() {
	// Create an empty vector to store a topological sort
	std::vector<int> topoSort;

	// Create a vector to store the indegree of each vertex
    std::vector<int> indegree(nverts, 0);

	// Traverse adjacency lists to fill indegrees of vertices
	for (int i = 0; i < nverts; ++i) {
		for (int j = 0; j < nverts; ++j) {
			auto it = std::find(adj[j].begin(), adj[j].end(), i);
			if (it != adj[j].end())
				indegree[i]++;
		}
	}

	// Create a queue to store all vertices with no incoming edges
	std::queue<int> no_incoming;
	for (int i = 0; i < nverts; ++i){
		if (indegree[i] == 0)
			no_incoming.push(i);
	}

	// Dequeue vertices one by one and enqueue adjacents if indegree of adjacent becomes 0
	while (!no_incoming.empty()) {

		// Extract front of the queue and add it to the topological sort
		int n = no_incoming.front();
		no_incoming.pop();
		topoSort.push_back(n);

		// Traverse all adjacent vertices of the removed one and decrease their in-degree by 1
		std::list<int> adj_copy(adj[n]);
		for (const auto &m : adj_copy) {
			adj[n].remove(m);
			indegree[m]--;

			// Add it to the queue if in-degree becomes zero
			if (indegree[m] == 0)
				no_incoming.push(m);
		}

	}

	// Check if there exists a cycle
	bool adj_empty = true;
	for (int i = 0; i < nverts; ++i) {
		if (!adj[i].empty())
			adj_empty = false;
	}
	if (!adj_empty) {
		std::cerr << "The graph has at least one cycle." << std::endl;
		return;
	}
	
	// Print the topological sort
	for (int i = 0; i < nverts; ++i)
        std::cout << topoSort[i] << " ";
    std::cout << std::endl;
}
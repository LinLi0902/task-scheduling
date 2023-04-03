#include <iostream>
#include <algorithm>

#include "CPM.hpp"

Graph::Graph(const int &nv) : nverts(nv) {
	adj.resize(nv);
	duration.resize(nv);
}

void Graph::addEdge(const int &orig, const int &dest) {
	adj[orig].push_back(dest);
}

void Graph::setDuration(const int &vert, const double &dur) {
	duration[vert] = dur;
}

// Compute the earliest finish time for each vertex
void Graph::dfs(const int &vert, std::vector<double> &finish_time) {
	for (const auto &neighbor : adj[vert]) {
        finish_time[neighbor] = std::max(finish_time[neighbor], finish_time[vert] + duration[neighbor]);
        dfs(neighbor, finish_time);
    }
}

// Function to schedule the tasks
void Graph::schedule() {
	// Create two vectors to store the start and finish times of each vertex
	std::vector<double> start_time(nverts);
	std::vector<double> finish_time(nverts);

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

	// Create a list to store all vertices that do not have any dependencies
	std::list<int> no_incoming;
	for (int i = 0; i < nverts; ++i){
		if (indegree[i] == 0)
			no_incoming.push_back(i);
	}

	// Use topological sort to check if there exists a cycle
	std::list<int> no_incoming_copy(no_incoming);
	std::vector<std::list<int>> adj_copy(adj);
	while (!no_incoming_copy.empty()) {
		int n = no_incoming_copy.back();
		no_incoming_copy.pop_back();
		for (const auto &m : adj[n]) {
			adj_copy[n].remove(m);
			indegree[m]--;
			if (indegree[m] == 0)
				no_incoming_copy.push_back(m);
		}

	}
	bool adj_empty = true;
	for (int i = 0; i < nverts; ++i) {
		if (!adj_copy[i].empty())
			adj_empty = false;
	}
	if (!adj_empty) {
		std::cerr << "The graph has at least one cycle." << std::endl;
		return;
	}

	// Compute finish time for all vertices that do not have any dependencies
    for (const auto &i : no_incoming) {
        finish_time[i] = duration[i];
        dfs(i, finish_time);
    }

    // Compute start time for all vertices and print its start and finish time
    for (int i = 0; i < nverts; i++) {
        start_time[i] = finish_time[i] - duration[i];
		std::cout << "Start time for task  " << i << " : " << start_time[i] << std::endl;
		std::cout << "Finish time for task " << i << " : " << finish_time[i] << std::endl;
    }

	std::vector<double>::iterator result = std::max_element(finish_time.begin(), finish_time.end());
    std::cout << "Minimum completion time: " << *result << std::endl;
}
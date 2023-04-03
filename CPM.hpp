#pragma once

#include <vector>
#include <list>
#include <string>

struct Graph {
	int nverts; // No. of vertices

	// Vector containing adjacency lists
	std::vector<std::list<int>> adj;

	// Vector containing the durations of tasks
	std::vector<double> duration;

	Graph(const int &nv); // Constructor

	// Add an edge to the graph
	void addEdge(const int &orig, const int &dest);

	// Set a duration for a vertex
	void setDuration(const int &vert, const double &dur);

	// Compute the earliest finish time for a vertex
	void dfs(const int &vert, std::vector<double> &finish_time);

	// Function to schedule the tasks
	void schedule();
};
#ifndef __GRAPH_H__
# define __GRAPH_H__

# include <iostream>
# include <vector>
# include <algorithm>
# include <cstdlib>
# include <ctime>
#include <bits/stdc++.h>

class	Graph
{
	private:
		std::vector<std::vector<int>>	graph;
		size_t							vertex;
	public:
		Graph(void);
		~Graph();

		void				display(void);
		bool				has_edge(const int &v1, const int &v2) const;
		bool				has_vertex(const int &v) const;
		size_t				vertex_cout(void) const;
		std::vector<int>	shortest(int start, int end);
		std::vector<int>	get_neighbours(const int &v) const;
		// void				remove_vertex(const int &vertex);
	private:
		std::vector<int>	dfs(int, int, std::unordered_set<int>&, std::vector<int>&, std::vector<int>&);
};

// remove_vertex(vertex): Remove a vertex and all its associated edges from the graph.
// remove_edge(vertex1, vertex2): Remove the edge between two vertices.
// get_neighbors(vertex): Get a list of neighbors for a given vertex.
// has_edge(vertex1, vertex2): Check if there is an edge between two vertices.
// has_vertex(vertex): Check if a vertex exists in the graph.
// vertex_count(): Get the number of vertices in the graph.
// edge_count(): Get the number of edges in the graph.
// connected_components(): Find the connected components of the graph.
// bfs() unordred_set, queue
// dextra's algorithm
// std::pair<int, int>

#endif
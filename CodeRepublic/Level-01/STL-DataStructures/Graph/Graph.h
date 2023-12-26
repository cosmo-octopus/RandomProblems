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
		unsigned int					vertex;
	public:
		Graph(void);
		~Graph();

		void				display(void);
		std::vector<int>	shortest(int start, int end);
	private:
		std::vector<int>	dfs(int, int, std::unordered_set<int>&, std::vector<int>&, std::vector<int>&);
};

#endif
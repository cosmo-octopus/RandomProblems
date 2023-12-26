#ifndef __GRAPH_H__
# define __GRAPH_H__

# include <iostream>
# include <vector>
# include <algorithm>
# include <cstdlib>
# include <ctime>

class	Graph
{
	private:
		std::vector<std::vector<int>>	graph;
		unsigned int					vertex;
	public:
		Graph(void);
		// Graph(int vertex);
		~Graph();

		void	display(void);
};

#endif
#include "Graph.h"

Graph::Graph(void): vertex(10)
{
	unsigned int	edges;
	unsigned int	randomVertex;

	graph.resize(vertex);
	srand(static_cast<unsigned int>(time(0)));
	for (unsigned int i = 0; i < vertex; i++)
	{
		edges = 1 + (rand() % 4);
		for (unsigned int j = 0; j < edges; j++)
		{
			randomVertex = rand() % 10;
			if (randomVertex != i)
				graph[i].push_back(randomVertex);
		}
		std::sort(graph[i].begin(), graph[i].end());
		graph[i].erase(std::unique(graph[i].begin(), graph[i].end()), graph[i].end());
	}
}

Graph::~Graph()
{
	for (int i = 0; i < 10; i++)
		graph[i].clear();
}

void	Graph::display(void)
{
	std::cout << "Graph:" << std::endl;
    for (size_t i = 0; i < vertex; ++i)
	{
        std::cout << "Vertex " << i << " -> ";
        for (size_t j = 0; j < graph[i].size(); ++j)
            std::cout << graph[i][j] << " ";
        std::cout << std::endl;
    }
}
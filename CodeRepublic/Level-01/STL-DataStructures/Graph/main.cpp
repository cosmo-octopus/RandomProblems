#include "Graph.h"

int	main()
{
	Graph	graph;

	graph.display();
	/* dfs test */
	std::vector<int> sh = graph.shortest(0, 9);
	std::cout << "Shortest path between 0 and 9: ";
	if (sh.empty())
		std::cout << "no way" << std::endl;
	else
	{
		for (int i : sh)
			std::cout << i << " ";
		std::cout << std::endl;
	}
	/* has_edge test */
	std::cout << "Is there an edge between 2 anf 5 : " << graph.has_edge(2, 5) << std::endl;
	std::cout << "Is there an edge between 4 anf 7 : " << graph.has_edge(4, 7) << std::endl;
	std::cout << "Is there an edge between 0 anf 8 : " << graph.has_edge(0, 8) << std::endl;
}
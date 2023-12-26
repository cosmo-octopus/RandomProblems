#include "Graph.h"

int	main()
{
	Graph	graph;

	graph.display();
	std::vector<int> sh = graph.shortest(0, 9);
	if (sh.empty())
		std::cout << "No Way" << std::endl;
	else
	{
		for (int i : sh)
			std::cout << i << " "; // Accessing elements directly, not sh[i]
		std::cout << std::endl;
	}
}
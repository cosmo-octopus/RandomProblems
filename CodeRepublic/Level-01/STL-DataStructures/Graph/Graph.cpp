#include "Graph.h"

Graph::Graph(void): vertex(10)
{
	size_t	edges;
	size_t	randomVertex;

	graph.resize(vertex);
	srand(static_cast<unsigned int>(time(0)));
	for (size_t i = 0; i < vertex; i++)
	{
		edges = 1 + (rand() % 4);
		for (size_t j = 0; j < edges; j++)
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
	for (size_t i = 0; i < vertex; i++)
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

std::vector<int>	Graph::shortest(int start, int end)
{
	std::unordered_set<int>	visited;
	std::vector<int>		path;
	std::vector<int>		shortPath;

	return (dfs(start, end, visited, path, shortPath));
}

std::vector<int> Graph::dfs(int curr, int dst, std::unordered_set<int> &v, std::vector<int> &p, std::vector<int> &sh)
{
    v.insert(curr);
    p.push_back(curr);

    if (curr == dst)
    {
        if (sh.empty() || p.size() < sh.size())
            sh = p;
    }
    else
    {
        for (int neighbour : graph[curr])
        {
            if (v.find(neighbour) == v.end())
                dfs(neighbour, dst, v, p, sh);
        }
    }
    p.pop_back();
    v.erase(curr);
    return (sh);
}

bool	Graph::has_edge(const int &v1, const int &v2) const
{
	for (int neighbour : graph[v1])
	{
		if (neighbour == v2)
			return (true);
	}
	return (false);
}

size_t	Graph::vertex_cout(void) const
{
	return (this->vertex);
}

bool	Graph::has_vertex(const int &v) const
{
	if (v >=0 && v < this->vertex)
		return (true);
	return (false);
}

std::vector<int>	Graph::get_neighbours(const int &v) const
{
	if (!has_vertex(v))
		throw std::invalid_argument("Error: vertex doesn't exist");
	return (graph[v]);
}
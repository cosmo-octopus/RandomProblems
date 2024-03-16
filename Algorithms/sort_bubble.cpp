/**************************
	Best Case: O(n)
	Average Case: O(n^2)
	Worst Case: O(n^2)
**************************/

#include <iostream>
#include <vector>


/*
void	sort_bubble(std::vector<int>& vec)
{
	for (auto it1 = vec.begin(); it1 != vec.end(); ++it1)
	{
		for (auto it2 = vec.begin(); it2 != vec.end(); ++it2)
			if (*it1 < *it2)
				std::swap(*it1, *it2);
	}
}
*/

/*
void	sort_bubble(std::vector<int>& vec)
{
	for (auto it1 = --vec.end(); it1 != vec.begin() - 1; --it1)
	{
		for (auto it2 = vec.begin(); it2 != it1; ++it2)
			if (*it1 < *it2)
				std::swap(*it1, *it2);
	}
}
*/

/* bubble sort with a better performance */
void	sort_bubble(std::vector<int>& vec)
{
	bool	swap = true;

	for (auto it1 = vec.begin(); it1 != vec.end(); ++it1)
	{
		swap = false;
		for (auto it2 = vec.begin(); it2 != vec.end(); ++it2)
		{
			if (*it1 < *it2)
			{
				std::swap(*it1, *it2);
				swap = true;
			}
		}
	}
}

int	main()
{
	std::vector<int>	vec{70, 124, 8, 1, 34, 189, 105, 16, 132, 173, 144, 71, 167, 200, 48};

	sort_bubble(vec);
	for (auto it = vec.cbegin(); it != vec.cend(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}
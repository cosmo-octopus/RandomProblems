/***************************
	Best Case: O(n^2)
	Average Case: O(n^2)
	Worst Case: O(n^2)
***************************/

#include <iostream>
#include <vector>

void	sort_selection(std::vector<int>& vec)
{
	for (auto it1 = vec.begin(); it1 != vec.end(); ++it1)
	{
		auto key = it1;
		for (auto it2 = it1 + 1; it2 != vec.end(); ++it2)
		{
			if (*it2 < *key)
				key = it2;
		}
		if (key != it1)
			std::swap(*it1, *key);
	}
}

/*
using iterator = std::vector<int>::iterator;

void	sort_selection_rec(std::vector<int>&vec, iterator it1, iterator it2, iterator key)
{
	if (it1 == vec.end())
		return ;

	if (it2 != vec.end())
	{
		key = *key > *it2 ? it2 : key;
		++it2;
	}
	else
	{
		std::swap(*it1, *key);
		++it1;
		key = it1;
		it2 = it1 + 1;
	}
	sort_selection_rec(vec, it1, it2, key);
}
*/

int	main()
{
	std::vector<int>	vec{70, 124, 8, 1, 34, 189, 105, 16, 132, 173, 144, 71, 167, 200, 48};

	sort_selection(vec);
	// sort_selection_rec(vec, vec.begin(), vec.begin() + 1, vec.begin());
	for (auto it = vec.cbegin(); it != vec.cend(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}


/*
	Best Case: O(n)
	Average Case: O(n^2)
	Worst Case: O(n^2)
*/

#include <iostream>
#include <vector>

void	sort_insertion(std::vector<int>& vec)
{
	for(auto it = vec.begin(); it != vec.end() - 1; ++it)
	{
		auto it1 = it;
		auto it2 = it1 + 1;
		while (*it2 < *it1)
			std::swap(*(it1--), *(it2--));
	}
}

int	main()
{
	std::vector<int>	vec{70, 124, 8, 1, 34, 189, 105, 16, 132, 173, 144, 71, 167, 200, 48};

	sort_insertion(vec);
	for (auto it = vec.cbegin(); it != vec.cend(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

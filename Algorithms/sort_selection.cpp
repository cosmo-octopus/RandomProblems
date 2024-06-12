/****************************/
/*	Best Case: O(n^2)		*/
/*	Average Case: O(n^2)	*/
/*	Worst Case: O(n^2)		*/
/****************************/

#include <iostream>
#include <vector>

void	sort_selection(std::vector<int>& vec)
{
	for (size_t i = 0; i < vec.size(); ++i)
	{
		size_t min_idx = i;
		size_t idx = i;
		while (idx < vec.size())
		{
			if (vec[min_idx] > vec[idx])
				min_idx = idx;
			idx ++;
		}
		std::swap(vec[i], vec[min_idx]);
	}
}

int	main()
{
	std::vector<int>	vec{70, 124, 8, 1, 34, 189, 105, 16, 132, 173, 144, 71, 167, 200, 48};

	sort_selection(vec);

	for (auto it = vec.cbegin(); it != vec.cend(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}


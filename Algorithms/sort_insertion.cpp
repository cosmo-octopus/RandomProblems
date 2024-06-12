/****************************/
/*	Best Case: O(n)			*/
/*	Average Case: O(n^2)	*/
/*	Worst Case: O(n^2)		*/
/****************************/

#include <iostream>
#include <vector>

void	sort_insertion(std::vector<int>& vec)
{
	for (size_t i = 0; i < vec.size(); ++i)
	{
		int key = vec[i];
		size_t j = i - 1;

		while (j >= 0 && vec[j] > key)
		{
			vec[j + 1] = vec[j];
			j --;
		}

		vec[j + 1] = key;
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

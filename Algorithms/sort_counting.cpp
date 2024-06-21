#include <iostream>
#include <vector>

/**
 * Time Complexity: best/average/worst O ( n + k )
 * Space Complexity: O ( n + k )
 * 
 * ADVANTAGES:
 * 	1. faster than all comparison-based sorting algorithms
 * 	2. stable algorithm
 * DISATVANTAGES:
 * 	1. inefficient if the range of values to be sorted is very large
 * 	2. doesn’t work on decimal values
 * 	3.not an In-place sorting algorithm, It uses extra space
*/

std::vector<int> sort_counting(const std::vector<int>& vec)
{
	int size = vec.size();
	int max = vec.at(0);

	for (int i = 0; i < size; ++i)
		max = std::max(max, vec[i]);
	
	std::vector<int> count(max + 1, 0);

	for (int i = 0; i < size; ++i)
		count[vec[i]] ++;

	for (size_t i = 1; i < count.size(); ++i)
		count[i] += count[i - 1];

	std::vector<int> ans(size, 0);

	for (int i = 0; i < size; ++i)
	{
		ans[count[vec[i]] - 1] = vec[i];
		count[vec[i]] --;
	}

	return ans;

}

int	main()
{
	std::vector<int> vec { 4, 3, 12, 1, 5, 5, 3, 9 };

	vec = sort_counting(vec);

	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << vec[i] << " ";
}
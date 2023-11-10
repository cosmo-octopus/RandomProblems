/*
PROBLEM: Consider the leftmost and righmost appearances
of some value in an array. We'll say that the "span"
is the number of elements between the two inclusive.
A single value has a span of 1. Returns the largest span
found in the given array. (Efficiency is not a priority.)

maxSpan([1, 2, 1, 1, 3]) → 4
maxSpan([1, 4, 2, 1, 4, 1, 4]) → 6
maxSpan([1, 4, 2, 1, 4, 4, 4]) → 6
*/

#include <iostream>
#include <vector>

int	getMaxSpan(const std::vector<int> &vec)
{
	const std::size_t	size = vec.size();
	int					max_span = 0;
	int					i, j;

	i = -1;
	while (++i < size)
	{
		j = size - 1;
		while(j > i && vec[j] != vec[i])
			j--;
		if (j - i > max_span)
			max_span = j - i + 1;
	}
	return(max_span == 0 && size > 0) ? 1 : max_span;
}

int	main()
{
	int arr[] = {1, 2, 1, 1, 3};
    int arr2[] = {1, 4, 2, 1, 4, 1, 4};
    int arr3[] = {1, 4, 2, 1, 4, 4, 4};
    int arr4[] = {3, 3, 3};
    int arr5[] = {3, 9, 9};
    int arr6[] = {1, 2, 3};
    std::cout << getMaxSpan(std::vector<int>(arr, arr + 5)) << std::endl;
    std::cout << getMaxSpan(std::vector<int>(arr2, arr2 + 7)) << std::endl;
    std::cout << getMaxSpan(std::vector<int>(arr3, arr3 + 7)) << std::endl;
    std::cout << getMaxSpan(std::vector<int>(arr4, arr4 + 3)) << std::endl;
    std::cout << getMaxSpan(std::vector<int>(arr5, arr5 + 3)) << std::endl;
    std::cout << getMaxSpan(std::vector<int>(0)) << std::endl;
    std::cout << getMaxSpan(std::vector<int>(arr6, arr6 + 1)) << std::endl;

    return 0;
}
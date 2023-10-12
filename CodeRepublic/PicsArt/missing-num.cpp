/*
PROBLEM: Given an array containing n distinct numbers taken from the range [1, n+1],
find the missing number.

Input Example: [3, 7, 1, 2, 8, 4, 5]
Output Example: 6
*/

#include <iostream>

int	missingNum(int *arr, int range)
{
	int	range_sum = range * (1 + range) / 2;
	int	sum = 0;
	int	i = -1;

	while (++i < range - 1)
		sum += arr[i];
	return (range_sum - sum);
}

int	main()
{
	int	arr[] = {3, 7, 1, 2, 8, 4, 5};
	std::cout << "The missing number is: " << missingNum(arr, 8) << std::endl;
	return (0);
}
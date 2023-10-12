/*
PROBLEM: Given an array containing n distinct numbers taken from the range [1, n+1],
find the two missing numbers.

Input Example: [3, 7, 1, 2, 8, 4, 5, 10]
Output Example: 6 and 10
*/

#include <iostream>

bool	isMember(int *arr, int range, int num)
{
	int	i = -1;

	while (++i < range - 2)
	{
		if (arr[i] == num)
			return (true);
	}
	return (false);
}

int	missingSum(int *arr, int range)
{
	int	range_sum = range * (1 + range) / 2;
	int	sum = 0;
	int	i = -1;

	while (++i < range - 2)
		sum += arr[i];
	return (range_sum - sum);
}

int	main()
{
	int	arr[] = {3, 7, 1, 2, 8, 4, 5, 10};

	int	num;
	int	sum = missingSum(arr, 10);

	num = 1;
	while (num < sum)
	{
		if (!isMember(arr, 10, num) && !isMember(arr, 10, sum - num))
			break ;
		num ++;
	}

	std::cout << "The missing numbers are: " << num << " and " << sum - num << std::endl;
}
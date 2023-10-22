/*
PROBLEM: Given an array of numbers sorted in ascending order and a target sum,
find a pair in the array whose sum is equal to the given target.

Write a function to return the indices of the two numbers (i.e. the pair)
such that they add up to the given target.

Example 1:
Input: [1, 2, 3, 4, 6], target=6
Output: [1, 3]
Explanation: The numbers at index 1 and 3 add up to 6: 2+4=6
*/

#include <iostream>
#include <vector>

class Solution
{
  public:

  static std::vector<int> search(const std::vector<int> &arr, int target)
  {
    std::vector<int>	res(2, -1);
	int					left = 0, right = arr.size() - 1;
	int					sum;

	while (left < right)
	{
		sum = arr[left] + arr[right];
		if (sum == target)
		{
			res[0] = left;
			res[1] = right;
			return (res);
		}
		if (sum < target)
			left++;
		else
			right--;
	}
    return (res);
  }
};

int main(void)
{
	auto result = Solution::search(std::vector<int>{1, 2, 3, 4, 6}, 6);
	std::cout << "Pair with target sum: [" << result[0] << ", " << result[1] << "]" 
    	<< std::endl;
	result = Solution::search(std::vector<int>{2, 5, 9, 11}, 11);
	std::cout << "Pair with target sum: [" << result[0] << ", " << result[1] << "]" 
    	<< std::endl;
}
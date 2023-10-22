/*
PROBLEM: Given an array of sorted numbers, move all non-duplicate number instances
at the beginning of the array in-place. The relative order of the elements should
be kept the same and you should not use any extra space so that the solution has
constant space complexity i.e. O(1).

Move all the unique number instances at the beginning of the array and after moving
return the length of the subarray that has no duplicate in it.

Example 1:
Input: [2, 3, 3, 3, 6, 9, 9]
Output: 4
Explanation: The first four elements after moving element will be [2, 3, 6, 9].
*/

#include <iostream>
#include <vector>

class RemoveDuplicates
{
	public:
	static int remove(std::vector<int>& arr)
	{
    	int nextNonDuplicate = 1;
    	for (int i = 0; i < arr.size(); i++)
		{
      		if (arr[nextNonDuplicate - 1] != arr[i])
			{
        		arr[nextNonDuplicate] = arr[i];
        		nextNonDuplicate++;
    		}	
    	}
    	return (nextNonDuplicate);
	}
};

int main(void)
{
	std::vector<int> arr = {2, 3, 3, 3, 6, 9, 9};
	std::cout << "Array new length: " << RemoveDuplicates::remove(arr) << std::endl;

	arr = std::vector<int>{2, 2, 2, 11};
	std::cout << "Array new length: " << RemoveDuplicates::remove(arr) << std::endl;
}
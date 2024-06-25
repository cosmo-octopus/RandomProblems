#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int findFinalValue(std::vector<int>& nums, int original) {
        while (std::find(nums.begin(), nums.end(), original) != nums.end())
            original *= 2;
        return original;
    }
};

int main()
{
	Solution s;
	std::vector<int> vec{5,3,6,1,12};

	std::cout << s.findFinalValue(vec) << std::endl;
}
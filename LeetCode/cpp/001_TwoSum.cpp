#include <iostream>
#include <vector>
#include <unordered_map>

class Solution{
public:
	/* O(n) */
    std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
        std::unordered_map<int, int> pair_idx;

        for (int i = 0; i < nums.size(); ++i)
        {
			int	diff = target - nums[i];
            if (pair_idx.find(diff) != pair_idx.end())
                return {i, pair_idx[diff]};
            pair_idx[nums[i]] = i;
        }
        return {};        
    }
};
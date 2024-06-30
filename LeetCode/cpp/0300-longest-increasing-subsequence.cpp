#include <iostream>
#include <vector>
#include <algorithm>

// TIME: O( n^2 ) | SPACE: O ( n )
class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        int size = nums.size();
        std::vector<int> dp(size, 1);

        for (int i = size - 1; i >= 0; --i)
        {
            for (int j = i + 1; j < size; ++j)
            {
                if (nums[i] < nums[j])
                    dp[i] = std::max(dp[i], 1 + dp[j]);
            }
        }
        return *std::max_element(dp.begin(), dp.end());
    }
};

int main()
{
	Solution s;
	std::vector<int> vec{10, 9, 2, 5, 3, 7, 101, 18};

	std::cout << s.lengthOfLIS(vec);
}
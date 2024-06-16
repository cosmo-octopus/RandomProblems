#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>
#include <algorithm>

// Time complexity: O(n log n) | Space complexity: O(n)

class Solution {
public:
	static bool comp (const std::pair<int, int>&a, const std::pair<int, int>&b)
    {
        return a.second < b.second;
    }
	void add (std::pair<int, int>&p, std::vector<int>& v)
	{
		for (int i = 0; i < p.second; ++i)
			v.push_back(p.first);
	}
    std::vector<int> frequencySort(std::vector<int>& nums) {
        std::unordered_map<int, int> m;
        std::vector<std::pair<int, int>> v;
        std::vector<int> res;

        for (int n : nums)
            m[n] ++;
        int i = 0;
        for (auto it : m)
            v.push_back({it.first, it.second});

		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());
		stable_sort(v.begin(), v.end(), comp);

		for (auto it : v)
			add(it, res);
		
		return res;
    }
};

int main()
{
	std::vector<int>v {-1,1,-6,4,5,-6,1,4,1};

	Solution s;
	v = s.frequencySort(v);

	for (int n : v)
		std::cout << n << " ";
}


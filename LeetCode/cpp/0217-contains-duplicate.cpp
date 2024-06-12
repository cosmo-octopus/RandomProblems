#include <iostream>
#include <vector>
#include <unordered_set>
#include <chrono>


// Time complexity: O(n) | Space complexity: O(n)

bool containsDuplicate(std::vector<int>& nums) {
	std::unordered_set<int> set;

	for (size_t i = 0; i < nums.size(); ++i)
	{
		if (set.find(nums[i]) != set.end())
			return true;
		set.insert(nums[i]);
	}
	return false;
}

int main()
{
	std::vector<int> vec;
	for (int i = 0; i < 1000000; ++i) {
		vec.push_back(i);
	}

	// Measuring execution time for vector with no duplicates
	auto start = std::chrono::high_resolution_clock::now();
	bool result = containsDuplicate(vec);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = end - start;
	std::cout << "Result (no duplicates): " << std::boolalpha << result << "\n";
	std::cout << "Time taken (no duplicates): " << elapsed.count() << " seconds\n";

	// Generating a large vector with duplicates
	vec.push_back(500000);  // Adding a duplicate
	start = std::chrono::high_resolution_clock::now();
	result = containsDuplicate(vec);
	end = std::chrono::high_resolution_clock::now();
	elapsed = end - start;
	std::cout << "Result (with duplicates): " << std::boolalpha << result << "\n";
	std::cout << "Time taken (with duplicates): " << elapsed.count() << " seconds\n";

	return 0;
}
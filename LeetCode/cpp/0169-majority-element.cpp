#include <iostream>
#include <vector>
#include <chrono>


// Time complexity: O(n) | Space complexity: O(1)

int majorityElement(std::vector<int>& nums) {
	int count = 0;
	int max_count = 0;

	for (size_t i = 0; i < nums.size(); ++i)
	{
		if (count == 0)
		{
			max_count = nums[i];
			count ++;
		}
		else if (max_count == nums[i])
			count ++;
		else
			count --;
	}
	return max_count;
}

int main() {
    // Test with a small vector
    std::vector<int> smallVector = {2, 2, 1, 1, 1, 2, 2};
    std::cout << "Majority element in smallVector: " << majorityElement(smallVector) << "\n";

    // Generating a large vector with a majority element
    std::vector<int> largeVector(1000000, 1);
    for (int i = 500000; i < 1000000; ++i) {
        largeVector[i] = 2;
    }

    // Measuring execution time for large vector
    auto start = std::chrono::high_resolution_clock::now();
    int result = majorityElement(largeVector);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Majority element in largeVector: " << result << "\n";
    std::cout << "Time taken for largeVector: " << elapsed.count() << " seconds\n";

    return 0;
}
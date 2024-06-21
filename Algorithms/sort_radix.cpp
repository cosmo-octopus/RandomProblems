#include <iostream>
#include <vector>

/**
 * Time Complexity: O ( n + b )
 * Space Complexity: O ( n + b )
*/

int	get_max(const std::vector<int>& vec)
{
	int max = vec.at(0);

	for (size_t i = 0; i < vec.size(); ++i)
		max = std::max(max, vec[i]);
	return max;
}

void sort_counting(std::vector<int>& vec, int exp)
{
	int size = vec.size();
	std::vector<int> count(10 + 1, 0);

	for (int i = 0; i < size; ++i)
		count[(vec[i] / exp) % 10] ++;

	for (int i = 1; i < 10; ++i)
		count[i] += count[i - 1];

	std::vector<int> ans(size, 0);

	for (int i = size - 1; i >= 0; --i)
	{
		ans[count[(vec[i] / exp) % 10] - 1] = vec[i];
		count[(vec[i] / exp) % 10] --;
	}

	for (int i = 0; i < size; ++i)
		vec[i] = ans[i];
}

void sort_radix(std::vector<int>& vec)
{
	int max = get_max(vec);

	for (int exp = 1; max / exp > 0; exp *= 10)
		sort_counting(vec, exp);
}

int main()
{
	std::vector<int> vec { 170, 45, 75, 90, 802, 24, 2, 66 };

	sort_radix(vec);

	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << vec[i] << " ";
}
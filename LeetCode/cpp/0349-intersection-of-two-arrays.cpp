#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::vector<int> res;
    std::unordered_map<int, bool> map;

    for (int n : nums1)
        map[n] = true;

    for (int n : nums2)
    {
        if (map.find(n) != map.end() && map[n])
        {
            map[n] = false;
            res.push_back(n);
        }
    }
    return res;
}

int main() {

    std::vector<int> nums1 = {1, 2, 2, 1};
    std::vector<int> nums2 = {2, 2};

    std::vector<int> result = intersection(nums1, nums2);

    std::cout << "Intersection of nums1 and nums2: ";
    for (int n : result) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}
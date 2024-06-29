#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int total = 0;
        int size = std::max(startPos, fruits.back().front()) + 1;
        std::vector<int> prefix_sum(size, 0);

        for (auto& it : fruits) prefix_sum[it[0]] = it[1];
        for (int i = 1; i < size; ++i) prefix_sum[i] += prefix_sum[i - 1];

        int lsteps, rsteps;
        for (int r = startPos; r < size && r <= startPos + k; ++r)
        {
            rsteps = r - startPos;
            lsteps = k - 2 * rsteps;
            if (lsteps < 0)
                lsteps = 0;
            int l = startPos - lsteps;
            if (l < 0)
                l = 0;
            total = std::max(total, prefix_sum[r] - (l > 0 ? prefix_sum[l - 1] : 0));
        }

        for (int l = startPos; l >= 0 && l >= startPos - k; --l)
        {
            lsteps = startPos - l;
            rsteps = k - 2 * lsteps;
            if (rsteps < 0)
                rsteps = 0;
            int r = startPos + rsteps;
            if (r >= size)
                r = size - 1;
            total = std::max(total, prefix_sum[r] - (l > 0 ? prefix_sum[l - 1] : 0));
        }

        return total;
    }
};

int main() {
  Solution s;
//   std::vector<std::vector<int>> vec {{2,8},{6,3},{8,6}};
  std::vector<std::vector<int>> vec {{0, 10000}};
  
//   s.maxTotalFruits(vec, 5, 4);
  s.maxTotalFruits(vec, 20000, 20000);

  return 0;
}
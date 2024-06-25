#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    int finalValueAfterOperations(std::vector<std::string>& operations) {
        int num = 0;

        for (auto it = operations.begin(); it != operations.end(); ++it)
        {
            if ((*it).find("--") != std::string::npos)
                num --;
            else
                num ++;
        }
        return num;
    }
};

int main()
{
	Solution s;
	std::vector<std::string> op = {"X++","++X","--X","X--"};
	std::cout << s.finalValueAfterOperations(op) << std::endl;
}
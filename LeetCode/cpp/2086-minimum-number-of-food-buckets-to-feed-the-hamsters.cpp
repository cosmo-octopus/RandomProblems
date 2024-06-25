#include <iostream>
#include <string>

class Solution {
public:
    int minimumBuckets(std::string hamsters) {
        int size = hamsters.size();
        int bucket = 0;

        for (int i = 0; i < size; ++i)
        {
            if (hamsters[i] == 'H')
            {
                if (i > 0 && hamsters[i - 1] == 'b')
                    continue ;
                if ((i == size - 1 || hamsters[i + 1] != '.')
                    && (i > 0 && hamsters[i - 1] == '.'))
                {
                    hamsters[i - 1] = 'b';
                    bucket ++;
                    continue ;
                }
                if (i == size - 1 || (i < size - 1 && hamsters[i + 1] != '.'))
                    return -1;
                if (hamsters[i + 1] == '.')
                {
                    hamsters[i + 1] = 'b';
                    bucket ++;
                }
            }
        }

        return bucket;
    }
};

int main()
{
	Solution s;
	std::string str{".H.H."};

	std::cout << s.minimumBuckets(str) << std::endl;
}
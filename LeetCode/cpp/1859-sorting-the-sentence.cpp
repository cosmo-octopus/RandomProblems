#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>


// Time complexity: O(n) | Space complexity: O(n)

std::string sortSentence(std::string s) {

	std::unordered_map<int, std::string> map;
    std::string str;

    for (int i = 0; i < s.size(); ++i)
    {
        if (isalpha(s[i]))
            str += s[i];
        else if (s[i] != ' ') // is num
        {
            int num = s[i] - '0';
            map[num] = str + " ";
            str = "";
        }
    }

    for (int i = 0; i < s.size(); ++i)
        str += map[i];

    str.pop_back();
    return str;
}
    
int main()
{  
	std::cout << "FINAL: " << \
    sortSentence("eHwJm5 xvJDHiymHBeCO2 uQjltjGlmIPdeOHsXSuD1 Vgf3 yXacYhRKVGlvukQRMal4") \
    << std::endl;
}
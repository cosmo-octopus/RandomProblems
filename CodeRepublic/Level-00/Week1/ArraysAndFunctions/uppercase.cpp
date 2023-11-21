/* PROBLEM: Write a function that takes
a string (std::string) as input, converts
it to uppercase, and returns the same string
with all uppercase letters*/

#include <iostream>
#include <string>
using namespace std;

void    ft_uppercase(string& str)
{
    int len = str.length();
    int i = 0;

    while (i < len)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
        i++;
    }
}

int main()
{
    string str = "";
    cout << "Input: ";
    cin >> str;
    ft_uppercase(str);
    cout << str << endl;
}
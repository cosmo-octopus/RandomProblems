#include <iostream>
#include <cstring>
using namespace std;

int ft_split(char *str)
{
    int counter = 0;

    while(*str)
    {
        while (*str && *str == ' ')
            ++str;
        if (*str && *str != ' ')
            counter++;
        while (*str && *str != ' ')
            ++str;
    }
    return (counter);
}

int main()
{
    char    str[] = "hello";

    cout << ft_split(str) << endl;
}
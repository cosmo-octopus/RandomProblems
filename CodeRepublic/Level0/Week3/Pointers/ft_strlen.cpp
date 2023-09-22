/* PROBLEM: Implement <cstring> strlen
without using any additional variables. */

#include <iostream>
using namespace std;

int ft_strlen(const char *str)
{
    if (*str)
        return (1 + ft_strlen(++str));
    else
        return (0);
}

int main()
{
    const char *ptr = "Hello";
    cout << ft_strlen(ptr) << endl;
}
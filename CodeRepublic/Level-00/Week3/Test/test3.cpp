/* PROBLEM: Implement <cstring> strcat*/

#include <iostream>
using namespace std;

#define SIZE 13

const char  *ft_strcat(char *str1, const char *str2)
{
    char *s1 = str1;
    int i = 0;

    while (*s1)
        ++s1;
    while (*(str2 + i))
    {
        *s1 = *(str2 + i);
        i++;
        ++s1;
    }
    *s1 = '\0';
    return (str1);
}

int main()
{
    static char str1[SIZE] = "Hello ";
    char str2[] = "world!";

    cout << ft_strcat(str1, str2) << endl;
}
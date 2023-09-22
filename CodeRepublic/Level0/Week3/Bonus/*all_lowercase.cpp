/* PROBLEM: Given an input string consisting
of letters, create a function that converts
all the letters to lowercase without using
any condition. */

#include <iostream>
using namespace std;

void    all_lowercase(char *str)
{
    int i = -1;

    while (str[++i])
        str[i] |= 32;
    // &= (uppercase) ^= (case-switch)
}

int main()
{
    char    str[] = {'H', 'e', 'L', 'l', 'O'};
    all_lowercase(str);

    for (int i = 0; str[i]; i++)
        cout << str[i] << " ";
    cout << endl;
}
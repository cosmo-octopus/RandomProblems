/* PROBLEM: Print the longest word in the
given text. */

#include <iostream>
using namespace std;

void    ft_longest(char *str)
{
    int i = 0, idx = 0, idxMax = 0;
    int temp1 = 0, temp2 = 0;

    while (str[i] && str[i] == ' ')
            i++;
    while (str[i] && str[i] != ' ')
    {
        i++;
        temp1++;
    }
    temp2 = temp1;
    temp1 = 0;
    while (str[i])
    {
        while (str[i] && str[i] == ' ')
            i++;
        idx = i;
        while (str[i] && str[i] != ' ')
        {
            i++;
            temp1++;
        }
        if (temp1 > temp2)
        {
            idxMax = idx;
            temp2 = temp1;
        }
        temp1 = 0;
    }
    while (str[idxMax] && str[idxMax] != ' ')
        cout << str[idxMax++];
}

int main()
{
    char    str[] = "   Hello     you, traveler!";

    cout << "The longest word in the text is: ";
    ft_longest(str);
    cout << endl;
}
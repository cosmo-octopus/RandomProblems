/* PROBLEM: Remove the duplicate characters from a given string. */

#include <iostream>

int main()
{
    char    str[] = {'H', 'e', 'l', 'l', 'l', 'o', 'o', 'e'};
    char    *res;
    int i = 0, j = 1, idx = 1;

    res[0] = str[0];
    while (str[j])
    {
        while (str[j] && i < j)
        {
            if (str[i] == str[j])
            {
                i = 0;
                j++;
                break;
            }
            i++;
        }
        if (i != 0)
        {
            res[idx++] = str[j];
            i = 0;
            j++;
        }
    }
    res[idx] = '\0';
    for (int i = 0; res[i]; i++)
        std::cout << res[i];
    std::cout << "\n";
}

/* PROBLEM: Create a function that takes two
4x4 two-dimensional character arrays and a
character c as input. Replace all occurrences
of c with spaces (' ') in the first array and
store the modified result in the second one. */

#include <iostream>
using namespace std;

void ft_change(char array[][4], char my_array[][4], char c)
{
    for (int i = 0; i < 4; i++)
    {
        char* src = array[i];
        char* dest = my_array[i];

        while (*src)
        {
            if (*src == c)
                *dest = ' ';
            else
                *dest = *src;

            src++;
            dest++;
        }
    }
}

int main()
{
    char    array[4][4] = {"he;", "t;e", "j;e", ";rf"};
    char    my_array[4][4];

    ft_change(array, my_array, ';');

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << my_array[i][j] << " ";
        }
        cout << endl;
    }
}
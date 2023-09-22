/* PROBLEM: Implement a function that takes
an array of integers and a boolean function pointer
and applies that function to the elements of the
given array to print even numbers.*/

#include <iostream>
using namespace std;

void    print_even(bool(*ptr)(int), int *arr, int len)
{
    int i = -1;

    while (++i < len)
    {
        if (ptr(arr[i]))
            cout << arr[i] << " ";
    }
    cout << endl;
}

bool    is_even(int a)
{
    if (a % 2 == 0)
        return (1);
    return (0);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int len = sizeof(arr) / sizeof(arr[0]);

    bool(*ptr)(int) = is_even;
    print_even(ptr, arr, len);
}
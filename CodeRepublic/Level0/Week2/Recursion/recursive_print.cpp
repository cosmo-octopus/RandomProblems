/* PROBLEM: Write a recursive function
that takes an array of integers and prints
the elements of the array to the screen.*/

#include <iostream>
#include <climits>
using namespace std;

int recursive_print(int *arr, int *i, int len)
{
    if (*i < len)
    {
        cout << arr[*i] << " ";
        (*i)++;
        recursive_print(arr, i, len);
    }
    return (0);
}

int main()
{
    int arr[] = {1, 14, 567, -1, 0, INT_MAX};
    int len = sizeof(arr) / sizeof(arr[0]);
    int i;
    recursive_print(arr, &i, len);
    cout << endl;
}
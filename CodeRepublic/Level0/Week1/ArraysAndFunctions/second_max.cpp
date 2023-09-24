/* PROBLEM: Write a function that takes
an array of integers and returns the second
maximum value. */

#include <iostream>
using namespace std;

int second_max(int *arr, int len)
{
    int i = -1;
    int max = arr[0], second_max = arr[0];

    while (++i < len)
    {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] > second_max && arr[i] < max)
            second_max = arr[i];
    }
    return (second_max);
}

int main()
{
    int arr[] = {66, 13, 5, 78, 65, 43, 55, 64};
    int len = sizeof(arr) / sizeof(arr[0]);

    cout << "Second maximum value is: " << second_max(arr, len) << endl;
}
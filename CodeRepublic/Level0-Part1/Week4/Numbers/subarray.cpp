/* PROBLEM: Write a program that searches for
a sub-array within an array of integers, such
that the sum of the elements in the sub-array
is equal to a given target value. */

#include <iostream>
using namespace std;

#define SIZE 15

int ft_subarray(int *arr, int target)
{
    int i = -1;
    int start = 0;
    int res = 0;
    int counter = 0;

    while (++i < SIZE && res <= target)
    {
        res += arr[i];
        counter++;
        if (res == target)
            return (counter);
        else if (res > target)
        {
            i = ++start;
            res = 0;
            counter = 0;
        }
    }
    return (-1);
}

int main()
{
    int arr[SIZE] = {54, 4, 5, 6, 7, 8, 9, 2, 3, 33, 24, 16, 15, 20, 11};
    int target = 55;

    cout << "New sub-array consists of " << ft_subarray(arr, target) << " enelemnts\n";
}
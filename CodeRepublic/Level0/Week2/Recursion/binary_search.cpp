/* PROBLEM: Implement binary search
algorithm recursively */

#include <iostream>
#include <climits>
using namespace std;

int binary_search(int arr[], int target, int start, int end)
{
    int mid = (start + end) / 2;
    if (start <= end)
    {
        if (arr[mid] == target)
            return (mid);
        else if (arr[mid] < target)
            start = mid + 1;
        else
            end = mid - 1;
        return (binary_search(arr, target, start, end));
    }
    return (-1);
}

int main()
{
    int arr[] = {1, 34, 56, 78, INT_MAX};
    int end = (sizeof(arr) / sizeof(arr[0])) - 1;
    cout << binary_search(arr, 34, 0, end) << endl;
}
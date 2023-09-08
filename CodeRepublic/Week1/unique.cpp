/* PROBLEM: Given a sorted array in which all elements appear 
 * twice (one after one) and one element appears only once.
 * Find that element in O(log n) complexity. */

#include <iostream>
using namespace std;

int search(int *arr, int len)
{
    // a Binary Search based method, to find the number
    //that only appears once
    int start = 0, end = len - 1;
    int mid = 0;

    // edge cases
    if (len == 1)
        return (arr[0]);
    if (arr[start] != arr[start + 1])
        return (arr[start]);
    if (arr[end] != arr[end - 1])
        return (arr[end]);

    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (arr[mid] != arr[mid - 1]
            && arr[mid] != arr[mid + 1])
            return (arr[mid]);
        else if ((arr[mid] == arr[mid + 1] && mid % 2 == 0) 
            || arr[mid] == arr[mid - 1] && mid % 2 != 0)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return (-1);
}

int	main()
{
    int arr[] = {1, 1, 3, 5, 5, 6, 6, 8, 8, 9, 9};
    int len = sizeof(arr) / sizeof(arr[0]);
    int element = search(arr, len);

    if (element != -1)
        cout << "The required element is: " << element << endl;
    else
        cout << "There is no such element!" << endl;
}

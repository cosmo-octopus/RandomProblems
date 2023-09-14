#include <iostream>
#include <cstdlib>
using namespace std;

#define SIZE 7

void    swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void    shift_arr(int *arr, int shift)
{
    int i = 0, idx = SIZE - shift;

    while (idx < SIZE)
        swap(&arr[i++], &arr[idx++]);
    while (i + 1 < SIZE)
    {
        swap(&arr[i], &arr[i + 1]);
        i++;
    }
}

int main()
{
    int arr[SIZE];
    int shift = 0;
    int *res;
    int k = 1;

    cout << "How many times you want to shift?: ";
    cin >> shift;

    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = k++;
        cout << arr[i] << " ";
    }
    cout << endl;
    shift_arr(arr, shift);
    for (int i = 0; i < SIZE; i++)
        cout << arr[i] << " ";
    cout << endl;
}
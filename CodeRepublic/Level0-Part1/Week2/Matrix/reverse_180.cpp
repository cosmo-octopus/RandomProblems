/* PROBLEM: Implement a function
that accepts a matrix as its input
and does a 180-degree rotation on it.
For example: 
    1   2   3   4
    5   6   7   8
    9   10  11  12
    13  14  15  16
    Output:
    16  15  14  13
    12  11  10  9
    8   7   6   5
    4   3   2   1
*/

#include <iostream>
#include <cstdlib>
using namespace std;

#define SIZE 3

void    swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void    swap_180(int arr[][SIZE])
{
    int i = -1, j = -1;
    int i1 = SIZE, j1 = SIZE;

    while (++i < --i1)
    {
        while (++j < SIZE)
        {
            swap(&arr[i][j], &arr[i1][--j1]);
        }
        j = -1;
        j1 = SIZE;
    }
    if (SIZE % 2 != 0)
    {
        j = 0;
        j1 = SIZE - 1;
        while (j < j1)
        {
            swap(&arr[i][j], &arr[i][j1]);
            j++;
            j1--;
        }
    }
}

void    fill_matrix(int arr[][SIZE])
{
    int i = -1, j = -1;

    srand(time(0));
    
    while (++i < SIZE)
    {
        while (++j < SIZE)
            arr[i][j] = 1 + (rand() % 9);
        j = -1;
    }
}

int main()
{
    int arr[SIZE][SIZE];
    int sum = 0;

    fill_matrix(arr);

    cout << "MATRIX:\n";
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    swap_180(arr);
    cout <<"\nFinal result:" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    
}
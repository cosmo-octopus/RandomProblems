/* PROBLEM: Implement a function
that takes a matrix as input and
swaps its rows and columns. */

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

void    row_col_swap(int arr[][SIZE])
{
    int res[SIZE][SIZE];
    int i = -1, j = -1;

    while (++i < SIZE)
    {
        while (++j < SIZE)
        {
            if (i > j)
                swap(&arr[i][j], &arr[j][i]);
        }
        j = -1;
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
    row_col_swap(arr);
    cout <<"\nFinal result:" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

/* PROBLEM: Implement a function that
will swap the values of the elements
located on the primary diagonal and the
secondary diagonal of a square matrix. */

#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

#define SIZE 5

void    swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void    diagonal_swap(int arr [][SIZE])
{
    int i = -1, j = SIZE;

    while (++i < SIZE)
    {
        while (--j < SIZE)
        {
            if (i + j == SIZE - 1)
            {
                swap(&arr[i][i], &arr[i][j]);
                j = SIZE;
                break ;
            }
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

    diagonal_swap(arr);
    cout << "\nSWAP:" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

/* PROBLEM: Implement a function that
calculates and returns the sum of the
elements of the primary diagonal and
the sum of the secondary diagonal of a
square matrix. */

#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

#define SIZE 5

int secondary_diagonal(int arr[][SIZE])
{
    int res = 0;
    int i = -1, j = SIZE;

    while (++i < SIZE)
    {
        while (--j >= 0)
        {
            if (i + j == SIZE - 1)
            {
                res += arr[i][j];
                j = SIZE;
                break ;
            }
        } 
    }
    return (res);
}

int primary_diagonal(int arr[][SIZE])
{
    int res = 0;
    int i = -1;
    while (++i < SIZE)
        res += arr[i][i];
    return (res);
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
    int primary = 0;
    int secondary = 0;

    fill_matrix(arr);

    cout << "MATRIX:\n";
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }

    primary = primary_diagonal(arr);
    secondary = secondary_diagonal(arr);
    cout << "Sums of primary and secondary diagonals are "
    << primary << " and " << secondary << " respectively." << endl;
}
/* PROBLEM: Implement a function that
calculates and returns the sum of the
elements located above the primary diagonal
of a square matrix, including the elements
of the primary diagonal itself.*/

#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

#define SIZE 5

int sum_above(int arr[][SIZE])
{
    int sum = 0;
    int i = -1, j = -1;

    while (++i < SIZE)
    {
        while (++j < SIZE && j <= i)
        {
            sum += arr[i][j];
            if (j >= i)
            {
                j = -1;
                break ;
            }
        }
    }
    return (sum);
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
    int sum;

    fill_matrix(arr);

    cout << "MATRIX:\n";
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }

    sum = sum_above(arr);
    cout << "The sum of the elements located above the primary diagonal is: " 
    << sum << endl;
}
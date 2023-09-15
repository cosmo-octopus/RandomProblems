/* PROBLEM: Implement a function that
calculates and returns the sum of the
elements located above the secondary diagonal
of a square matrix, including the elements
of the secondary diagonal itself.*/

#include <iostream>
#include <cstdlib>
using namespace std;

#define SIZE 5

int above_sec_diagonal(int arr[][SIZE])
{
    int res = 0;
    int i = -1, j = SIZE;

    while (++i < SIZE)
    {
        while (--j >= 0 && i + j <= SIZE - 1)
            res += arr[i][j];
        j = SIZE;
    }
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
    int sum = 0;

    fill_matrix(arr);

    cout << "MATRIX:\n";
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }

    sum = above_sec_diagonal(arr);
    cout << "The sum of the elements located above the secondary diagonal is: " 
    << sum << endl;
}
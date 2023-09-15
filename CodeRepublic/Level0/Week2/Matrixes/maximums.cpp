/* PROBLEM: Implement a function
that takes a matrix as input and
generates a static array containing
the maximum value from each row. */

#include <iostream>
#include <cstdlib>
using namespace std;

#define ROWS 4
#define COLS 6

int *maximums(int arr[][COLS])
{
    static int  res[ROWS];
    int i = -1, j = -1;
    int max = 0;

    while (++i < ROWS)
    {
        max = arr[i][0];
        while (++j < COLS)
        {
            if (arr[i][j] > max)
                max = arr[i][j];
        }
        res[i] = max;
        j = -1;
    }
    return (res);
}

void    fill_matrix(int arr[][COLS])
{
    int i = -1, j = -1;
    
    while (++i < ROWS)
    {
        while (++j < COLS)
            arr[i][j] = 1 + (rand() % 15);
        j = -1;
    }
}

int main()
{
    int arr[ROWS][COLS];
    int sum = 0;
    int *res;

    srand(time(0));

    fill_matrix(arr);
    cout << "MATRIX:\n";
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    
    res = maximums(arr);
    for (int i = 0; i < ROWS; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
}
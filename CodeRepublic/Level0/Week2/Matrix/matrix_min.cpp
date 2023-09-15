/* PROBLEM: Write a program that will find
the indices of the smallest value
in an NxM (N rows and M columns)
sized matrix and print them to the
screen */

#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

#define ROWS 3
#define COLS 5

int *min_idx(int arr[][COLS])
{
    int i = -1, j = -1;
    int min = arr[0][0];
    static int res[2];

    while (++i < ROWS)
    {
        while (++j < COLS)
        {
            if (arr[i][j] < min)
            {
                res[0] = i;
                res[1] = j;
                min = arr[i][j];
            }
        }
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
    res = min_idx(arr);

    cout << *res << " and " << *(res + 1) << endl;
}
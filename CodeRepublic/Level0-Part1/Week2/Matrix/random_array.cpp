/* PROBLEM: Generate a Matrix of
Random Numbers */

#include <iostream>
#include <cstdlib>
using namespace std;


int main()
{
    srand(time(0)); // to generate pseudo random numbers each time

    int rows = 1 + (rand() % 10); // lie b/w 1 to 10
    int cols = 1 + (rand() % 10); // lie b/w 1 to 10
    int arr[rows][cols];

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            arr[i][j] = 1 + (rand() % 500); // lie b/w 1 to 500

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}
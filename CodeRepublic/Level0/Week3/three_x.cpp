/* PROBLEM: Display all occurrences
of the variable 'x' using a single
'cout' statement. */

#include <iostream>
using namespace std;

int x = 10;

int main()
{
    int x = 20;
    {
        int x = 5;
        int *a = &x;
        cout << *a << " " << *(a + 1) << " " << ::x << endl;
    }
}
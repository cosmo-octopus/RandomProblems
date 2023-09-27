/* PROBLEM: Implement a recursive
function that takes a fibonacci number
index as an input and prints the fibonacci
number to the screen */

#include <iostream>
using namespace std;

int fibonacci(int x)
{
    if (x <= 0)
        return (0);
    else if (x == 1)
        return (1);
    return (fibonacci(x - 1) + fibonacci(x - 2));
}

int main()
{
    int x;

    cout << "Index for a fibonacci number: ";
    cin >> x;
    cout << fibonacci(x) << endl;
}
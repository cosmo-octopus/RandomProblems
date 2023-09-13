/* PROBLEM: Implement a recursive function
that takes a number as an input
and prints the factorial of that number
on the screen */

#include <iostream>
using namespace std;

int factorial(int x)
{
    if (x <= 1)
        return (1);
    return (x * factorial(x - 1));
}

int main()
{
    int x = 0;
    cout << "Enter a number: ";
    cin >> x;
    cout << "Factorial of the number " << x <<
    " is: " << factorial(x) << endl;
}
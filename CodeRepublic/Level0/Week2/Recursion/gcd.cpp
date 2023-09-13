/* PROBLEM: Implement a recursive
function that calculates the greatest
common divisor (GCD) of two numbers. */

#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (a == 0 || b == 0)
        return (0);
    else if (a == b)
        return (a);
    else if (a > b)
        return (gcd(a - b, b));
    else
        return (gcd(a, b - a));
}

int main()
{
    int num1 = 0, num2 = 0;

    cout << "Enter two positive numbers: ";
    cin >> num1 >> num2;
    if (num1 < 0 || num2 < 0)
    {
        cout << "Wrong input!" << endl;
        exit(1);
    }
    cout << "The greatest common divisor of this two numbers is: "
    << gcd(num1, num2) << endl;
}
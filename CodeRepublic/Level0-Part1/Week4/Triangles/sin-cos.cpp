/* PROBLEM: Write a program that determines whether
a given set of three integer values forms a Pythagorean triple.
If so, the program should calculate and display the values of sin
and cos of an angle 'x' in a right triangle with sides 'a', 'b', and 'c'.
If it is not a Pythagorean triple, the program should output a message indicating so.*/

#include <iostream>
using namespace std;

double  ft_cos(double b, double c)
{
    return (b / c);
}

double  ft_sin(double a, double c)
{
    return (a / c);
}

bool    check_the_triangle(int a, int b, int c)
{
    if (a * a + b * b == c * c)
        return (0);
    return (1);
}

int main()
{
    int a = 0, b = 0, c = 0;

    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    cout << "Enter c: ";
    cin >> c;

    if (!check_the_triangle(a, b, c))
        cout << "sin x = " << ft_sin(a, c) << endl
        << "cos x = " << ft_cos(b, c) << endl;
    else
        cout << "Not a Pythagorean triple\n";
}

/* PROBLEM: Write a program that calculates
the result of a summation series based on
user-provided values of 'n' and 'x.'
The program should compute the sum of a series
defined by the following formula:
Σ (-1)^j * (x^(j+1)) / (3j! + 2^(j+1)) */

#include <iostream>
using namespace std;

int ft_exp(int num, int exp)
{
    int res = num;

    while (exp > 1)
    {
        res *= num;
        exp--;
    }
    return (res);
}

int   ft_factorial(int num)
{
    int res = num;

    while (--num > 1)
        res *= num;
    return (res);
}

double   ft_summation(int n, int x)
{
    double   res = 0;
    
    double a = 0, b = 0, c = 0;
    int sign = 0;
    for (int j = 1; j <= n; j++)
    {
        a = ft_exp(x, j + 1);
        b = ft_factorial(3 * j);
        c = ft_exp(2, j + 1);

        sign = ft_exp(-1, j);

        res += sign * ( a / (b + c));
    }
    return (res);
}

int main()
{
    int n = 0, x = 0;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter x: ";
    cin >> x;

    cout << "result: " << ft_summation(n, x) << endl;
}
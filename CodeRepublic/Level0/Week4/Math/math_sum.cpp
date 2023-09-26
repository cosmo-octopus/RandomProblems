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

double   math_sum(int n, int x)
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

    cout << "result: " << math_sum(n, x) << endl;
}
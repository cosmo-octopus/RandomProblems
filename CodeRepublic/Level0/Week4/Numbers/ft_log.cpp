/* PROBLEM: Create a C++ program that calculates the
integer logarithm of a given number 'num' with a specified
base 'base.' The program should determine the largest integer
'x' such that 'base^x' is less than or equal to 'num'. */

#include <iostream>
using namespace std;

unsigned long   ft_exp(int num, int exp)
{
    unsigned long   res = num;

    if (exp == 0)
        return (1);
    while (exp > 1)
    {
        res *= num;
        exp--;
    }
    return (res);
}

//          base ^ x == num
int ft_log(int num, int base)
{
    unsigned long   res = 0;
    int             x = 0;

    res = ft_exp(base, x);
    while (1)
    {
        res = ft_exp(base, x);

        if (res == num)
            return (x);
        if (res > num)
            return (x - 1);
        x++;
    }
}

int main()
{
    int num = 0, base = 0;

    cout << "Enter the number: ";
    cin >> num;
    cout << "Enter the base: ";
    cin >> base;
    if (num < 0 || base <= 0)
        cout << "Wrong input\n";
    else
        cout << "Result: " << ft_log(num, base) << endl;
}
/* PROBLEM: Write a program that determines whether
a given integer 'num' is an Armstrong number.
An Armstrong number (also known as a narcissistic number)
is a number that is equal to the sum of its own digits,
each raised to the power of the number of digits in the number itself.
The program should check if 'num' is an Armstrong number and output "YES"
if it is, or "NO" if it is not. */

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

int digit_counter(int num)
{
    int digit;

    while (num)
    {
        digit++;
        num /= 10;
    }
    return (digit);
}

bool    is_armstrong_num(int num)
{
    int tmp = num;
    int digit = digit_counter(num);
    int res;

    while (tmp)
    {
        res += ft_exp(tmp % 10, digit);
        tmp /= 10;
    }
    if (res == num)
        return (0);
    return (1);
}

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (!is_armstrong_num(num))
        cout << "YES\n";
    else
        cout << "NO\n";
}
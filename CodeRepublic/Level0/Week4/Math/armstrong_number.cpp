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
    int digit = 0;

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
    int res = 0;

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
    int num = 0;
    cout << "Enter a number: ";
    cin >> num;

    if (!is_armstrong_num(num))
        cout << "YES\n";
    else
        cout << "NO\n";
}
/*PROBLEM: Given a decimal number as input, write
a program to convert the given decimal number into
equivalent hexadecimal number. i.e convert the number
with base value 10 to base value 16.*/

#include <iostream>
using namespace std;

void    reverse(char *str, int len)
{
    int     start = 0, end = len - 1;
    char    temp = 0;
    while (start < end)
    {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

char    *ft_hex(int num)
{
    char    *res;
    int     rmndr = 0;

    int     i = 0;
    while (num)
    {
        rmndr = num % 16;
        if (rmndr < 10)
            res[i] = '0' + rmndr;
        else
            res[i] = 'A' + (rmndr - 10);
        num = num / 16;
        i++;
    }
    res[i] = '\0';
    reverse(res, i);
    return (res);
}

int main()
{
    int num;

    cout << "Enter a decimal number: ";
    cin >> num;
    cout << "Hexadecimal for " << num << " is: " << ft_hex(num) << endl;
}

/*PROBLEM: Given a decimal number as input,
write a program to convert the given decimal
number into an equivalent binary number.*/

#include <iostream>
using namespace std;

void    ft_reverse(char *str, int i)
{
    int     start = 0, end = i - 1;
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

char    *ft_binary(int num)
{
    char    *res;
    int     i = 0;

    while (num)
    {
        res[i++] = (num % 2) + '0';
        num = num / 2;
    }
    res[i] = '\0';
    ft_reverse(res, i);
    return (res);
}

int main()
{
    int num = 0;

    cout << "Enter a number: ";
    cin >> num;
    cout << "Binary representation of decimal number " <<
    num << " is: " << ft_binary(num) << endl;  
}
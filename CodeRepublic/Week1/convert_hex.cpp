#include <iostream>
using namespace std;

void    reverse(char *str, int len)
{
    int start = 0, end = len - 1;

    while (start < end)
    {
        char tmp = str[start];
        str[start] = str[end];
        str[end] = tmp;
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
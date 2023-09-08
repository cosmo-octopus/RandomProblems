/* PROBLEM: Write a function that takes a number (int)
as input, sums its reverse until a palindrome value is
obtained, and returns the number of steps required to
reach that value.*/

#include <iostream>
using namespace std;

bool    is_palindrome(int num);
int     ft_reverse(int num);

bool    is_palindrome(int num)
{
    if (num == ft_reverse(num))
        return (1);
    return (0);
}

int ft_reverse(int num)
{
    int reverse = 0;

    while (num)
    {
        reverse = (reverse * 10) + (num % 10);
        num = num / 10;
    }
    return (reverse);
}

int main()
{
    int num = 0, steps = 0;

    cout << "Enter a number: ";
    cin >> num;
    while (!is_palindrome(num))
    {
        num += ft_reverse(num);
        steps++;
    }
    cout << "Palindrome number is " << 
    num << ". It took " << steps
    << " step(s) to find it." << endl;
}
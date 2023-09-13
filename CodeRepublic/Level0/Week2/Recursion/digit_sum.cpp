/* PROBLEM: Implement a recursive
function that takes a number and
returns the sum of its digits. */

#include <iostream>
using namespace std;

int digit_sum(int num, int *res)
{
    if (num)
    {
        *res += num % 10;
        digit_sum(num / 10, res);
    }
    return (*res);
}

int main()
{
    int num = 0, res = 0;
    cout << "Enter a number: ";
    cin >> num;
    cout << "The sum of the digits of the " <<
    num << " is: " << digit_sum(num, &res) << endl;
}